#include <bits/stdc++.h>
using namespace std;
#define N 1100

struct dat{
    int to, rev, f, cap;
    dat(int to = 0, int rev = 0, int f = 0, int cap = 0):to(to), rev(rev), f(f), cap(cap){}
};

vector<dat> v[N];
int dist[N], p[N], we[N], flag[N], vis[N], work[N];
queue<int> q;
#define inf 10100000
typedef pair<int, int> pi;

priority_queue<pi> pq;

void add(int x, int y, int z) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, z));
    v[y].push_back(dat(x, n, 0, z));
}


int n, m;

void init() {
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < (int) v[i].size(); j ++) v[i][j].f = 0;
    }
}

int so, de;

bool dinic_bfs() {
    for(int i = 1; i <= n; i ++) dist[i] = inf;
    dist[so] = 0;
    while(!q.empty()) q.pop();
    q.push(so);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < (int) v[x].size(); i ++) {
            if(v[x][i].f == v[x][i].cap) continue;
            int y = v[x][i].to;
            if(dist[y] != inf) continue;
            dist[y] = dist[x] + 1;
            q.push(y);
        }
    }
    return dist[de] != inf;
}

int dinic_dfs(int x, int f) {
    if(x == de) return f;
    for(; work[x] < (int) v[x].size(); work[x] ++) {
        dat a = v[x][work[x]];
        if(a.f == a.cap) continue;
        int y = a.to;
        if(dist[y] != dist[x] + 1) continue;
        int d = dinic_dfs(y, min(f, a.cap - a.f));
        if(!d) continue;
        v[x][work[x]].f += d;
        v[y][a.rev].f -= d;
        return d;
    }
    return 0;
}

int doit() {
    int mx = 0;
    while(dinic_bfs()) {
        for(int i = 1; i <= n; i ++) work[i] = 0;
        while(1) {
            int d = dinic_dfs(so, inf);
            if(!d) break;
            mx += d;
        }
    }
    return mx;
}


void dfs(int x) {
    flag[x] = 1;
    for(int i = 0; i < (int) v[x].size(); i ++) {
        if(v[x][i].f == v[x][i].cap) continue;
        int y = v[x][i].to;
        if(!flag[y]) dfs(y);
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    for(int i = 1; i <= n; i ++) p[i] = 1;
    int ans = 0;
    for(int i = 2; i <= n; i ++) {
        so = i;
        de = p[i];
        init();
        we[i] = doit();
        ans += we[i];
        for(int j = 1; j <= n; j ++) flag[j] = 0;
        dfs(i);
        for(int j = i + 1; j <= n; j ++) if(p[i] == p[j] && flag[j]) p[j] = i;
    }
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    printf("%d\n", ans);
    printf("%d", 1);
    vis[1] = 1;
    for(int i = 2; i <= n; i ++) if(p[i] == 1) pq.push(pi(we[i], i));
    while(!pq.empty()) {
        int x = pq.top().second;
        vis[x] = 1;
        printf(" %d", x);
        pq.pop();
        for(int i = 1; i <= n; i ++) if(!vis[i] && p[i] == x) pq.push(pi(we[i], i));
    }
    puts("");

}