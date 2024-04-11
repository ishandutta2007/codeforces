#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define what_is(x) cerr << #x << " is " << x << endl;
const int mod = 998244353;

int n, m;
vl bs, todo;

int cnt[(1 << 16) + 1];
ll inv2 = (mod + 1) / 2;

int popcount(ll x) {
    return __builtin_popcountll(x);
}

ll getp(ll x) {
    return 63 - __builtin_clzll(x);
}

bool add(ll x) {
    for(int i = m - 1; i >= 0; i--) {
        if(!bs[i]) continue;
        if(x >> i & 1) x ^= bs[i];
    }
    if(!x) return false;
    bs[getp(x)] = x;
    return true;
}

void build() {
    rep(i, 0, m) {
        for(int j = i - 1; j >= 0; j--) {
            if(bs[i] >> j & 1) bs[i] ^= bs[j];
        }
    }
    vl new_bs;
    for(int i = 0; i < m; i++) {
        if(bs[i]) continue;
        ll val = 0;
        val |= (1LL << i);
        for(int j = 0; j < m; j++) val |= (bs[j] >> i & 1) << j;
        new_bs.push_back(val);
    }
    todo = new_bs;
}

ll pk = 1;
ll res[55], fres[55];
ll C[55][55], f[55][55];
void dfs(int d, ll cur) {
    if(d == sz(todo)) {
        res[popcount(cur)]++;
        return ;
    }
    dfs(d + 1, cur);
    if(todo[d]) dfs(d + 1, cur ^ todo[d]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i < (1 << 16); i++) {
        cnt[i] = cnt[i / 2] + i % 2;
    }

    cin >> n >> m;
    bs.resize(m, 0);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        if(!add(x)) pk *= 2, pk %= mod;
    }

    trav(x, bs) if(x) todo.push_back(x);
    if(sz(todo) <= 26) {
        dfs(0, 0);
        for(int i = 0; i <= m; i++) cout << (pk * res[i] % mod + mod) % mod << " ";
        cout << "\n";
    }
    else {
        for(int i = 0; i < 55; i++) C[i][i] = C[i][0] = 1;
        for(int i = 0; i < 55; i++) {
            for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
//        int k = sz(bs);
        build();
//        for(int i = 0; i < sz(bs); i++) cout << bitset<36>(bs[i]) << endl;

        dfs(0, 0);
        for(int b = 0; b <= m; b++) {
            for(int c = 0; c <= m; c++) {
                for(int a = 0; a <= b && a <= c; a++) {
                    int s = (a % 2 == 0 ? 1 : -1);
                    f[b][c] = (f[b][c] + s * C[b][a] * C[m - b][c - a]) % mod;
                }
                fres[c] += (f[b][c] * res[b]);
                fres[c] %= mod;
            }
        }
        for(int i = 0; i < sz(todo); i++) pk = (pk * inv2) % mod;
        for(int i = 0; i <= m; i++) cout << (pk * fres[i] % mod + mod) % mod << " ";
        cout << "\n";
    }
}