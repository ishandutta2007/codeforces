#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000

int S, T;

struct dat{
    int to, rev, f, cap;
    dat(int to = 0, int rev = 0, int f = 0, int cap = 0):to(to), rev(rev), f(f), cap(cap){}
};

#define N 11000
vector<dat> v[N];

int a[N], b[N], c[N], l[N], r[N], st[N];

int dist[N];
queue<int> q;

int work[N];

void add(int x, int y, int cap) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, cap));
    v[y].push_back(dat(x, n, 0, 0));
}


bool bfs() {
    for(int i = 0; i <= T; i ++) dist[i] = inf;
    while(!q.empty()) q.pop();
    q.push(S);
    dist[S] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i ++) {
            dat aa = v[x][i];
            if(aa.f == aa.cap) continue;
            int y = aa.to;
            if(dist[y] != inf) continue;
            dist[y] = dist[x] + 1;
            q.push(y);
        }
    }
    return dist[T] != inf;
}

int dfs(int x, int f) {
    if(x == T) return f;
    for(; work[x] < v[x].size(); work[x] ++) {
        dat aa = v[x][work[x]];
        if(aa.f == aa.cap) continue;
        int y = aa.to;
        if(dist[y] != dist[x] + 1) continue;
        int d = dfs(y, min(f, aa.cap - aa.f));
        if(d) {
            v[x][work[x]].f += d;
            v[y][aa.rev].f -= d;
            return d;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    T = 0;
    S = 0;
    int val = 400000;
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d", &l[i], &r[i]);
        ++ T;
        st[i] = T;
        add(S, T, inf);
        for(int j = l[i]; j <= r[i]; j ++) {
            int xx = a[i] * j * j + b[i] * j + c[i];
            add(T, T + 1, val - xx);
            T ++;
        }
    }
    ++ T;
    for(int i = 1; i <= n; i ++) {
        add(st[i] + r[i] - l[i] + 1, T, inf);
    }
    for(int i = 1; i <= m; i ++) {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        for(int j = l[x]; j <= r[x]; j ++) {
            int xx = j - d;
            if(xx >= l[y] && xx <= r[y] + 1) {
                add(st[x] + j - l[x], st[y] + xx - l[y], inf);
            }
        }
    }
    int ans = val * n;
    while(bfs()) {
        for(int i = 0; i <= T; i ++) work[i] = 0;
        while(1) {
            int d = dfs(S, inf);
            if(!d) break;
            ans -= d;
        }
    }
    printf("%d\n", ans);
    return 0;
}