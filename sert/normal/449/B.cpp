#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll INF = 1e18 + 41;
priority_queue <pair<ll, int> > q;
vector <pair<int, int> > es[N];
ll d[N];
int v, ans, n, m, k, v1, v2, c;
bool u[N], zd[N], nid;

int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &v1, &v2, &c);
        v1--;
        v2--;
        es[v1].push_back(make_pair(v2, c));
        es[v2].push_back(make_pair(v1, c));
    }
    for (int i = 0; i < n; i++)
        d[i] = INF;

    for (int i = 0; i < k; i++) {
        scanf("%d%d", &v1, &c);
        ans++;
        v1--;
        zd[v1] = true;
        d[v1] = min(d[v1], (ll)c);
    }

    d[0] = 0;
    
    for (int i = 0; i < n; i++)
        if (d[i] != INF)
            q.push(make_pair(-d[i], i));

    while (!q.empty()) {
        v = q.top().second;
        q.pop();

        if (u[v]) continue;
        u[v] = true;

        for (pair<int, int> w: es[v]) {
            if (d[w.first] >= d[v] + w.second) {
                d[w.first] = d[v] + w.second;
                q.push(make_pair(-d[w.first], w.first));
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (!zd[i]) continue;
        nid = true;
        for (pair<int, int> w: es[i]) {
            if (d[w.first] + w.second == d[i])
                nid = false;
        }
        if (nid)
            ans--;
    }

    printf("%d", ans);

    return 0;
}