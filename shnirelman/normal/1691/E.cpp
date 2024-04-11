#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;

vector<int> g[N * 9];
bool used[N * 9];

void dfs(int v) {
//    if(v >= 80)cout << "dfs_in " << v << endl;
    used[v] = true;
    for(int u : g[v])
        if(!used[u]) {
//            cout << v << " -> " << u << endl;
            dfs(u);
        }
//    if(v >= 80)cout << "dfs_out " << v << endl;
}

int c[N], l[N], r[N];
int add[N * 2][2];
bool both[N * 2];

void build(int v, int l, int r, int mx) {
//    cout << "build " << v << ' ' << l << ' ' << r << endl;
    if(r - l == 1) {
        if(both[l])
            g[v].push_back(v + mx);
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m, mx);
    build(v * 2 + 2, m, r, mx);

    g[v].push_back(v * 2 + 1);
    g[v].push_back(v * 2 + 2);

    g[v * 2 + 1 + mx].push_back(v + mx);
    g[v * 2 + 2 + mx].push_back(v + mx);
}

void upd(int v, int l, int r, int mx, int ql, int qr, int u) {
    if(ql >= r || qr <= l)
        return;

    if(ql <= l && r <= qr) {
        g[u].push_back(v);
        g[v + mx].push_back(u);
        return;
    }

    int m = (l + r) / 2;
    upd(v * 2 + 1, l, m, mx, ql, qr, u);
    upd(v * 2 + 2, m, r, mx, ql, qr, u);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a;
    for(int i = 0; i < n; i++) {
        cin >> c[i] >> l[i] >> r[i];
        a.push_back(l[i]);
        a.push_back(r[i]);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for(int i = 0; i < a.size(); i++) {
        add[i][0] = add[i][1] = 0;
        both[i] = false;
    }

    for(int i = 0; i < n; i++) {
        l[i] = lower_bound(a.begin(), a.end(), l[i]) - a.begin();
        r[i] = lower_bound(a.begin(), a.end(), r[i]) - a.begin();
    }

    for(int i = 0; i < n; i++) {
        add[l[i]][c[i]]++;
        add[r[i] + 1][c[i]]--;
    }

    int cur[2] = {0, 0};
    for(int i = 0; i < a.size(); i++) {
        cur[0] += add[i][0];
        cur[1] += add[i][1];

        both[i] = (cur[0] > 0 && cur[1] > 0);
    }

//    for(int i = 0; i < a.size(); i++) {
//        cout << i << ' ' << a[i] << ' ' << both[i] << endl;
//    }

//    for(int i = 0; i < n; i++) {
//        cout << "segment " << i << ' ' << l[i] << ' ' << r[i] << endl;
//    }

    int mx = a.size() * 4;
//    cout << "mx = " << mx << endl;
    for(int i = 0; i < mx * 2 + n; i++) {
        used[i] = false;
        g[i].erase(g[i].begin(), g[i].end());
    }

    build(0, 0, a.size(), mx);
    for(int i = 0; i < n; i++) {
        upd(0, 0, a.size(), mx, l[i], r[i] + 1, i + mx * 2);
    }


    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!used[mx * 2 + i]) {
//            cout << "------------------------------" << endl;
            dfs(mx * 2 + i);
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}