#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 1e6 + 10;
int n;
vector<int> g[N];
ll ans = 0;

int sz[N];

ll vans[N];

void dfs_down(int v, int p) {
    sz[v] = 1;
    vans[v] = 0;
    for (auto i : g[v]) {
        if (i == p) continue;
        dfs_down(i, v);
        sz[v] += sz[i];
        vans[v] += vans[i];
    }
    vans[v] += sz[v];
}

void dfs_up(int v, int p) {
    for (auto i : g[v]) {
        if (i == p) continue;
        ll cur_vans = vans[v] - vans[i] - sz[i];
        int cur_sz = n - sz[i];
        vans[i] += cur_vans + cur_sz;
        dfs_up(i, v);
    }
}

void calcVans() {
    dfs_down(0, 0);

    // cerr << "vans = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << vans[i] << " ";
    // }
    // cerr << endl;
    dfs_up(0, 0);
    // cerr << "vans = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << vans[i] << " ";
    // }
    // cerr << endl;
}

int w[N];
int topW = 0;

bitset<N / 2> dp;

int solve() {
    map<int, int> cnt;
    for (int i = 0; i < topW; i++) {
        cnt[w[i]]++;
    }
    topW = 0;
    for (auto el : cnt) {
        int k = el.second;
        int cur = 1;
        while (cur <= k) {
            w[topW++] = cur * el.first;
            k -= cur;
            cur <<= 1;
        }
        if (k) {
            w[topW++] = k * el.first;
        }
    }
    sort(w, w + topW);
    reverse(w, w + topW);
    if (w[0] * 2 > n) {
        return w[0];
    } else {
        dp &= 0;
        dp[0] = 1;
        for (int i = 0; i < topW; ++i) {
            dp |= (dp << w[i]);
        }

        for (int i = n / 2; i >= 0; --i) {
            if (dp[i]) {
                return i;
            }
        }
        assert(false);
        return -1;
    }
}

void dfs(int v, int p) {
    sz[v] = 1;
    for (auto i : g[v]) {
        if (i == p) continue;
        dfs(i, v);
        sz[v] += sz[i];
    }
    topW = 0;
    for (auto i : g[v]) {
        if (i == p) {
            w[topW++] = n - sz[v];   
        } else { 
            w[topW++] = sz[i];
        }
    }
    int half = solve();
    // cerr << "half = " << half << endl;
    chkmax(ans, vans[v] + (ll)half * (n - half - 1));
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
        g[i].push_back(p);
    }   
    calcVans();
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}