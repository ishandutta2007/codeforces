#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> scores;
    scores.resize(N);
    for(int i=0; i<N; i++){
        cin >> scores[i];
    }

    int passedScores = 0;

    int passingScore = scores[K-1];
    for(int j=0; j<N; j++){
        if(scores[j]!=0 && scores[j]>=passingScore){
            passedScores++;
        }
    }

    cout << passedScores;
    return 0;
}