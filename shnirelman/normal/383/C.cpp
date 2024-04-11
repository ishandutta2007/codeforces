#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 2e5 + 13;
const int B = 500;

vector<int> g[N];
int a[N], add[N];
int col[N];
int lf[N][2], rg[N][2];
vector<int> s[2];

void dfs(int v, int par, int cl) {
    col[v] = cl;

    for(int i = 0; i < 2; i++)
        lf[v][i] = s[i].size();

    s[col[v]].push_back(v);

    for(auto u : g[v])
        if(u != par)
            dfs(u, v, cl ^ 1);

    for(int i = 0; i < 2; i++)
        rg[v][i] = s[i].size();
}

int t[4 * N][2];

void build(int v, int l, int r, int i) {
    if(r - l <= 1) {
        t[v][i] = 0;
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m, i);
    build(v * 2 + 2, m, r, i);

    t[v][i] = 0;
}

void update(int v, int l, int r, int i, int ql, int qr, int x) {
    if(ql >= r || qr <= l)
        return;

    if(ql <= l && r <= qr) {
        t[v][i] += x;
        return;
    }

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, i, ql, qr, x);
    update(v * 2 + 2, m, r, i, ql, qr, x);
}

int get(int v, int l, int r, int i, int ind) {
    if(ind < l || ind >= r)
        return 0;

    if(r - l <= 1)
        return t[v][i];

    int m = (l + r) / 2;

    return t[v][i] + get(v * 2 + 1, l, m, i, ind) +
            get(v * 2 + 2, m, r, i, ind);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0, 0);

    build(0, 0, s[0].size(), 0);
    build(0, 0, s[1].size(), 1);

//    for(int i = 0; i < 2; i++) {
//        for(auto x : s[i])
//            cout << x << ' ';
//
//        cout << endl;
//    }
//
//    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << col[i] << ' ' << lf[i][0] << ' ' << rg[i][0] <<
//            ' ' << lf[i][1] << ' ' << rg[i][1] << endl;
//    }

    for(int i = 0; i < m; i++) {
        int beh;
        cin >> beh;

        if(beh == 1) {
            int v, x;
            cin >> v >> x;

            v--;

            update(0, 0, s[col[v]].size(), col[v], lf[v][col[v]], rg[v][col[v]], x);
            update(0, 0, s[col[v] ^ 1].size(),
                   col[v] ^ 1, lf[v][col[v] ^ 1], rg[v][col[v] ^ 1], -x);
        } else {
            int v;
            cin >> v;

            v--;

            cout << a[v] + get(0, 0, s[col[v]].size(), col[v], lf[v][col[v]]) << '\n';
        }
    }
}