#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 55;

int n;
ll k;
ll dp[N];
ll res[N];

int main() {
    cin >> n >> k;
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--) {
        dp[i] += dp[i+1];
        if(i < n-1) dp[i] += dp[i+2];
    }
    for(int i = 0; i < n;) {
        if (dp[i + 1] < k) {
            k -= dp[i+1];
            res[i] = i + 2, res[i + 1] = i + 1;
            i += 2;
        }
        else {
            res[i] = i + 1;
            i++;
        }
    }
    for(int i = 0; i < n; i++) cout << res[i] << " ";

}