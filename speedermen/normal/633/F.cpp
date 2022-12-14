#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second

vector < int > g[N];
int n, a[N];
ll x[N], y[N], z[N], rs;

bool cx(int i, int j) {
    return x[i] > x[j];
}

bool cy(int i, int j) {
    return y[i] > y[j];
}

void dfs(int v, int p) {
    x[v] = a[v];
    vector <long long> f;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(to == p) continue;
        dfs(to, v);
        x[v] = max(x[v], x[to] + a[v]);
        y[v] = max(y[v], max(y[to], x[v]));
        f.push_back(x[to]);
    }
    sort(f.rbegin(), f.rend());
    if (f.size() >= 2) {
        y[v] = max(y[v], f[0] + a[v] + f[1]);
    }
    vector <int> h;
    for (int i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        if (to == p) continue;
        z[v] = max(z[v], z[to] + a[v]);
        h.push_back(to);
    }
    z[v] = max(z[v], y[v]);
    sort(h.begin(), h.end(), cy);
    if (h.size() >= 2) {
        rs = max(rs, y[h[0]] + y[h[1]]);
    }
    sort(h.begin(), h.end(), cx);
    for (int i = 0; i < h.size(); ++i) {
        ll cur = 0;
        for (int j = 0; j < h.size() && j < 2; ++j)
            if (i != j)
                cur = max(cur, x[h[j]]);
        z[v] = max(z[v], cur + y[h[i]] + a[v]);
    }
    for (int i = 0; i < h.size(); ++i) {
        ll cur = 0;
        for (int j = 0; j < h.size() && j < 2; ++j) {
            if (i == j) continue;
            cur = max(cur, x[h[j]]);
        }
        rs = max(rs, cur + z[h[i]] + a[v]);
    }
    for (int i = 0; i < h.size(); ++i) {
        ll cur = 0;
        vector < ll > u;
        for (int j = 0; j < h.size() && j < 3; ++j) {
            if (i == j) continue;
            u.push_back(x[h[j]]);
        }
        for (int k = 0; k < u.size() && k < 2; ++k) {
            cur += u[k];
        }
        rs = max(rs, cur + y[h[i]] + a[v]);
    }
    rs = max(rs, z[v]);
    y[v] = max(y[v], x[v]);
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << rs << endl;
    return 0;
}