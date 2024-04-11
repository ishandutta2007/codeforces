#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, mod = (int)1e9 + 7, B = 60;
const ll inv2 = (int)5e8 + 4;

struct edge {
    int to;
    ll cost;
};

int n, m;
vector<edge> G[N];
vector<ll> ls;
ll res = 0;
ll val[N];
int cnt[2];
ll pw2[N];
bool vis[N];

struct Basis {
    int size;
    ll bas[B];
    bool bit[B];

    Basis(){
        size = 0;
        fill(bas, bas + B, 0);
        fill(bit, bit + B, false);
    }
    void add(ll x) {
        if(x == 0) return ;
        for(int i = 0; i < size; i++) {
            if((x ^ bas[i]) < x) x ^= bas[i];
            if(x == 0) return ;
        }
        bas[size++] = x;
        for(int i = 0; x > 0 && i < B; i++) {
            if(x % 2 == 1) bit[i] = true;
            x /= 2;
        }
        for(int i = size - 1; i >= 1; i--) if(bas[i-1] < bas[i]) swap(bas[i-1], bas[i]);
    }


};

int dfs(int v, int p, ll x, Basis &basis) {
    int res = 0;
    vis[v] = true;
    val[v] = x;
    ls.push_back(x);
    for(auto e : G[v]) {
        if(e.to == p) continue;
        if(vis[e.to]) basis.add(val[e.to] ^ val[v] ^ e.cost);
        else res += dfs(e.to, v, x ^ e.cost, basis);
    }
    return res + 1;
}

void solve(int v) {
    Basis basis;
    ls.clear();
    int numV = dfs(v, -1, 0, basis);
    for(int i = 0; i < B; i++) {
        if(basis.bit[i]) {
            res += pw2[i] * numV % mod * (numV - 1) % mod * pw2[basis.size - 1] % mod * inv2 % mod;
            res %= mod;
        }
        else {
            cnt[0] = cnt[1] = 0;
            for(ll x : ls) cnt[(x >> i) & 1]++;
            res += pw2[i] * cnt[0] % mod * cnt[1] % mod * pw2[basis.size] % mod;
            res %= mod;
        }
    }
}

void solve_all() {
    fill(vis, vis + n, false);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) solve(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pw2[0] = 1;
    for(int i = 1; i < B; i++) pw2[i] = pw2[i-1] * 2 % mod;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w; a--, b--;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    solve_all();
    cout << res << endl;


}