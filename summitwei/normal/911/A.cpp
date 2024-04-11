#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> numbers(N);
    int minNumber = 1000000000;
    vector<int> minNumbers;
    for(int i=0; i<N; i++){
        cin >> numbers[i];
        if(numbers[i] < minNumber){
            minNumber = numbers[i];
            minNumbers.clear();
            minNumbers.push_back(i);
        } else if(numbers[i] == minNumber){
            minNumbers.push_back(i);
        }
    }

    int minDiff = 1000000000;
    for(int i=0; i<minNumbers.size()-1; i++){
        if(minNumbers[i+1] - minNumbers[i] < minDiff){
            minDiff = minNumbers[i+1] - minNumbers[i];
        }
    }

    cout << minDiff;
    return 0;
}