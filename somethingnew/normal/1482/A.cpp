#include "iostream"
#include "vector"
#include "numeric"
#include "algorithm"
#include "set"
#include "list"
#include "queue"
#define all(x) (x).begin(), (x).end()
using namespace std;
#define Dasha signed
#define Top main
#define int long long
const int MAXN = 605;
vector<pair<int, int>> g[605];
vector<pair<int, int>> zpr[605];
vector<pair<int, int>> edges;
vector<int> c;
vector<int> edgesval;
void solve (int v, int n) {
    vector<int> dst(n, -1);
    vector<pair<int, int>> elems(n, {-1, -1});
    vector<int> seen(n);
    elems[v] = {0, v};
    while (1) {
        pair<int, int> t = {-1, -1};
        for (int j = 0; j < n; ++j) {
            auto i = elems[j];
            if (seen[j])
                continue;
            if (t.second == -1)
                t = i;
            else {
                if (i.second != -1 and t.first > i.first)
                    t = i;
            }
        }
        if (t.second == -1)
            break;
        seen[t.second] = 1;
        int u = t.second;
        int val = t.first;
        dst[u] = val;
        for (auto [i, vl] : g[u]) {
            if (elems[i].second == -1)
                elems[i] = {val + vl, i};
            elems[i] = min(elems[i], {val + vl, i});
        }
    }
    vector<int> obrdst(n);
    seen.assign(n, 0);
    elems.assign(n, {-1, -1});
    for (auto [i, vl] : zpr[v]) {
        elems[i] = {vl, i};
    }
    while (1) {
        pair<int, int> t = {-1, -1};
        for (int j = 0; j < n; ++j) {
            auto i = elems[j];
            if (seen[j])
                continue;
            if (t.second == -1)
                t = i;
            else {
                if (i.second != -1 and t.first < i.first)
                    t = i;
            }
        }
        if (t.second == -1)
            break;
        int u = t.second;
        int val = t.first;
        //cout << u << ' ' << val << endl;
        seen[u] = 1;
        obrdst[u] = val;
        for (auto [i, vl] : g[u]) {
            if (seen[i] == 0)
                elems[i] = max(elems[i], {val - vl, i});
        }
    }
//    for (auto i : dst)
//        cout << i << ' ';
//    cout << endl;
//    for (auto i : obrdst)
//        cout << i << ' ';
//    cout << endl;
    for (int i = 0; i < edges.size(); ++i) {
        int v1 = edges[i].first, v2 = edges[i].second;
        if (dst[v1] != -1 and dst[v1] + c[i] <= obrdst[v2] and seen[v2])
            edgesval[i] = 1;
        if (dst[v2] != -1 and dst[v2] + c[i] <= obrdst[v1] and seen[v1])
            edgesval[i] = 1;
    }
}
Dasha Top() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    edges.assign(m, {});
    edgesval.assign(m, 0);
    c.assign(m, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b >> c[i];
        a--;b--;
        edges[i] = {a, b};
        g[a].push_back({b, c[i]});
        g[b].push_back({a, c[i]});
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        a--;b--;
        zpr[a].push_back({b, l});
        zpr[b].push_back({a, l});
    }
    for (int i = 0; i < n; ++i) {
        if (!zpr[i].empty())
            solve(i, n);
    }
    cout << accumulate(all(edgesval), 0);
//    for (auto i : edgesval)
//        cout << i << ' ';
}
// 5
// 3 1 2 4 5