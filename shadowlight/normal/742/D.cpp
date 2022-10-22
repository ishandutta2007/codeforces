#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

vector <int> r, p;

void create(int v) {
    r[v] = 0;
    p[v] = v;
}

int get_root(int v) {
    if (p[v] == v) return v;
    return p[v] = get_root(p[v]);
}

void unite(int v, int u) {
    u = get_root(u);
    v = get_root(v);
    if (r[v] > r[u]) swap(v, u);
    if (r[v] == r[u]) r[u]++;
    p[v] = u;
}

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    p.resize(n);
    r.resize(n);
    for (int i = 0; i < n; i++) {
        create(i);
    }
    vector <int> w1(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> w1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        unite(x, y);
    }
    vector <vector <int> > comps;
    for (int i = 0; i < n; i++) {
        if (get_root(i) != i) continue;
        comps.push_back(vector <int> (0));
        for (int j = 0; j < n; j++) {
            if (get_root(j) == i) {
                comps.back().push_back(j);
            }
        }
    }
    int k = comps.size();
    /*for (int i = 0; i < k; i++) {
        for (int j = 0; j < comps[i].size(); j++) {
            cout << comps[i][j] << " ";
        }
        cout << endl;
    }*/
    vector <vector <int> > dp(k + 1, vector <int> (w + 1, -1));
    dp[0][0] = 0;
    int maxk = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= w; j++) {
            if (dp[i - 1][j] == -1) continue;
            int sum1 = 0, sum2 = 0;
            for (int l = 0; l < comps[i - 1].size(); l++) {
                int u = comps[i - 1][l];
                sum1 += w1[u];
                sum2 += b[u];
                if (w1[u] + j > w) continue;
                dp[i][w1[u] + j] = max(dp[i][w1[u] + j], dp[i - 1][j] + b[u]);
            }
            if (j + sum1 <= w) {
                dp[i][sum1 + j] = max(dp[i - 1][j] + sum2, dp[i][sum1 + j]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    for (int i = 0; i <= w; i++) {
        maxk = max(maxk, dp[k][i]);
    }
    cout << maxk;
}