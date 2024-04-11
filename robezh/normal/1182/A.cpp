#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 61;

ll dp[N];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i >= 2) dp[i] += dp[i-2] * 2;
    }
    cout << dp[n] << endl;

}