#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 500, mod = 998244353;
typedef long long ll;

int n;
vector<int> G[N];
ll dp[3][N];

void dfs(int v, int p){
    dp[0][v] = 1;
    dp[1][v] = 1;
    int m = 1, mxm = (p == -1 ? G[v].size() : G[v].size() - 1);
    vector<ll> pre(mxm+2, 0), suf(mxm+2, 0), mid(mxm+2, 0);

    for(int nxt : G[v]){
        if(nxt != p){
            dfs(nxt, v);
            pre[m] = suf[m] = (dp[0][nxt] + dp[2][nxt]) % mod;
            mid[m] = dp[1][nxt];
            dp[0][v] = (dp[0][v] * dp[0][nxt]) % mod;
            m++;
        }
    }

    pre[0] = 1;
    for(int i = 1; i < m; i++) pre[i] *= pre[i-1], pre[i] %= mod;
    suf[m] = 1;
    for(int i = m-1; i >= 1; i--) suf[i] *= suf[i+1], suf[i] %= mod;

    dp[2][v] = 0;
    for(int i = 1; i < m; i++) dp[2][v] += (mid[i] * pre[i-1] % mod * suf[i+1] % mod), dp[2][v] %= mod;
    dp[1][v] = suf[1];
    dp[0][v] += dp[2][v]; dp[0][v] %= mod;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    cout << dp[0][0] << endl;
}