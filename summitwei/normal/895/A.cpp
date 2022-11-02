#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int N;
    cin >> N;
    vector<int> slices(N);
    for(int i=0; i<N; i++){
        cin >> slices[i];
    }

    vector<int> sums(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<i+1; j++){
            sums[i] += slices[j];
        }
    }

    int minDist = 180;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int thisSum = sums[i]-sums[j];
            int near180 = abs(180-thisSum);
            minDist = min(near180, minDist);
        }
    }

    cout << 2*minDist;
    return 0;
}