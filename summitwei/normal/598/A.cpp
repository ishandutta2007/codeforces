#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector <long long> inputs;
    inputs.resize(N);
    for(int a=0; a<N; a++){
        cin >> inputs[a];
    }
    for(long long i=0; i<N; i++){
        long long maxNum = inputs[i];

        long long sum = 0;

        /*for(long long j = 1; j<maxNum+1; j++){
            if(floor(log(j) / log(2))==(log(j) / log(2))){
                sum -= j;
            } else{
                sum += j;
            }
        }*/

        sum += maxNum*(maxNum+1)/2;

        long long largestPower = floor(log(maxNum) / log(2));
        long long sumOfPowers = pow(2, largestPower+1);

        long long totalSubtracted = (sumOfPowers-1)*2;

        sum -= totalSubtracted;
        
        cout << sum << endl;
    }

    return 0;
}