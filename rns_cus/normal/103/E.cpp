#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e14
struct dat{
    int x, rev;
    ll f, cap;
    dat(int x = 0, int rev = 0, ll f = 0, ll cap = 0):x(x), rev(rev), f(f), cap(cap) {}
};
#define N 2100
vector<dat> v[N];
ll dist[N], fl[N];
queue<int> q;

void add(int x, int y, ll co) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, co));
    v[y].push_back(dat(x, n, 0, 0));
}



bool dinic_bfs(int n) {
    for(int i = 0; i <= n; i ++) dist[i] = inf;
    dist[0] = 0;
    while(!q.empty()) q.pop();
    q.push(0);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i ++) {
            dat aa = v[x][i];
            int y = aa.x;
            if(aa.f == aa.cap) continue;
            if(dist[y] != inf) continue;
            dist[y] = dist[x] + 1;
            q.push(y);
        }
    }
    return dist[n] != inf;
}
int work[N];

ll dinic_dfs(int sr, int de, ll f) {
    if(sr == de) return f;
    for(; work[sr] < v[sr].size(); work[sr] ++) {
        int i = work[sr];
        dat aa = v[sr][i];
        int y = aa.x;
        if(aa.f == aa.cap) continue;
        if(dist[y] != dist[sr] + 1) continue;
        ll x = dinic_dfs(y, de, min(f, aa.cap - aa.f));
        if(!x) continue;
        v[sr][i].f += x;
        v[y][aa.rev].f -= x;
        return x;
    }
    return 0;
}


ll Flow(int n) {
    ll ans = 0;
    while(dinic_bfs(n)) {
        while(1) {
            for(int i = 0; i <= n; i ++) work[i] = 0;
            ll sum1 = dinic_dfs(0, n, inf);
            if(!sum1) break;
            ans += sum1;
        }
    }
    return ans;
}

int main() {
    //freopen("103.in", "r", stdin);
    int n, x, y;
    scanf("%d", &n);
    ll val = 1ll * n * 1000000;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &x);
        for(int j = 0; j < x; j ++) {
            scanf("%d", &y);
            add(i, n + y, inf);
        }
    }
    long long sum = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &x);
        add(0, i, val - x);
        sum += val - x;
    }
    for(int i = 1; i <= n; i ++) {
        add(n + i, n * 2 + 1, val);
    }
    ll sum1 = Flow(n * 2 + 1);
    ll ans = sum1 - sum;
    printf("%I64d\n", ans);
    return 0;
}