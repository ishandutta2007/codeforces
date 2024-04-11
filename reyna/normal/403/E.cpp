// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 4e5 + 5, L = 18, mod = 0;

int n, t, h[2][N], par[2][N], st[2][N], ed[2][N], used, mark[2][N], anc[2][N][L];
pair<int, int> q[N];
vector<int> adj[2][N];
vector<pair<int, int>> seg[2][N << 2];

void dfs(int v, int g, int p = 0) {
    st[g][v] = used++;
    h[g][v] = h[g][p] + 1;
    anc[g][v][0] = p;
    for (int i = 1; i < L; ++i)
        anc[g][v][i] = anc[g][anc[g][v][i - 1]][i - 1];
    for (int u : adj[g][v]) if (u != p)
        dfs(u, g, v);
    ed[g][v] = used;
}

int lca(int u, int v, int g) {
    if (h[g][u] < h[g][v])
        swap(u, v);
    for (int i = 0; i < L; ++i)
        if (h[g][u] - h[g][v] >> i & 1)
            u = anc[g][u][i];
    if (u == v)
        return v;
    for (int i = L - 1; i >= 0; --i)
        if (anc[g][v][i] != anc[g][u][i])
            v = anc[g][v][i], u = anc[g][u][i];
    return anc[g][v][0];
}

void update(int pos, pair<int, int> x, int g, int v = 1, int b = 0, int e = n) {
    seg[g][v].push_back(x);
    if (b + 1 != e) {
        int m = b + e >> 1, l = v << 1, r = l | 1;
        if (pos < m)
            update(pos, x, g, l, b, m);
        else
            update(pos, x, g, r, m, e);
    }
}

void visit(int i, int j, int x, int g, int v = 1, int b = 0, int e = n) {
    if (i >= e || b >= j)
        return;
    if (i <= b && e <= j) {
        while ((int) seg[g][v].size()) {
            auto cur = seg[g][v].back();
            if (cur.first >= x) {
                break;
            }
            if (!mark[g ^ 1][cur.second]++)
                q[t++] = make_pair(cur.second, g ^ 1);
            seg[g][v].pop_back();
        }
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    visit(i, j, x, g, l, b, m);
    visit(i, j, x, g, r, m, e);
}

pair<int, int> ord[N * 4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int j = 0; j < 2; ++j)
       for (int i = 1; i < n; ++i) {
           cin >> par[j][i];
           par[j][i]--;
           adj[j][par[j][i]].push_back(i);
       }
    for (int i = 0; i < 2; ++i)
        dfs(0, i), used = 0;
    for (int j = 0; j < 2; ++j)
        for (int v = 1; v < n; ++v) {
            int l = lca(v, par[j][v], j ^ 1);
            ord[used++] = make_pair(st[j ^ 1][l], v << 1 | j);
            /*
            update(st[j ^ 1][v], make_pair(st[j ^ 1][l], v), j ^ 1);
            update(st[j ^ 1][u], make_pair(st[j ^ 1][l], v), j ^ 1);
            */
        }
    sort(ord, ord + used);
    reverse(ord, ord + used);
    rep(_i, used) {
        int x = ord[_i].first, v = ord[_i].second >> 1, j = ord[_i].second & 1, u = par[j][v];
        update(st[j ^ 1][v], make_pair(x, v), j ^ 1);
        update(st[j ^ 1][u], make_pair(x, v), j ^ 1);
    }
    int start, h = 0, last = 0;
    cin >> start;
    q[t++] = make_pair(start, 0);
    mark[0][start] = 1;
    while (h != t) {
        int e = q[h].first, g = q[h++].second;
        visit(st[g][e], ed[g][e], st[g][e], g);
        if (h == t || q[h].second != g) {
            sort(q + last, q + h);
            cout << (g == 1? "Red": "Blue") << '\n';
            for (int i = last; i < h; ++i)
                cout << q[i].first << ' ';
            cout << '\n';
            last = h;
        }
    }
}