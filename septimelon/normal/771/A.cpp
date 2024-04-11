#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
const int MAX = 1000000009;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void dfs(int v, int c, const vector<vector<int>>& r, vector<int>& col) {
    if (col[v] != -1) {
        return;
    }
    col[v] = c;
    for (int i = 0; i < r[v].size(); ++i) {
        dfs(r[v][i], c, r, col);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> r(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    
    vector<int> col(n, -1);
    vector<ll> cc(n, 0LL);
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            dfs(i, i, r, col);
        }
        ++cc[col[i]];
    }
    
    ll mm = 0;
    for (int i = 0; i < n; ++i) {
        mm += cc[i] * (cc[i] - 1) / 2;
    }
    if (mm == m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}