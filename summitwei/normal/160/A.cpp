#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> numbers;
    numbers.resize(N);
    for(int i=0; i<N; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    reverse(numbers.begin(), numbers.end());

    int totalSum = 0;
    for(int j=0; j<N; j++){
        totalSum += numbers[j];
    }

    int toGet = ceil((totalSum+1)/2.0);
    int tempSum = 0;
    for(int k=0; k<N; k++){
        tempSum += numbers[k];
        if(tempSum >= toGet){
            cout << k+1;
            return 0;
        }
    }
    return 0;
}