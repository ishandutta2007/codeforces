#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 100001;
vector<int> g[N];
int sn[N], len, mx[N], up[N], csn[N], maxl[N], pos[N], maxp;

int getmx(int v, int p) {
    int res = 0;
    for (int u : g[v])
        if (u != p)
            res = max(res, getmx(u, v));
    return res + 1;
}

int dfs1(int v, int p, int t) {
    if (v == t) {
        sn[v] = 1;
        pos[v] = maxp++;
        len++;
        return 1;
    }
    for (int u : g[v]) {
        if (u == p)
            continue;
        if (dfs1(u, v, t)) {
            sn[v] = 1;
            pos[v] = maxp++;
            len++;
            return 1;
        }
    }
    return 0;
}

void dfs2(int v, int p) {
    for (int u : g[v]) {
        if (u == p)
            continue;
        up[u] = mx[v] + 1;
        dfs2(u, v);
        mx[v] = max(mx[v], mx[u] + 1);
    }
    int cm = 0;
    for (int i = g[v].size() - 1; i >= 0; i--) {
        int u = g[v][i];
        if (u == p)
            continue;
        up[u] = max(up[u], cm + 1);
        cm = max(cm, mx[u] + 1);
    }
}

void dfs3(int v, int p) {
    for (int u : g[v]) {
        if (u == p)
            continue;
        up[u] = max(up[u], up[v] + 1);
        dfs3(u, v);
        if (mx[u] >= len - 2)
            csn[v]++;
    }
    if (up[v] >= len - 1)
        csn[v]++;
}

int rot(int v, int p) {
    if (csn[v] >= 3)
        return 1;
    for (int u : g[v])
        if (!sn[u] && u != p && rot(u, v))
            return 1;
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, u, v, v1, v2;
    cin >> t;
    rep(z, t) {
        cin >> n >> v1 >> v2;
        v1--; v2--;
        rep(i, n - 1) {
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(v1, -1,v2);
        dfs2(0, -1);
        dfs3(0, -1);
        rep(i, n) {
            if (!sn[i])
                continue;
            for (int j : g[i])
                if (!sn[j])
                    maxl[pos[i]] = max(maxl[pos[i]], getmx(j, i));
        }
        int cl = 0, cr = len - 1, pl = cl, pr = cr;
        while (1) {
            if (pl <= cl) {
                if (pl < len)
                    cr = min(cr, pl + len - 1 - maxl[pl]);
                pl++;
            }
            else if (pr >= cr) {
                if (pr >= 0)
                    cl = max(cl, pr - len + 1 + maxl[pr]);
                pr--;
            }
            else
                break;
        }
        int fl = 0;
        rep(i, n) {
            if (!sn[i])
                continue;
            if ((cl >= pos[i] || cr <= pos[i]) && rot(i, -1))
                fl = 1;
        }
        if (fl)
            cout << "YES\n";
        else
            cout << "NO\n";
        rep(i, n) {
            g[i].clear();
            mx[i] = up[i] = sn[i] = csn[i] = maxl[i] = pos[i] = 0;
        }
        len = maxp = 0;
    }
}