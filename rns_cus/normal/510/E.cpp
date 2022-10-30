#include <bits/stdc++.h>
using namespace std;

#define N 21000
struct dat{
    int to, rev, f, cap;
    dat(int to = 0, int rev = 0, int f = 0, int cap = 0):to(to), rev(rev), f(f), cap(cap) {}
};

vector<dat> v[N];
vector<int> arr[N];
int dist[N], work[N], vis[N], pa[N], A[N][10], deg[N], a[N];
queue<int> q;
#define inf 10100000
typedef pair<int, int> pi;

void add(int x, int y, int cap) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, cap));
    v[y].push_back(dat(x, n, 0, 0));
}

int n;

bool dinic_bfs() {
    for(int i = 0; i <= n + 1; i ++) dist[i] = inf;
    dist[0] = 0;
    while(!q.empty()) q.pop();
    q.push(0);
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
    return dist[n + 1] != inf;
}

int dinic_dfs(int x, int f) {
    if(x == n + 1) return f;
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

int main() {
    //freopen("1.in", "r", stdin);
    vis[1] = 1;
    for(int i = 2; i <= N; i ++) if(!vis[i]) {
        for(int j = 2; j * i <= N; j ++) vis[i * j] = 1;
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int so = 0;
    int de = n + 1;
    for(int i = 1; i <= n; i ++) {
        if(a[i] % 2 == 0) {
            add(so, i, 2);
            for(int j = 1; j <= n; j ++) {
                if(vis[a[i] + a[j]]) continue;
                add(i, j, 1);
            }
        } else add(i, de, 2);
    }
    int ans = 0;
    while(dinic_bfs()) {
        for(int i = 0; i <= n + 1; i ++) work[i] = 0;
        int d = dinic_dfs(so, inf);
        if(!d) break;
        ans += d;
    }
    if(ans != n) {
        puts("Impossible");
        return 0;
    }
    for(int i = 1; i <= n; i ++) for(int j = 0; j < v[i].size(); j ++) {
        dat aa = v[i][j];
        if(aa.cap != 1) continue;
        if(aa.f != aa.cap) continue;
        int x = aa.to;
        A[i][deg[i] ++] = x;
        A[x][deg[x] ++] = i;
    }



    for(int i = 1; i <= n; i ++) vis[i] = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i ++) if(!vis[i]) {
        vis[i] = 1;
        ++cnt;
        arr[cnt].clear();
        int x = i;
        while(1) {
            arr[cnt].push_back(x);
            bool ok = false;
            for(int j = 0; j < deg[x]; j ++) {
                int y = A[x][j];
                if(vis[y]) continue;
                ok = true;
                vis[y] = 1;
                x = y;
                break;
            }
            if(!ok) break;
        }
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= cnt; i ++) {
        printf("%d", arr[i].size());
        for(int j = 0; j < (int) arr[i].size(); j ++) printf(" %d", arr[i][j]);
        puts("");
    }
    return 0;

}