#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;

const ll mod = 998244353;
const int MAXN = 1e5 + 10;
vector<int> adj[MAXN];
int gdy[MAXN];
const int MSZ = 512;
int cnt[MSZ];

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

int matInv(vector<vector<ll>>& A) {
    int n = sz(A); vi col(n);
    vector<vector<ll>> tmp(n, vector<ll>(n));
    rep(i,0,n) tmp[i][i] = 1, col[i] = i;

    rep(i,0,n) {
        int r = i, c = i;
        rep(j,i,n) rep(k,i,n) if (A[j][k]) {
            r = j; c = k; goto found;
        }
        return i;
found:
        A[i].swap(A[r]); tmp[i].swap(tmp[r]);
        rep(j,0,n) swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
        swap(col[i], col[c]);
        ll v = modpow(A[i][i], mod - 2);
        rep(j,i+1,n) {
            ll f = A[j][i] * v % mod;
            A[j][i] = 0;
            rep(k,i+1,n) A[j][k] = (A[j][k] - f*A[i][k]) % mod;
            rep(k,0,n) tmp[j][k] = (tmp[j][k] - f*tmp[i][k]) % mod;
        }
        rep(j,i+1,n) A[i][j] = A[i][j] * v % mod;
        rep(j,0,n) tmp[i][j] = tmp[i][j] * v % mod;
        A[i][i] = 1;
    }

    for (int i = n-1; i > 0; --i) rep(j,0,i) {
        ll v = A[j][i];
        rep(k,0,n) tmp[j][k] = (tmp[j][k] - v*tmp[i][k]) % mod;
    }

    rep(i,0,n) rep(j,0,n)
        A[col[i]][col[j]] = tmp[i][j] % mod + (tmp[i][j] < 0 ? mod : 0);
    return n;
}

int mex(vector<int> &v) {
    if(v.empty())
        return 0;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < v.size(); i++)
        if(v[i] != i)
            return i;
    return v.size();
}

void dfs(int u) {
    vector<int> to;
    for(auto v : adj[u]) {
        if(gdy[v] == -1)
            dfs(v);
        to.push_back(gdy[v]);
    }
    gdy[u] = mex(to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ll inv_n = modpow(n, mod - 2), inv_n1 = modpow(n + 1, mod - 2);
    if(n == 1) {
        cout << "0\n";
        return 0;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    fill(gdy, gdy + MAXN, -1);
    for(int u = 1; u <= n; u++) {
        if(gdy[u] == -1)
            dfs(u);
    }

    for(int i = 1; i <= n; i++)
        cnt[gdy[i]]++;
    vector<vector<ll>> A(MSZ, vector<ll>(MSZ));
    for(int i = 0; i < MSZ; i++) {
        A[i][i] = 1;
        for(int j = 0; j < MSZ; j++) {
            A[i][j] = (A[i][j] - cnt[i^j] * inv_n1) % mod;
            A[i][j] = (A[i][j] + mod) % mod;
        }
    }
    matInv(A);
    ll tot = A[0][0];
    tot = (tot * inv_n1) % mod;
    cout << (mod + 1 - tot) % mod << '\n';
}