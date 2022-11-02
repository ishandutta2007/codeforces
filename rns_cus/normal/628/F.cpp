#include <bits/stdc++.h>
using namespace std;

#define N 31000

struct dat{
    int to, rev, f, cap;
    dat(int to = 0, int rev = 0, int f = 0, int cap = 0):to(to), rev(rev), f(f), cap(cap){}
};

vector<dat> v[N];
int dist[N], we[N], work[N];
queue<int> q;
#define inf 10100000
typedef pair<int, int> pi;
pi p[N];

priority_queue<pi> pq;

void add(int x, int y, int z) {
    //if(z) printf("%d %d %d\n", x, y, z);
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, z));
    v[y].push_back(dat(x, n, 0, 0));
}


int n, m;

void init() {
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < (int) v[i].size(); j ++) v[i][j].f = 0;
    }
}

int so, de;

bool dinic_bfs() {
    for(int i = 1; i <= de; i ++) dist[i] = inf;
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
        for(int i = 0; i <= de; i ++) work[i] = 0;
        while(1) {
            int d = dinic_dfs(so, inf);
            if(!d) break;
            mx += d;
        }
    }
    return mx;
}

int main() {
    //freopen("1.in", "r", stdin);
    int n, B, Q;
    scanf("%d%d%d", &n, &B, &Q);
    p[0] = pi(0, 0);
    p[Q + 1] = pi(B, n);
    for(int i = 1; i <= Q; i ++) scanf("%d%d", &p[i].first, &p[i].second);
    bool ok = true;
    Q += 2;
    sort(p, p + Q);
    Q = unique(p, p + Q) - p;
    for(int i = 1; i < Q; i ++) if(p[i].second - p[i - 1].second > p[i].first - p[i - 1].first || p[i].second < p[i - 1].second) {
        ok = false;
        break;
    }
    if(!ok) {
        puts("unfair");
        return 0;
    }
    so = 0;
    int mm = B + Q;
    de = mm + 5;
    for(int i = 0; i < 5; i ++) add(so, mm + i, n / 5);
    for(int i = 1; i <= B; i ++) add(mm + (i % 5), i, 1);
    for(int i = 1; i < Q; i ++) {
        for(int j = p[i - 1].first + 1; j <= p[i].first; j ++) {
            add(j, B + i, 1);
        }
        add(B + i, de, p[i].second - p[i - 1].second);
    }
    int kk = doit();
    if(kk == n) {
        puts("fair");
    } else puts("unfair");
    return 0;

}