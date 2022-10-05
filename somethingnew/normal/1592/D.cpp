// I hope one day I'll be at least half as cool as dsgrekova
#include <bits/stdc++.h>
//#pragma GCC optimise("O3")
//#pragma GCC optimise("Ofast,no-stack-protector")
//#pragma GCC optimise("unroll-loops")
//#pragma GCC optimise("fast-math")
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
const int INF = 1e18, N = 1e5 + 179;


vector<vector<int>> g;
vector<pair<int, int>> re;
void dfs(int v, int p = -1) {
    for (int u : g[v]) {
        if (u != p) {
            re.emplace_back(v, u);
            dfs(u, v);
        }
    }
    if (p != -1) {
        re.emplace_back(v, p);
    }
}

signed main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    cout.setf(ios::fixed);
    int n; cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        g[a - 1].push_back(b-1);
        g[b - 1].push_back(a-1);
    }
    dfs(0);
    int l = 0, r = re.size() - 1;
    cout << "? " << n << " ";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " ";
    }
    cout << endl;
    int res; cin >> res;
    while (l != r) {
        int m = (l + r) / 2;
        set<int> v;
        for (int i = l; i <= m; ++i) {
            v.insert(re[i].first);
            v.insert(re[i].second);
        }
        cout << "? " << v.size() << " ";
        for (int e : v) {
            cout << e + 1 << " ";
        }
        cout << endl;
        int ans; cin >> ans;
        if (ans == res) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << "! " << re[l].first + 1 << " " << re[r].second + 1 << endl;
    return 0;
}