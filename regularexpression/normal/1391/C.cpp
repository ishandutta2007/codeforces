#include<bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;

int add(int a, int b) {
    return a + b < p ? a + b : a + b - p;
}

int mul(int a, int b) {
    return (long long)a * b % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fact[i] = mul(fact[i - 1], i);
    vector<int> dp(n + 1, 0);
    for (int i = 3; i <= n; ++i) 
        dp[i] = add(mul(fact[i - 1], i - 2), mul(2, dp[i - 1]));
    cout << dp[n];
    return 0;
}