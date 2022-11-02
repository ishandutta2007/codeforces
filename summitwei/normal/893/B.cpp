#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int N;
    cin >> N;

    vector<int> nums;
    int i = 1;
    int number = 1;
    while(number <= N){
        nums.push_back(number);
        i++;
        number = (pow(2, i)-1)*(pow(2, i-1));
    }

    for(int i=0; i<nums.size(); i++){
        int maybe = nums[nums.size()-1-i];
        if(N % maybe == 0){
            cout << maybe;
            return 0;
        }
    }
    return 0;
}