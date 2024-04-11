#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2005;
const ll INF = (ll)1e18;

int a, n, m;
int rain[N];
ll wei[N];
int um[N];
ll dp[N][N];

int main() {
    memset(um, -1, sizeof(um));
    cin >> a >> n >> m;
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r; r--;
        for(int j = l; j <= r; j++) rain[j] = 1;
    }
    for(int i = 1; i <= m; i++) {
        int loc;
        cin >> loc >> wei[i];
        if(um[loc] == -1 || wei[um[loc]] > wei[i]) um[loc] = i;
    }
    for(int i = 0; i < N; i++) fill(dp[i], dp[i] + N, INF);
    dp[0][0] = 0;
    if(um[0] != -1) dp[0][um[0]] = 0;
    for(int i = 1; i <= a; i++) {
        ll mn = INF;
        for(int j = 0; j <= m; j++) {
            if(!rain[i-1] || j != 0) {
                if(dp[i-1][j] != INF) {
                    dp[i][j] = dp[i-1][j] + wei[j];
                    mn = min(mn, dp[i][j]);
                }
            }
        }
//        cout << i << ", " << mn << endl;
        if(i == a) return cout << (mn == INF ? -1 : mn) << endl, 0;
        if(um[i] != -1) dp[i][um[i]] = mn;
        dp[i][0] = mn;
    }
    cout << "-1" << endl;

}