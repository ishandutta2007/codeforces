#include <bits/stdc++.h>
using namespace std;
#define N 31000
struct dat{
    int x, rev, f, cap;
    dat(int x = 0, int rev = 0, int f = 0, int cap = 0):x(x), rev(rev), f(f), cap(cap){}
};

vector<dat> v[N];
queue<int> q;
int dist[N], work[N], se[N];
#define inf 1e9
void add(int x, int y, int c) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, c));
    v[y].push_back(dat(x, n, 0, 0));
}

int so, de;
bool bfs() {
    for(int i = 0; i <= de; i ++) dist[i] = inf;
    dist[0] = 0;
    while(!q.empty()) q.pop();
    q.push(0);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i ++) {
            dat aa = v[x][i];
            if(aa.f == aa.cap) continue;
            int y = aa.x;
            if(dist[y] > dist[x] + 1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    return dist[de] != inf;
}

int dfs(int x, int f) {
    if(x == de) return f;
    for(work[x]; work[x] < v[x].size(); work[x] ++) {
        int i = work[x];
        dat aa = v[x][i];
        if(aa.f == aa.cap) continue;
        int y = aa.x;
        if(dist[y] != dist[x] + 1) continue;
        int d = dfs(y, min(f, aa.cap - aa.f));
        if(!d) continue;
        v[x][i].f += d;
        v[y][aa.rev].f -= d;
        return d;
    }
    return 0;
}

int main() {
    //freopen("1.in", "r", stdin);
    int n, m, g;
    scanf("%d%d%d", &n, &m, &g);
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &se[i]);
    }
    so = 0;
    de = n + m + 1;
    int val = 20000;
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        if(se[i]) add(i, de, val), add(so, i, val - x);
        else add(i, de, val - x), add(so, i, val);
        sum += val;
        sum += val - x;
    }
    int ans = 0;
    for(int i = 1; i <= m; i ++) {
        int ty, x, k, y, ok;
        scanf("%d", &ty);
        scanf("%d", &x);
        scanf("%d", &k);
        for(int j = 0; j < k; j ++) {
            scanf("%d", &y);
            if(!ty) add(n + i, y, inf);
            else add(y, n + i, inf);
        }
        scanf("%d", &ok);
        if(ok) x += g, ans -= g;
        sum += x;
        if(!ty) add(so, n + i, x);
        else add(n + i, de, x);
    }
    int ans1 = 0;
    while(bfs()) {
        for(int i = 0; i <= de; i ++) work[i] = 0;
        while(1) {
            int d = dfs(so, inf);
            if(!d) break;
            ans1 += d;
        }
    }
    sum -= ans1;
    sum -= val * n;
    ans += sum;
    printf("%d\n", ans);
    return 0;
}