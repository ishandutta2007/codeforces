#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n, m;

vector<pair<int, int> > graph[205];
int dist[205];
bool inque[205];
int U[2005], V[2005], B[2005];
vector<int> cgraph[205];
int cdeg[205];
int ansdist[205][205];
int rcnt[205];

bool has_cycle(void)
{
    queue<int> topo;
    int remain = n;
    for (int i = 1; i <= n; i++) {
        if (!cdeg[i]) {
            topo.push(i); remain--;
        }
    }
    while (!topo.empty()) {
        int node = topo.front(); topo.pop();
        for (int i = 0; i < cgraph[node].size(); i++) {
            int nxt = cgraph[node][i];
            cdeg[nxt]--;
            if (!cdeg[nxt]) {
                topo.push(nxt);
                remain--;
            }
        }
    }
    return remain > 0;
}

queue<int> spfa;

void SPFA()
{
    for (int i = 1; i <= n; i++) rcnt[i] = 0;
    while (!spfa.empty()) {
        int cur = spfa.front(); spfa.pop();
        inque[cur] = false;
        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i].first;
            int newd = dist[cur] + graph[cur][i].second;
            if (newd < dist[nxt]) {
                dist[nxt] = newd;
                rcnt[nxt]++;
                if (rcnt[nxt] > n) {
                    printf("NO"); exit(0);
                }
                if (!inque[nxt]) {
                    spfa.push(nxt);
                    inque[nxt] = true;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, b; scanf("%d%d%d", &u, &v, &b);
        U[i] = u; V[i] = v; B[i] = b;
        if (b == 0) {
            graph[u].push_back(make_pair(v, 1));
            graph[v].push_back(make_pair(u, 1));
        } else {
            graph[u].push_back(make_pair(v, 1));
            graph[v].push_back(make_pair(u, -1));
            cgraph[u].push_back(v); cdeg[v]++;
        }
    }
    if (has_cycle()) {
        printf("NO"); return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[j] = 1000000;
        dist[i] = 0;
        spfa.push(i);
        SPFA();
        for (int j = 1; j <= n; j++) ansdist[i][j] = dist[j];
    }

    int max_ineq = 0;
    int max_origin = 0;
    for (int i = 1; i <= n; i++) {
        int maxv = -1000000, minv = 1000000;
        for (int j = 1; j <= n; j++) {
            maxv = max(maxv, ansdist[i][j]);
            minv = min(minv, ansdist[i][j]);
        }
        if (maxv - minv > max_ineq) {
            max_ineq = maxv - minv;
            max_origin = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        int dif = dist[V[i]] - dist[U[i]];
        if (B[i] == 1 && dif != 1) {
            printf("NO"); return 0;
        }
        if (dif != 1 && dif != -1) {
            printf("NO"); return 0;
        }
    }
    printf("YES\n");
    printf("%d\n", max_ineq);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ansdist[max_origin][i] + 500000);
    }
    return 0;
}