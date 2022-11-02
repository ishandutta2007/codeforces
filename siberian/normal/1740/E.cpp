#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a)        \
    for (auto& i : a) \
    cin >> i

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template <typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
    if (y < x)
        x = y;
}

template <typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y)
        x = y;
}

const int N = 1e5 + 10;
const int INF = 1e9 + 228;

int n;
vector<int> g[N];
int par[N];
int h[N];
int deg[N];
int p[N];
int timer = 0;
int dp[N];
int max_h[N];

void dfs(int v) {
    max_h[v] = h[v];
    int sum = 0;
    for (auto to : g[v]) {
        h[to] = h[v] + 1;
        dfs(to);
        sum += dp[to];
        chkmax(max_h[v], max_h[to]);
    }
    dp[v] = 1;
    for (auto to : g[v]) {
        chkmax(dp[v], sum - dp[to] + max_h[to] - h[v]);
    }
    chkmax(dp[v], max_h[v] - h[v] + 1);
    chkmax(dp[v], sum);

    // p[v] = timer++;
}

// int a[N];
// int top = 0;
// int d[N];

// int calc() {
//     set<pair<int, int>> q;
//     fill(deg, deg + n, 0);
//     for (int i = 0; i < n; ++i) {
//         deg[i] = g[i].size();
//         if (!deg[i]) {
//             q.insert(mp(p[i], i));
//         }
//     }
//     top = 0;
//     while (!q.empty()) {
//         a[top++] = q.begin()->first;
//         int v = q.begin()->second;
//         q.erase(q.begin());
//         deg[par[v]]--;
//         chkmin(p[par[v]], p[v]);
//         if (!deg[par[v]]) {
//             q.insert(mp(p[par[v]], par[v]));
//         }
//     }
//     assert(top == n);

//     // cerr << "a = " << endl;
//     // for (int i = 0; i < n; ++i) {
//     //     cerr << a[i] << " ";
//     // }
//     // cerr << endl;

//     d[0] = -INF;
//     for (int i = 1; i <= n; ++i)
//         d[i] = INF;

//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         int j = int(upper_bound(d, d + n + 1, a[i]) - d);
//         if (d[j - 1] <= a[i] && a[i] < d[j]) {
//             d[j] = a[i];
//             chkmax(ans, j);
//         }
//     }
//     return ans;
// }

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        par[i] = p;
        g[p].push_back(i);
    }
    h[0] = 0;
    dfs(0);
    // iota(order, order + n, 0);
    // sort(order, order + n, [&](int lhs, int rhs) -> bool { return h[lhs] > h[rhs]; });
    // for (int i = 0; i < n; ++i) {
    //     p[order[i]] = i;
    // }
    // cerr << "p = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << p[i] << " ";
    // }
    // cerr << endl;
    // int ans = calc();
    // cout << ans << '\n';
    cout << dp[0] << '\n';
    return 0;
}