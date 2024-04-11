#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, k, p;
    cin >> n >> k >> p;
    vector<ll> a(n), b(k);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < k; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll inf = 10000000000;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, inf));
    dp[0].assign(k + 1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            dp[i + 1][j + 1] = min(dp[i + 1][j], max(dp[i][j], abs(a[i] - b[j]) + abs(b[j] - p)));
        }
    }
    cout << dp[n][k];
}