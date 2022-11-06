#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()

typedef long long ll;

void make_tree(int v, int par, vector<vector<int>> &gr, vector<int> &pr) {
    if (pr[v] == -2) {
        pr[v] = par;
        for (auto w : gr[v]) make_tree(w, v, gr, pr);
    }
}

bool dfs(int from, int to, int par, vector<vector<int>> &gr, vector<int> &pth) {
    if (from == to) {
        pth.push_back(to);
        return true;
    }
    for (auto w : gr[from]) {
        if (w == par) continue;
        if (dfs(w, to, from, gr, pth)) {
            pth.push_back(from);
            return true;
        }
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> gr(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<int> pr(n, -2);
    make_tree(0, -1, gr, pr);

    int q;
    cin >> q;

    vector<pair<int, int>> paths(q);
    vector<int> pathsum(n);

    for (int i = 0; i < q; i++) {
        cin >> paths[i].first >> paths[i].second;
        paths[i].first--;
        paths[i].second--;
        pathsum[paths[i].first]++;
        pathsum[paths[i].second]++;
    }

    for (int i = 0; i < n; i++) {
        gr[i].clear();
    }
    for (int i = 1; i < n; i++) {
        gr[i].push_back(pr[i]);
        gr[pr[i]].push_back(i);
    }

    int odd = 0;
    for (int i = 0; i < n; i++) if (pathsum[i] % 2 != 0) odd++;

    if (odd > 0) {
        cout << "NO\n" << odd / 2 << "\n";
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < q; i++) {
            vector<int> pth;
            dfs(paths[i].first, paths[i].second, -1, gr, pth);
            reverse(all(pth));
            cout << sz(pth) << "\n";
            for (auto el : pth) cout << el + 1 << ' ';
            cout << "\n";
        }
    }


    return 0;
}