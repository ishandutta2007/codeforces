#include <bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef array<int, 2> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

int n;
int a[N];
vi G[N];
int idx[N], cnt[N];
int badup[N], bdp[N];
pii baddown[N];
hash_map<int, int> mp[N];

int unite(int u, int v) {
    if(mp[u].size() > mp[v].size()) swap(u, v);
    for(auto &p : mp[u]) mp[v][p.first] += p.second;
    return v;
}

bool is_bad(int v, int p) {
    return bdp[v] || (baddown[v][0] != -1 && baddown[v][0] != p) || (baddown[v][1] != -1 && baddown[v][1] != p);
}

void dfs(int v, int p) {
    idx[v] = v;
    mp[v][a[v]]++;
    baddown[v] = {-1, -1};
    bdp[v] = 0;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        if(mp[idx[nxt]][a[v]]) {
            rep(j, 0, 2) {
                if(baddown[v][j] == -1) {
                    baddown[v][j] = nxt;
                    break;
                }
            }
        }
        if(is_bad(nxt, v)) bdp[v]++;
        idx[v] = unite(idx[v], idx[nxt]);
    }
    if(mp[idx[v]][a[v]] != cnt[a[v]]) {
        rep(j, 0, 2) {
            if(baddown[v][j] == -1) {
                baddown[v][j] = p;
                break;
            }
        }
    }
}

int res = 0;

void reroot(int v, int p) {
    if(bdp[v] == 0 && baddown[v][0] == -1) {
//        cout << v +1 << endl;
        res++;
    }
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        int badcnt = bdp[v] - is_bad(nxt, v);
        int isbad = ((baddown[v][0] != -1) + (baddown[v][1] != -1) - (baddown[v][0] == nxt || baddown[v][1] == nxt)) > 0;
        if(badcnt == 0 && isbad == 0) reroot(nxt, v);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vi xs;
    rep(i, 0, n) cin >> a[i], xs.push_back(a[i]);
    sort(all(xs));
    xs.resize(unique(all(xs)) - xs.begin());
    rep(i, 0, n) a[i] = (int)(lower_bound(all(xs), a[i]) - xs.begin()), cnt[a[i]]++;

    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i, 0, n) idx[i] = i;
    dfs(0, -1);
    reroot(0, -1);
    cout << res << '\n';

}