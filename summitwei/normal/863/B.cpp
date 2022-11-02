#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> weights;
    weights.resize(2*N);
    for(int kek = 0; kek < 2*N; kek++){
        cin >> weights[kek];
    }

    sort(weights.begin(), weights.end());
    int minweight = weights[2*N-1]*weights[2*N-1];

    vector<int> storageWeights = weights;
    for(int a=0; a<(2*N-1); a++){
        for(int b=(a+1); b<2*N; b++){
            weights.erase(weights.begin()+b);
            weights.erase(weights.begin()+a);
            int weightSum = 0;
            for(int i=0; i<2*N-3; i+=2){
                weightSum += (weights[i+1]-weights[i]);
            }

            if(weightSum < minweight){
                minweight = weightSum;
            }
            weights = storageWeights;
        }
    }

    cout << minweight;
    return 0;
}