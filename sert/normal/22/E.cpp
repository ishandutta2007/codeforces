#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> ES;
const int INF = (int)1e9 + 41;

void dfsOrd(int v, const ES &es, vector<int> &ord, vector<bool> &u) {
    if (u[v]) return;
    u[v] = true;
    for (int w : es[v]) dfsOrd(w, es, ord, u);
    ord.push_back(v);
}

void dfsBack(int v, const ES &es, vector<int> &comp, int compNum) {
    if (comp[v] != -1) return;
    comp[v] = compNum;
    for (int w : es[v]) dfsBack(w, es, comp, compNum);
}

void dfsRoot(int v, int root, const ES &es, vector<int> &tops) {
    if (tops[v] != -1) return;
    tops[v] = root;
    for (int w : es[v])
        dfsRoot(w, root, es, tops);
}

void solve() {
    int n;
    cin >> n;
    ES es(n);
    ES eo(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        es[i].push_back(x - 1);
        eo[x - 1].push_back(i);
    }
    vector<int> ord;
    vector<bool> u(n, false);
    for (int i = 0; i < n; i++)
        dfsOrd(i, es, ord, u);

    reverse(ord.begin(), ord.end());
    vector<int> comp(n, -1);
    int compNum = 0;
    vector<int> compV;
    for (int v : ord) {
        if (comp[v] != -1) continue;
        dfsBack(v, eo, comp, compNum++);
        compV.push_back(v);
    }
    //for (int i = 0; i < n; i++) cout << comp[i] << " "; cout << "\n";
    if (compNum == 1) {
        cout << "0\n";
        return;
    }
    vector<bool> isLast(compNum, true);
    vector<bool> isTop(compNum, true);
    for (int i = 0; i < n; i++)
        for (int v : es[i])
            if (comp[i] != comp[v]) {
                isLast[comp[i]] = false;
                isTop[comp[v]] = false;
            }
    vector<int> bots(n, -1);
    vector<int> botRoots;
    for (int i = 0; i < compNum; i++) if (isLast[i]) {
        dfsRoot(compV[i], botRoots.size(), eo, bots);
        botRoots.push_back(compV[i]);
    }
    vector<pair<int, int>> ans;

    for (int c = 0; c < compNum; c++) {
        if (!isTop[c]) continue;
        int bi = bots[compV[c]];
        int b2 = botRoots[(bi + 1) % botRoots.size()];
        ans.emplace_back(b2, compV[c]);
    }

    cout << ans.size() << "\n";
    for (const auto &[v1, v2] : ans) {
        cout << v1 + 1 << " " << v2 + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 3;
#endif
    while (t--) {
        solve();
    }
}