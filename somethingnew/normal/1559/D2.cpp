#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
struct snm{
    vector<int> batya;
    vector<vector<int>> elems;
    snm(int n) {
        elems.assign(n, {});
        batya.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            elems[i].push_back(i);
            batya[i] = i;
        }
    }
    int get(int v) {
        if (batya[v] == v)
            return v;
        return batya[v] = get(batya[v]);
    }
    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a != b) {
            if (elems[a].size() < elems[b].size())
                swap(a, b);
            batya[b] = a;
            for (auto i : elems[b])
                elems[a].push_back(i);
            elems[b].clear();
        }
    }
};
void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> e1(m1), e2(m2);
    snm sn1(n), sn2(n);
    for (auto &[u, v] : e1) {
        cin >> u >> v;
        u--;v--;
    }
    for (auto &[u, v] : e2) {
        cin >> u >> v;
        u--;v--;
    }
    if (m1 < m2) {
        swap(m1, m2);
        swap(e1, e2);
    }
    for (auto [u, v] : e1) {
        sn1.merge(u, v);
    }
    for (auto [u, v] : e2) {
        sn2.merge(u, v);
    }
    set<int> notina;
    for (int i = 0; i < n; ++i) {
        notina.insert(i);
    }
    vector<pair<int, int>> ans;
    for (auto i : sn1.elems[sn1.get(0)]) {
        notina.erase(i);
    }
    for (auto i : notina) {
        if (sn1.get(i) != sn1.get(0)) {
            while (sn2.get(sn1.elems[sn1.get(0)].back()) == sn2.get(sn1.elems[sn1.get(0)][0]) and sn1.elems[sn1.get(0)].size() > 1)
                sn1.elems[sn1.get(0)].pop_back();
            int v1 = sn1.elems[sn1.get(0)][0];
            if (sn2.get(i) != sn2.get(v1)) {
                ans.push_back({i, v1});
                sn2.merge(i, v1);
                sn1.merge(i, v1);
            } else {
                v1 = sn1.elems[sn1.get(0)].back();
                if (sn2.get(i) != sn2.get(v1)) {
                    ans.push_back({i, v1});
                    sn2.merge(i, v1);
                    sn1.merge(i, v1);
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto [u, v] : ans) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
}
signed main() {
    int n = 1;
    while (n--) solve();
}