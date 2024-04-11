#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50, B = 26, INF = (int)1e9;

int n, k;
int nxt[N][B];
int sz[N], id[N];
int dp[2][N];
int res[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(nxt, -1, sizeof(nxt));
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int p; char c;
        cin >> p >> c;
        nxt[p][c - 'a'] = i;
    }
    cin >> k;
    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        id[x] = i;
    }
    for(int i = n; i >= 0; i--) {
        sz[i] = (id[i] != 0);
        for(int b = 0; b < 26; b++) {
            if(nxt[i][b] != -1) sz[i] += sz[nxt[i][b]];
        }
    }
    for(int i = 0; i <= n; i++) dp[0][i] = dp[1][i] = INF;
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++) {
        dp[1][i] = min(dp[1][i], dp[0][i] + 1);
        if(id[i]) {
            dp[0][i] = min(dp[1][i], dp[0][i]);
            res[id[i]] = dp[0][i];
        }
        int sum = (id[i] != 0);
        for(int b = 0; b < 26; b++) {
            int nx = nxt[i][b];
            if(nx != -1) {
                dp[1][nx] = dp[1][i] + sum;
                dp[0][nx] = dp[0][i] + 1;
                sum += sz[nx];
            }
        }
    }
//    for(int i = 0; i <= n; i++) cout << i << " : " << dp[i[]]
    for(int i = 1; i <= k; i++) cout << res[i] << " ";
    cout << '\n';

}