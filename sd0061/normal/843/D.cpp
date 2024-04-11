#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = 1000005;
typedef long long LL;

int n , m , q , pre[N] , mcnt;
struct edge {
    int x , w , next;
} e[N];
LL d[N];
int g[N];
bool v[N];

queue<int> que[N];

int main() {
    scanf("%d%d%d" , &n , &m , &q);
    memset(pre , -1 , sizeof(pre));
    for (int i = 0 ; i < m ; ++ i) {
        int x , y , z;
        scanf("%d%d%d" , &x , &y , &z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
    }
    priority_queue< pair<long long , int> > Q;
    memset(d , 0x3f , sizeof(d));
    d[1] = 0; Q.push({-d[1] , 1});
    while (!Q.empty()) {
        auto it = Q.top(); Q.pop();
        int x = it.second; if (-it.first > d[x]) continue;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (d[x] + e[i].w < d[y]) {
                d[y] = d[x] + e[i].w;
                Q.push({-d[y] , y});
            }
        }
    }
    while (q --) {
        int o , k;
        scanf("%d%d" , &o , &k);
        if (o == 1) {
            if (d[k] >= d[0]) {
                puts("-1");
            } else {
                printf("%lld\n" , d[k]);
            }
        } else {
            int w;
            for (int i = 0 ; i < k ; ++ i) {
                scanf("%d" , &w);
                e[w - 1].w ++;
            }
            memset(g , 0x3f , sizeof(g));
            g[1] = 0;
            que[0].push(1);
            int maxDis = 0 , u = min(k, n - 1);
            for (int dis = 0 ; dis <= maxDis ; ++ dis) {
                while (!que[dis].empty()) {
                    int x = que[dis].front(); que[dis].pop();
                    if (dis > g[x]) continue;
                    for (int i = pre[x] ; ~i ; i = e[i].next) {
                        int y = e[i].x , z = d[x] + e[i].w - d[y];
                        if (g[x] + z < g[y]) {
                            g[y] = g[x] + z;
                            if (g[y] <= u) {
                                maxDis = max(maxDis , g[y]);
                                que[g[y]].push(y);
                            }
                        }
                    }
                }
            }
            for (int i = 1 ; i <= n ; ++ i) {
                d[i] = min(d[0] , d[i] + g[i]);
            }
        }
    }
}