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

vector<vector<int>> ig, g, li;
vector<int> used, p, q, par;

void dfs(int v) {
    used[v] = 1;
    int fv = -1, dv = -1;
    for (int u : g[v]) {
        if (used[u])
            continue;
        dfs(u);
        if (par[u] == -1) {
            li[v].push_back(u);
            par[u] = v;
            par[v] = v;
        }
        else if (par[u] == u)
            fv = u;
        else
            dv = u;
    }
    if (par[v] == -1) {
        if (fv != -1) {
            par[v] = fv;
            li[fv].push_back(v);
        }
        else if (dv != -1) {
            li[par[dv]].pop_back();
            par[v] = v;
            par[dv] = v;
            li[v].push_back(dv);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, m, u, v;
    cin >> t;
    rep(z, t) {
        cin >> n >> m;
        ig.assign(n, vector<int>());
        g.assign(n, vector<int>());
        li.assign(n, vector<int>());
        used.assign(n, 0);
        p.assign(n, 0);
        q.assign(n, 0);
        par.assign(n, -1);
        rep(i, m) {
            cin >> u >> v;
            u--; v--;
            ig[u].push_back(v);
            ig[v].push_back(u);
        }
        rep(i, n) {
            sort(all(ig[i]));
            if (ig[i].size() == n - 1)
                continue;
            int pos = 0;
            rep(j, n) {
                if (j == i)
                    continue;
                if (pos == ig[i].size() || ig[i][pos] != j) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                    break;
                }
                pos++;
            }
        }
        rep(i, n)
            if (!used[i])
                dfs(i);
        int np = 1, nq = 1;
        rep(i, n) {
            if (par[i] != i && par[i] != -1)
                continue;
            for (int j : li[i]) {
                p[j] = np++;
            }
            p[i] = np++;
            q[i] = nq++;
            for (int j : li[i])
                q[j] = nq++;
        }
        assert(np == n + 1);
        for (int i : p)
            cout << i << ' ';
        cout << '\n';
        for (int i : q)
            cout << i << ' ';
        cout << '\n';
    }
}