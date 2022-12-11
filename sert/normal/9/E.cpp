#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> ES;
const int INF = (int)1e9 + 41;

void dfsCnt(int v, int pr, const ES &es, vector<bool> &u, int &V, int &E, vector<int> &one) {
    if (u[v]) return;
    V++;
    u[v] = true;
    if ((int)es[v].size() > 2) E = INF;
    if ((int)es[v].size() <= 1) one.push_back(v);
    for (int w : es[v]) {
        if (w <= v) E++;
        if (w == pr) continue;
        dfsCnt(w, v, es, u, V, E, one);
    }
}

int fail() {
    cout << "NO\n";
    return 0;
}

vector<int> pr;
int fnd(int v) {
    return (pr[v] == v ? v : pr[v] = fnd(pr[v]));
}

void uniq(int v1, int v2) {
    if (v1 == v2) return;
    //cout << v1 + 1 << " & " << v2 + 1 << "\n";
    pr[fnd(v1)] = fnd(v2);
//    for (int i = 0; i < 6; i++) cout << fnd(i) << " ";
//    cout << "\n";
}

int solve() {
    int n, m, v1, v2;
    cin >> n >> m;
    ES es(n);
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--; v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    if (n == 1) {
        if (m > 1) return fail();
        cout << "YES\n";
        if (m == 1) cout << "0\n";
        else cout << "1\n1 1\n";
        return 0;
    }

    vector<bool> u(n, false);
    vector<int> comp(n, -1);
    int compNum = 0;
    set<int> s;
    vector<pair<int, int>> ans;
    vector<int> sz1;
    pr.resize(n);
    for (int i = 0; i < n; i++) pr[i] = i;
    int numEnds = 0;
    for (int i = 0; i < n; i++) {
        if (u[i]) continue;
        int v = 0, e = 0;
        vector<int> one;
        dfsCnt(i, -1, es, u, v, e, one);
        //cout << i << " " << v << " " << e << endl;
        if (e > v || (v < n && v == e) || (int)one.size() > 2) {
            //cout << n << " " << v << " " << e << " " << one.size() << endl;
            return fail();
        }
        for (int x : one) {
            comp[x] = compNum;
            s.insert(x);
            uniq(x, one[0]);
        }
        numEnds += max(2, (int)one.size());
        sz1.push_back(one.size());
        compNum++;
    }

    if (s.empty()) {
        cout << "YES\n0\n";
        return 0;
    }

    while (numEnds > 2) {
        auto it = s.begin();
        v1 = *it;
        it++;
        v2 = *it;
        if (fnd(v1) == fnd(v2)) {
            it++;
            v2 = *it;
        }
        ans.emplace_back(v1, v2);
        uniq(v1, v2);
        numEnds -= 2;
        if (sz1[comp[v1]] == 1) sz1[comp[v1]]++;
        else s.erase(v1);
        if (sz1[comp[v2]] == 1) sz1[comp[v2]]++;
        else s.erase(v2);
    }
    if ((int)s.size() != 2) exit(11);
    ans.emplace_back(*s.begin(), *s.rbegin());
    cout << "YES\n" << ans.size() << "\n";
    for (const auto &[v1, v2] : ans) {
        cout << v1 + 1 << " " << v2 + 1 << "\n";
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 1;
#endif
    while (t--) {
        solve();
    }
}