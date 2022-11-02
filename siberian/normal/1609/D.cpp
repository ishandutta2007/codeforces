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

struct Dsu{
    vector<int> par;
    vector<int> sz;
    int maxSz;
    Dsu() {}
    Dsu(int n) : par(n), sz(n, 1), maxSz(1) {
        iota(all(par), 0);
    }
    int getPar(int v) {
        if (par[v] == v) return v;
        return par[v] = getPar(par[v]);
    }
    bool uni(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        if (a == b) return false;
        par[a] = b;
        sz[b] += sz[a];
        chkmax(maxSz, sz[b]);
        return true;
    }
    int getSz(int v) {
        return sz[getPar(v)];
    }
};

const int N = 1e3 + 10;
int n, d;
int sz[N];
bool used[N];
int topSz;
Dsu dsu;

void solve(int addEdges) {
    topSz = 0;
    fill(used, used + n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[dsu.getPar(i)]) {
            used[dsu.getPar(i)] = true;
            sz[topSz++] = dsu.getSz(i);
        }
    }
    sort(sz, sz + topSz);
    reverse(sz, sz + topSz);
    int ans = 0;
    for (int i = 0; i <= addEdges; ++i) {
        ans += sz[i];
    }
    ans -= 1;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> d;
    dsu = Dsu(n);
    int cnt = 0;
    for (int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        cnt += !dsu.uni(x, y);
        // cout << dsu.getSz() - 1 << '\n';
        solve(cnt);
    }
    return 0;
}