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
const int N=200050;
struct dsu {
    int p[N], sz[N], edprc[N];
    vector<pair<int, int>> persikp = {{-1,-1}}, persiksz = {{-1,-1}}, persiked = {{-1, -1}};
    int c = 0;
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            sz[i] = 1;
        }
    }
    pair<int, int> getdep(int v) {
        int res = 0;
        while (p[v] != v) {
            res ^= edprc[v];
            v = p[v];
        }
        return {res, v};
    }
    int getv(int v) {
        while (v != p[v]) {
            c ^= edprc[v];
            v = p[v];
        }
        return v;
    }
    bool maymrg(int a, int b) {
        pair<int, int> a1 = getdep(a), b1 = getdep(b);
        if (a1.second == b1.second and (a1.first ^ b1.first) == 0)
            return 0;
        return 1;
    }
    void merg(int a, int b) {
        c = 1;
        a = getv(a);
        b = getv(b);
        if (a == b)
            return;
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        persikp.emplace_back(a, p[a]);
        persiksz.emplace_back(b, sz[b]);
        persiked.emplace_back(a, edprc[a]);
        p[a] = b;
        sz[b] += sz[a];
        edprc[a] = c;
    }
    void stop() {
        persikp.emplace_back(-1, -1);
        persiksz.emplace_back(-1, -1);
        persiked.emplace_back(-1, -1);
    }
    void restwr() {
        pair<int, int> st = {-1, -1};
        while (persikp.back() != st) {
            p[persikp.back().first] = persikp.back().second;
            persikp.pop_back();
        }
        persikp.pop_back();
        while (persiksz.back() != st) {
            sz[persiksz.back().first] = persiksz.back().second;
            persiksz.pop_back();
        }
        persiksz.pop_back();
        while (persiked.back() != st) {
            edprc[persiked.back().first] = persiked.back().second;
            persiked.pop_back();
        }
        persiked.pop_back();
    }
};
vector<pair<int, int>> ed;
vector<int> res;
void razdelka(int l1, int r1, int l2, int r2, dsu &dska) { // (r1+...)
    //cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
    if (l1 > r1)
        return;
    if (l1 == r1) {
        dska.stop();
        int ind = -1;
        dska.merg(ed[l1].first, ed[l1].second);
        for (int i = l2; i <= r2; ++i) {
            if (dska.maymrg(ed[i].first, ed[i].second) == 0) {
                ind = i;
                break;
            }
            dska.merg(ed[i].first, ed[i].second);
        }
        dska.restwr();
        res[l1] = ind;
        return;
    }
    int m1 = (l1 + r1) / 2;
    //cout << m1 << endl;
    dska.stop();
    int ind = -2;
    for (int i = m1; i <= r1; ++i) {
        dska.merg(ed[i].first, ed[i].second);
    }
    dska.stop();
    for (int i = l2; i <= r2; ++i) {
        if (dska.maymrg(ed[i].first, ed[i].second) == 0) {
            ind = i;
            break;
        }
        dska.merg(ed[i].first, ed[i].second);
    }
    dska.restwr();
    if (ind != -2)
        razdelka(l1, m1-1, l2, ind, dska);
    dska.restwr();
    if (ind == -2)
        return;
    res[m1] = ind;
    dska.stop();
    for (int i = l2; i < ind; ++i) {
        dska.merg(ed[i].first, ed[i].second);
    }
    razdelka(m1 + 1, r1, ind, r2, dska);
    dska.restwr();
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    res.assign(m, -1);
    ed.assign(m, {});
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        ed[i] = {a, b};
    }
    dsu dska;
    dska.init(n);
    dska.stop();
    int ind = -1;
    for (int i = m - 1; i >= 0; --i) {
        if (dska.maymrg(ed[i].first, ed[i].second) == 0) {
            ind = i;
            break;
        }
        dska.merg(ed[i].first, ed[i].second);
    }
    dska.restwr();
    dska.stop();
    int indleft = -1;
    for (int i = 0; i < m; ++i) {
        if (dska.maymrg(ed[i].first, ed[i].second) == 0) {
            indleft = i;
            break;
        }
        dska.merg(ed[i].first, ed[i].second);
    }
    dska.restwr();
    if (ind != -1) {
        razdelka(ind + 1, m - 1, 0, indleft, dska);
    }
    for (int i = 0; i < q; ++i) {
        //dska.init(n);
        int l, r;
        cin >> l >> r;
        l -= 2;
        if (ind == -1) {
            cout << "NO\n";
            continue;
        }
        if (r <= ind) {
            cout << "YES\n";
            continue;
        }
        if (l >= indleft) {
            cout << "YES\n";
            continue;
        }
        if (r == m) {
            cout << "NO\n";
            continue;
        }
        if (res[r] != -1 and res[r] <= l) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}