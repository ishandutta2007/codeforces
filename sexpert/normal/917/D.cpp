#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 105;
vector<int> adj[MAXN];
int sz[MAXN], n;
ll tdp[MAXN][MAXN][MAXN], dp[MAXN][MAXN][MAXN], binom[MAXN][MAXN], uwu[MAXN]; // vertex, size, tree edges

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

void dfs(int s, int p = 0) {
    for(auto v : adj[s])
        if(v != p)
            dfs(v, s);
    sz[s] = 1;
    dp[s][1][0] = 1;
    for(auto v : adj[s]) {
        if(v == p)
            continue;

        for(int i = 0; i < MAXN; i++)
            for(int j = 0; j < MAXN; j++)
                tdp[s][i][j] = 0;

        for(int ssz = 1; ssz <= sz[s]; ssz++) {
            for(int se = 0; se <= n - 1; se++) {
                for(int vsz = 1; vsz <= sz[v]; vsz++) {
                    for(int ve = 0; ve <= n - 1 && se + ve <= n - 1; ve++) {
                        ll t = (dp[s][ssz][se] * dp[v][vsz][ve]) % MOD;
                        tdp[s][ssz][se + ve] = (tdp[s][ssz][se + ve] + vsz * t) % MOD;
                        tdp[s][ssz + vsz][se + ve + 1] = (tdp[s][ssz + vsz][se + ve + 1] + t) % MOD;
                    }
                }
            }
        }
        for(int i = 0; i < MAXN; i++)
            for(int j = 0; j < MAXN; j++)
                dp[s][i][j] = tdp[s][i][j];

        sz[s] += sz[v];
    }
}

int main() {
    for(int i = 0; i < MAXN; i++)
        binom[i][0] = 1;
    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for(int k = 0; k <= n - 1; k++) {
        ll yay = 0;
        for(int s = 1; s <= n; s++) {
            yay = (yay + dp[1][s][k] * s) % MOD;
            //cout << dp[1][s][k] << " ";
        }
        if(k < n - 1)
            uwu[k] = (yay * mpow(n, n - k - 2)) % MOD;
        else
            uwu[k] = 1;
        //cout << endl;
    }
    //for(int k = 0; k <= n - 1; k++)
    //    cout << uwu[k] << " ";
    //cout << endl;
    for(int k = n - 2; k >= 0; k--) {
        for(int j = k + 1; j <= n - 1; j++) {
            uwu[k] = (uwu[k] - binom[j][k] * uwu[j]) % MOD;
        }
    }
    for(int k = 0; k <= n - 1; k++)
        cout << (uwu[k] + MOD) % MOD << " ";
    cout << endl;
}