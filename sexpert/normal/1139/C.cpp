#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k <<= 1) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b)%MOD;
    }
    return res;
}

vector<int> adj[MAXN];
int sz[MAXN], comp[MAXN];

void dfs(int s, int c, int p = 0) {
    sz[c]++;
    comp[s] = c;
    for(auto v : adj[s])
        if(v != p) dfs(v, c, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 0) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    int cc = 1;
    for(int i = 1; i <= n; i++) {
        if(!comp[i]) dfs(i, cc);
        cc++;
    }
    ll ans = mpow(n, k);
    for(int i = 1; i < cc; i++)
        ans = (ans - mpow(sz[i], k)) % MOD;
    if(ans < 0) ans += MOD;
    cout << ans << endl;
}