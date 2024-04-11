#include <bits/stdc++.h>
using namespace std;

vector<int> res;
int dp[12000000];

int getD(int x){
    return dp[x] = x % 10 + dp[x / 10];
}

int main() {
    int k;
    cin >> k;
    for(int i = 0; i < 12000000; i++){
        if(getD(i) == 10){
            k--;
            if(k == 0) return !printf("%d", i);
        };
    }
}