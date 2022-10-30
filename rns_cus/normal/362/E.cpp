#include <bits/stdc++.h>
using namespace std;
#define N 110
struct dat{
    int to, rev, f, cap;
    dat(int to = 0, int rev = 0, int f = 0, int cap = 0):to(to), rev(rev), f(f), cap(cap) {}
};

vector<dat> v[N];
int dist[N], work[N], vis[N], pa[N];
int f[N][N];
queue<int> q;
#define inf 10100000
typedef pair<int, int> pi;

void add(int x, int y, int cap) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, cap));
    v[y].push_back(dat(x, n, 0, 0));
    f[x][y] = n;
}



int n;
bool dinic_bfs() {
    for(int i = 1; i <= n; i ++) dist[i] = inf;
    dist[1] = 0;
    while(!q.empty()) q.pop();
    q.push(1);
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
    return dist[n] != inf;
}

int dinic_dfs(int x, int f) {
    if(x == n) return f;
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

priority_queue<pi> p;

int main() {
    //freopen("1.in", "r", stdin);
    int K;
    scanf("%d%d", &n, &K);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int x;
            scanf("%d", &x);
            if(x) add(i, j, x);
        }
    }
    int ans = 0;
    while(1) {
        int xx = 0;
        while(dinic_bfs()) {
            for(int i = 1; i <= n; i ++) work[i] = 0;
            int d = dinic_dfs(1, inf);
            if(!d) break;
            ans += d;
            xx += d;
        }
        for(int i = 1; i <= n; i ++) dist[i] = inf;
        dist[1] = 0;
        while(!p.empty()) p.pop();
        p.push(pi(0, 1));
        while(!p.empty()) {
            pi aa = p.top();
            int x = aa.second;
            p.pop();
            if(-aa.first != dist[x]) continue;
            for(int i = 0; i < v[x].size(); i ++) {
                int bf = 0;
                if(v[x][i].cap == 0 && v[x][i].f == 0) continue;
                if(v[x][i].cap == v[x][i].f) bf ++;
                int y = v[x][i].to;
                if(dist[y] > dist[x] + bf) {
                    dist[y] = dist[x] + bf;
                    pa[y] = x;
                    p.push(pi(-dist[y], y));
                }
            }
        }
        int En = n;
        if(dist[En] > K) break;
        K -= dist[En];
        while(En > 1) {
            int xx = pa[En];
            if(dist[En] == dist[xx]) {
                En = xx;
                continue;
            }
            int yy = f[xx][En];
            v[xx][yy].cap ++;
            En = xx;
        }
    }
    printf("%d\n", ans);
    return 0;
}