#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e15;
const int N = 1e6 + 34;

ll d[N];
int v1, v2, v, n, m, c;
bool u[N];
priority_queue<pair<ll, ll> > q;
vector <int> es[N], w[N];
int pr[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &v1, &v2, &c);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
        w[v1].push_back(c);
        w[v2].push_back(c);
    }
    q.push(make_pair(0, 0));
    for (int i = 1; i < n; i++)
        d[i] = INF;
    while (!q.empty()) {
        v = q.top().second;
        q.pop();
        if (u[v]) continue;
        if (d[v] == INF) break;
        u[v] = true;
        for (int i = 0; i < es[v].size(); i++) {
            v2 = es[v][i];
            if (d[v2] > d[v] + w[v][i]) {
                d[v2] = d[v] + w[v][i];
                pr[v2] = v;
                q.push(make_pair(-d[v2], v2));
            }
        }
    }
    if (d[n - 1] == INF) {
        cout << -1;
        return 0;
    }
    vector <int> path;
    --n;
    while (n != 0) {
        path.push_back(n);
        n = pr[n];
    }
    path.push_back(0);
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] + 1 << " ";
}