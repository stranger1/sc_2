/*
 * Interface of class Network
 */
#pragma once

#include <vector>
#include <stdint.h>
#include "weightmatrix.h"
#include "neuron.h"

using std::vector;

//Feedforward autoassociative artificial neural network
class Network
{
public:
    Network();
    Network( unsigned iNeuronSize );
    Network( WeightMatrix& iW );

    vector<vector<double> > getWeightMatrix();

    void storePattern(Neuron &t );
    //calculate weight matrix W using Hebb rule
    void calculateWeightMatrix();
    Neuron recallPattern(Neuron &s );
private:
    const long unsigned neuronSize;

    vector< Neuron > y; //input/output units
    WeightMatrix W; //Weight matrix

    Neuron activateFunction(Neuron &iNeuron); //signum (for Hebb rule)
};
