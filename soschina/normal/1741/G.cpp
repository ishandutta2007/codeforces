#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int N = 1e4 + 1, K = 6;

int t, n, m, head[N], nxt[N << 1], to[N << 1], eid;
void addedge(int u, int v){
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}

int f, h[N], k, p[N];
int val[N], dist[N];
bool foo[N][1 << K], dp[N][1 << K];

int main(){
    scanf("%d", &t);
    while(t--){
        eid = 1;
        memset(head + 1, 0, sizeof(int) * n);
        memset(val + 1, 0, sizeof(int) * n);
        scanf("%d%d", &n, &m);
        while(m--){
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        scanf("%d", &f);
        for (int i = 1; i <= f; i++)
            scanf("%d", &h[i]);
        scanf("%d", &k);
        for (int i = 0; i < k; i++){
            scanf("%d", &p[i]);
            val[h[p[i]]] |= 1 << i;
            h[p[i]] = 0;
        }
        memset(foo + 1, 0, sizeof(bool) * (1 << K) * n);
        memset(dist + 1, 0x3f, sizeof(int) * n);
        foo[1][val[1]] = true;
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for (int e = head[i]; e; e = nxt[e]){
                if(dist[to[e]] > dist[i] + 1){
                    dist[to[e]] = dist[i] + 1;
                    q.push(to[e]);
                }
                if(dist[to[e]] == dist[i] + 1)
                    for (int s = 0; s < (1 << k); s++)
                        foo[to[e]][s | val[to[e]]] |= foo[i][s];
            }
        }
        while(f && !h[f])
            f--;
        memset(dp + 1, 0, sizeof(bool) * (1 << K) * f);
        dp[0][0] = true;
        for (int i = 1; i <= f; i++){
            if(h[i]){
                for (int s = 0; s < (1 << k); s++)
                    if(dp[i - 1][s])
                        for (int t = 0; t < (1 << k); t++)
                            if(foo[h[i]][t])
                                dp[i][s | t] = true;
            }
            else
                for (int s = 0; s < (1 << k); s++)
                    dp[i][s] = dp[i - 1][s];
        }
        int ans = 0;
        for (int i = 0; i < (1 << k); i++)
            if(dp[f][i])
                ans = max(ans, __builtin_popcount(i));
        printf("%d\n", k - ans);
    }
    return 0;
}