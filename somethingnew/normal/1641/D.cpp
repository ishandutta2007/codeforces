#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

constexpr int N = 1e5 + 5;
constexpr int M = 5;
constexpr int T = 1000;
#pragma GCC target ("avx2")
#pragma GCC optimize("179")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("popcnt")
int a[N][M];
int elem[N * M];
vi idx[N * M];
unique_ptr<bitset<N>> good[N * M];
bitset<N> state;
int w[N];
int ord[N];
int conv[N];

int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    int sz = 0;
    rep(i, n) {
        rep(j, m) cin >> a[i][j], elem[sz++] = a[i][j];
        cin >> w[i];
    }
    sort(elem, elem + sz);
    sz = unique(elem, elem + sz) - elem;
    iota(ord, ord + n, 0);
    sort(ord, ord + n, [&](int i, int j) {return w[i] < w[j];});
    rep(i, n) conv[ord[i]] = i;
    rep(i, n) {
        sort(a[i], a[i] + m);
        rep(j, m) {
            int v = lower_bound(elem, elem + sz, a[i][j]) - elem;
            a[i][j] = v;
            if(!j || a[i][j] != a[i][j - 1]) idx[v].pb(conv[i]);
        }
    }
    rep(i, sz) if(idx[i].size() >= T) {
        good[i] = make_unique<bitset<N>>();
        good[i] -> set();
        for(int v: idx[i]) good[i] -> reset(v);
    }
    int ans = INT_MAX;
    rep(i, n) {
        state.set();
        state[conv[i]] = 0;
        rep(j, m) if(!j || a[i][j] != a[i][j - 1]) {
            int v = a[i][j];
            if(idx[v].size() < T) for(int x: idx[v]) state[x] = 0;
            else state &= *good[v];
        }
        int id = state._Find_first();
        if(id >= n) continue;
        else {
            id = ord[id];
            ans = min(ans, w[i] + w[id]);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}