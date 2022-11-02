#include <bits/stdc++.h>
using namespace std;

#define N 6015
#define M 9100000

struct min_cost_max_flow {
    #define inf 168430090
    int n, st, en, tot, flowTot;
    int b[M], c[M], w[M], nxt[M];
    int head[N], pre[N], p[N], d[N];
    queue<int> q;
    void init(int _n, int _st, int _en){
        memset(head, 0, sizeof(head));
        tot = 1;
        st = _st; en = _en;
        n = _n;
        flowTot = 0;
    }
    void add(int x,int y,int z,int cost){
        b[++tot] = y; c[tot] = z; w[tot] = cost; nxt[tot] = head[x]; head[x] = tot;
        b[++tot] = x; c[tot] = 0; w[tot] = -cost; nxt[tot] = head[y]; head[y] = tot;
    }
    int push_flow(){
        int x = en, flow = inf;
        while (x != st){
            flow = min(flow, c[pre[x]]);
            x = b[pre[x] ^ 1];
        }
        x = en;
        while (x != st){
            c[pre[x]] -= flow; c[pre[x]^1] += flow;
            x = b[pre[x] ^ 1];
        }
        flowTot += flow;
        return flow * d[en];
    }
    int spfa(){
        memset(d, 10, sizeof(d));
        memset(p, 0, sizeof(p));
        q.push(st); p[st] = 1; d[st] = 0;
        while (!q.empty()){
            int x = q.front(); q.pop();
            p[x] = 0;
            for (int go = head[x]; go; go = nxt[go])
                if (c[go] && d[b[go]] > d[x] + w[go]){
                    d[b[go]] = d[x] + w[go];
                    pre[b[go]] = go;
                    if (p[b[go]] == 0){
                        p[b[go]] = 1;
                        q.push(b[go]);
                    }
                }
        }
        return d[en] < inf;
    }
    int min_cost(){ // return cost
        int ans = 0;
        while (spfa()) ans += push_flow();
        return ans;
    }
} mcmf;

int n;
int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    int src = 2 * n + 2, dst = 2 * n + 3;
    mcmf.init(2 * n + 3, src, dst);
    for (int i = 1; i <= n; i ++) {
        int x1 = 0, x2 = 0, x3 = 0;
        for (int j = i + 1; j <= n; j ++) {
            bool fg = 0;
            if (a[j] == a[i] + 1) { if (x1 >= 4) continue; x1 ++, fg = 1; }
            else if (a[j] == a[i] - 1) { if (x2 >= 4) continue; x2 ++, fg = 1; }
            else if ((a[j] - a[i]) % 7 == 0) {if (x3 >= 4) continue; x3 ++, fg = 1; }
            if (fg) mcmf.add(2 * i, 2 * j - 1, 1, 0);
        }
    }
    for (int i = 1; i <= n; i ++) {
        mcmf.add(2 * i - 1, 2 * i, 1, -1);
        mcmf.add(0, 2 * i - 1, 1, 0);
        mcmf.add(2 * i, 2 * n + 1, 1, 0);
    }
    mcmf.add(src, 0, 4, 0);
    mcmf.add(2 * n + 1, dst, 4, 0);
    printf("%d\n", -mcmf.min_cost());
    return 0;
}