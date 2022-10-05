#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "climits"
#include "queue"
#include "array"
#include "numeric"
#include "random"
using namespace std;
#define all(x) x.begin(), x.end()
vector<array<int, 3>> sobii;
struct dsu{
    int n;
    vector<int> p;
    void make(int nn) {
        n = nn;
        p.assign(nn, {});
        for (int i = 0; i < nn; ++i) {
            p[i] = i;
        }
    }
    int getv(int v) {
        if (v == p[v])
            return v;
        return p[v] = getv(p[v]);
    }
    bool onecomp(int a, int b) {
        return getv(a) == getv(b);
    }
    void merge(int a, int b, int ok = 1) {
        a = getv(a);
        b = getv(b);
        if (a != b) {
            if (ok)
                sobii.push_back({1, a, b});
            p[a] = b;
        }
    }
};
void mrg(vector<int> &a, vector<int> &b) {
    if (a.size() < b.size())
        swap(a, b);
    for (auto i : b)
        a.push_back(i);
    b.clear();
}
struct dsusolve {
    vector<vector<int>> g;
    vector<vector<vector<int>>> elems;
    vector<int> sz;
    vector<int> p;
    dsu dska;
    dsusolve(int n, vector<vector<int>> gsh) {
        dska.make(n);
        sz.assign(n, 1);
        g = move(gsh);
        p.assign(n, {});
        elems.assign(n, {});
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            elems[i].push_back({i});
        }
    }
    int getv(int v) {
        if (v == p[v])
            return v;
        return p[v] = getv(p[v]);
    }
    int incmp(int a, int b) {
        return dska.onecomp(a, b);
    }
    void merge(int a, int b) {
        a = getv(a);
        b = getv(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        vector<int> pelem(elems[b].size(), -1);
        for (int i = 0; i < elems[b].size(); ++i) {
            for (auto j : elems[b][i]) {
                for (int k = 0; k < elems[a].size(); ++k) {
                    if (pelem[i] == k)
                        continue;
                    int myt = 0;
                    for (auto t : elems[a][k]) {
                        //cout << t << ' ' << j << endl;
                        auto it = lower_bound(all(g[j]), t);
                        if (it == g[j].end() or *it != t) {
                            myt = 1;
                            //cout << "AMOGUS\n";
                            dska.merge(j, t);
                            break;
                        }
                    }
                    if (myt) {
                        if (pelem[i] == -1) {
                            pelem[i] = k;
                        } else {
                            int k1 = pelem[i], k2 = k;
                            if (k1 > k2)
                                swap(k1, k2);
                            mrg(elems[a][k1], elems[a][k2]);
                            if (elems[a][k2].empty()) {
                                swap(elems[a][k2], elems[a][elems[a].size() - 1]);
                                elems[a].pop_back();
                            } else {
                                exit(1);
                            }
                            pelem[i] = k1;
                            k--;
                        }
                    }
                }
            }
        }
        for (auto i : elems[b])
            elems[a].push_back(i);
    }
};
void solveline() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<array<int, 3>> ed(m);
    vector<array<int, 2>> edans(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        ed[i] = {c, a, b};
        edans[i] = {a, b};
    }
    vector<int> ans(m);
    sort(all(ed));
    for (int i = 0; i < n; ++i) {
        sort(all(g[i]));
    }
    dsusolve dska(n, g);
    for (int i = 0; i < m; ++i) {
        dska.merge(ed[i][1], ed[i][2]);
        while (i + 1 != m and ed[i][0] == ed[i + 1][0]) {
            i++;
            dska.merge(ed[i][1], ed[i][2]);
        }
        for (int j = 0; j < m; ++j) {
            if (ans[j] == 0 and dska.incmp(edans[j][0], edans[j][1]))
                ans[j] = ed[i][0];
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
void solveparall() {
    int n, m;
    cin >> n >> m;
    sobii.clear();
    vector<vector<int>> g(n);
    vector<array<int, 3>> ed(m);
    vector<array<int, 2>> edans(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        ed[i] = {c, a, b};
        edans[i] = {a, b};
    }
    vector<int> ans(m);
    sort(all(ed));
    for (int i = 0; i < n; ++i) {
        sort(all(g[i]));
    }
    vector<pair<int, int>> binp(m, {-1, m - 1});
    dsusolve dska(n, g);
    for (int i = 0; i < m; ++i) {
        dska.merge(ed[i][1], ed[i][2]);
        sobii.push_back({0, 0, 0});
    }
    while (1) {
        vector<vector<int>> sob(m);
        dsu dska2;
        dska2.make(n);
        bool ok = 0;
        for (int i = 0; i < m; ++i) {
            if (binp[i].first + 1 != binp[i].second) {
                int mm = binp[i].first + binp[i].second >> 1;
                sob[mm].push_back(i);
                ok = 1;
            }
        }
        if (ok == 0)
            break;
        int ind = 0;
        for (int i = 0; i < m; ++i) {
            while (sobii[ind][0] != 0) {
                dska2.merge(sobii[ind][1], sobii[ind][2], 0);
                ind++;
            }
            ind++;
            for (auto j : sob[i]) {
                if (dska2.onecomp(edans[j][0], edans[j][1])) {
                    binp[j].second = i;
                } else {
                    binp[j].first = i;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ed[binp[i].second][0] << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t, gr;
    cin >> t;
    while (t--) {
        solveparall();
    }
}

// 57(+19) 100 100 71
//359
/*
3 0
4 3
1 2 1
2 3 2
4 3 3
5 5
1 2 1
1 3 1
2 4 1
4 5 2
5 1 3
6 6
1 2 3
2 3 1
3 6 5
3 4 2
4 5 4
2 4 2
 */