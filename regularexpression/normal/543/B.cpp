#include <bits/stdc++.h>
using namespace std;

const int N = 3005, INF = 1e9 + 239;
int n, m;
vector<int> g[N];

vector<int> dist(int st) {
    vector<int> d(n, INF);
    queue<int> q;
    d[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (d[v] + 1 < d[u]) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    s1--;
    t1--;
    s2--;
    t2--;
    vector<vector<int>> d(n);
    for (int i = 0; i < n; ++i) d[i] = dist(i);
    if (d[s1][t1] > l1 || d[s2][t2] > l2) {
        cout << "-1\n";
        return 0;
    }
    int ans = d[s1][t1] + d[s2][t2];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int d1 = d[s1][i] + d[i][j] + d[j][t1], d2 = d[s2][i] + d[i][j] + d[j][t2];
            if (d1 <= l1 && d2 <= l2) ans = min(ans, d1 + d2 - d[i][j]);
            swap(s1, t1);
            d1 = d[s1][i] + d[i][j] + d[j][t1], d2 = d[s2][i] + d[i][j] + d[j][t2];
            if (d1 <= l1 && d2 <= l2) ans = min(ans, d1 + d2 - d[i][j]);
        }
    }
    cout << m - ans;
    return 0;
}