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

#define int ll

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        return a - MOD;
    }
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) {
        return a + MOD;
    }
    return a;
}

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

int n, m;
vector<int> a;
vector<vector<int>> g, rg;
vector<int> order;
vector<bool> good;

void brute() {
    fill(all(good), false);
    for (int i = 0; i < n; ++i) {
        good[i] = (a[i] > 0);
    }
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            for (auto to : g[i]) {
                a[to]++;
            }
            a[i]--;
        }
    }
}

vector<bool> used;

void dfs(int v) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    order.push_back(v);
}

void process() {
    for (int i = 0; i < n; ++i) {
        a[i] = a[i] % MOD;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(all(order));
    for (auto v : order) {
        for (auto to : g[v]) {
            a[to] = add(a[to], a[v]);
        }
    }
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    vin(a);
    g.assign(n, vector<int>());
    rg.assign(n, vector<int>());
    order = vector<int>();
    good = vector<bool>(n, false);
    used = vector<bool>(n, false);
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        --from;
        --to;
        g[from].push_back(to);
        rg[to].push_back(from);
    }
    if (*max_element(all(a)) == 0) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= n; ++i) {
        brute();
        if (*max_element(all(a)) == 0) {
            cout << i << "\n";
            // cout.flush();
            return;
        }
    }
    // for (auto i : a) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
    // exit(0);
    // cout << -1 << endl;
    // return;
    int ans = n;
    process();
    ans = add(a[order[n - 1]], ans);
    cout << ans << '\n';    
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}