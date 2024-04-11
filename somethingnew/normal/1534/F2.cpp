#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "map"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

vector<vector<int>> numka;
vector<vector<int>> pole;
int c = 0;
int n, m;
set<pair<int, int>> edges;
vector<vector<int>> g, gobr;
void dfs(int i, int j, int clr) {
    if (pole[i][j] == 0)
        return;
    if (numka[i][j] == clr)
        return;
    numka[i][j] = clr;
    if (i + 1 < n)
        dfs(i + 1, j, clr);
    if (i > 0)
        dfs(i - 1, j, clr);
    if (j > 0)
        dfs(i, j - 1, clr);
    if (j + 1 < m)
        dfs(i, j + 1, clr);
}
int findp(vector<int> &elems, int i, int j) {
    if (elems.empty())
        return -1;
    auto iter = upper_bound(all(elems), i);
    if (iter == elems.end())
        return -1;
    //cout << i << ' ' << j << ' ' << *iter << ' ' << numka[*iter][j] << endl;
    return numka[*iter][j];
}
vector<int> seen, top;
vector<int> clr;
void dfs1(int v) {
    if (seen[v])
        return;
    seen[v] = 1;
    for (auto i : g[v])
        dfs1(i);
    top.push_back(v);
}
void dfs2(int v, int cc) {
    if (clr[v] != -1)
        return;
    clr[v] = cc;
    for (auto i : gobr[v])
        dfs2(i, cc);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    pole.assign(n, vector<int>(m));
    vector<vector<int>> elems(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char t;
            cin >> t;
            if (t == '#') {
                pole[i][j] = 1;
                elems[j].push_back(i);
            }
        }
    }
    numka.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pole[i][j] and numka[i][j] == -1)
                dfs(i, j, c++);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pole[i][j]) {
                if (j != 0) {
                    int v = findp(elems[j-1], i, j-1);
                    if (v != -1 and v != numka[i][j]) {
                        edges.insert({numka[i][j], v});
                    }
                }
                int v = findp(elems[j], i, j);
                if (v != -1 and v != numka[i][j]) {
                    edges.insert({numka[i][j], v});
                }
                if (j + 1 != m) {
                    v = findp(elems[j+1], i, j+1);
                    if (v != -1 and v != numka[i][j]) {
                        edges.insert({numka[i][j], v});
                    }
                }
            }
        }
    }
    g.assign(c, {});
    gobr.assign(c, {});
    seen.assign(c, 0);
    clr.assign(c, -1);
    for (auto i : edges) {
        //cout << i.first << ' ' << i.second << endl;
        g[i.first].push_back(i.second);
        gobr[i.second].push_back(i.first);
    }
    for (int i = 0; i < c; ++i) {
        dfs1(i);
    }
    reverse(all(top));
    int ccc = 0;
    for (auto i : top) {
        if (clr[i] == -1)
            dfs2(i, ccc++);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (numka[i][j] != -1)
                numka[i][j] = clr[numka[i][j]];
        }
    }
    c = ccc;
    edges.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pole[i][j]) {
                if (j != 0) {
                    int v = findp(elems[j-1], i, j-1);
                    if (v != -1 and v != numka[i][j]) {
                        edges.insert({numka[i][j], v});
                    }
                }
                int v = findp(elems[j], i, j);
                if (v != -1 and v != numka[i][j]) {
                    edges.insert({numka[i][j], v});
                }
                if (j + 1 != m) {
                    v = findp(elems[j+1], i, j+1);
                    if (v != -1 and v != numka[i][j]) {
                        edges.insert({numka[i][j], v});
                    }
                }
            }
        }
    }
    g.assign(c, {});
    gobr.assign(c, {});
    //cerr << c << endl;
    for (auto i : edges) {
        //cerr << i.first << ' ' << i.second << endl;
        g[i.first].push_back(i.second);
        gobr[i.second].push_back(i.first);
    }
    vector<int> vazhn(c);
    vector<int> kk(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        kk[i] = k;
        if (k == 0)
            continue;
        vazhn[numka[elems[i][elems[i].size() - k]][i]] = 1;
    }
    for (int i = 0; i < c; ++i) {
        if (vazhn[i]) {
            for (auto j : g[i])
                vazhn[j] = 1;
        }
    }
    for (int i = c - 1; i >= 0; --i) {
        if (vazhn[i]) {
            for (auto j : gobr[i]){
                if (vazhn[j])
                    vazhn[i] = 0;
    
            }
        }
    }
    vector<int> otr;
    vector<int> numin(c);
    for (int i = 0; i < m; ++i) {
        int k = kk[i];
        if (k == 0)
            continue;
        if (vazhn[numka[elems[i][elems[i].size() - k]][i]] == 1) {
            otr.push_back(numka[elems[i][elems[i].size() - k]][i]);
            numin[otr.back()] = otr.size() - 1;
            vazhn[numka[elems[i][elems[i].size() - k]][i]] = 2;
        }
    }
    vector<pair<int, int>> ans(c, {-1, -1});
    for (int i = 0; i < c; ++i) {
       //cout << i << ' ' << vazhn[i] << endl;
        if (vazhn[i])
            ans[i] = {numin[i], numin[i]};
    }
    for (int i = c - 1; i >= 0; --i) {
        
        for (auto j : g[i]) {
            //cerr << i << ' ' << j << endl;
            if (ans[j].first != -1) {
                if (ans[i].first == -1)
                    ans[i] = ans[j];
                ans[i].first = min(ans[i].first, ans[j].first);
                ans[i].second = max(ans[i].second, ans[j].second);
            }
        }
    }
    vector<int> gg(otr.size());
    for (auto [i, j] : ans) {
        if (i == -1)
            continue;
        gg[i] = max(j + 1, gg[i]);
    }
    //cerr << gg[0] << ' ';
    for (int i = 1; i < otr.size(); ++i) {
        gg[i] = max(gg[i], gg[i - 1]);
        //cerr << gg[i] << ' ';
    }
    vector<int> dp(otr.size() + 1, 0);
    for (int i = otr.size() - 1; i >= 0; --i) {
        dp[i] = 1 + dp[gg[i]];
    }
    cout << dp[0];
}