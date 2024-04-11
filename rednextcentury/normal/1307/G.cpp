#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 60
#define M 7000
const ll INF = 1e15;
int n, m, p;
ll top, head[N], to[M], nxt[M], c[M], l[M];
void addedge(int u, int v, int cap, int len) {
    to[top] = v, nxt[top] = head[u], c[top] = cap, l[top] = len, head[u] = top++;
}
vector<pair<int, int >> paths;
ll dis[N], fa[N];
bool inque[N];
bool go() {
    int source = 0, target = n-1;
    for (int i = 0; i < n; ++i) {
        dis[i] = INF;
    }
    dis[source] = 0;
    inque[source] = true;
    queue<int> q;
    q.push(source);
    while (q.size()) {
        int u = q.front();
        inque[u] = false;
        q.pop();
        for (int i = head[u]; ~i; i = nxt[i]) {
            if (c[i]) {
                int v = to[i]; ll nd = dis[u] + l[i];
                if (dis[v] > nd) {
                    dis[v] = nd;
                    fa[v] = i;
                    if (!inque[v]) {
                        inque[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    if (dis[target] == INF) {
        return false;
    }
    ll f = INF;
    int u = target;
    while (u != source) {
        ll e = fa[u];
        f = min(f, c[e]);
        u = to[e ^ 1];
    }
    paths.push_back(make_pair(f, dis[target]));
    u = target;
    while (u != source) {
        int e = fa[u];
        c[e] -= f, c[e ^ 1] += f;
        u = to[e ^ 1];
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    top = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        addedge(u-1, v-1, 1, d);
        addedge(v-1, u-1, 0, -d);
    }
    while(1){
        if (!go())break;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&p);
        ll csum = 0, fsum = 0;
        for (int i = 0; i < (int) paths.size(); ++i) {
            csum += paths[i].first * paths[i].second;
            fsum += paths[i].first;
            double ans = (double) (p + csum) / fsum;
            if (i + 1 == paths.size() || ans < paths[i + 1].second) {
                printf("%.12f\n", ans);
                break;
            }
        }
    }

    return 0;
}