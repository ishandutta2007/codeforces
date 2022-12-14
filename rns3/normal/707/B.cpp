#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n, m, k, a[N], b[N], cost[N], x;
bool vis[N];

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i ++) scanf("%d %d %d", a + i, b + i, cost + i);
    int ans = 2000000000;
    for(int i = 0; i < k; i ++){
        scanf("%d", &x);
        vis[x] = 1;
    }
    for(int i = 0; i < m; i ++){
        if(vis[a[i]] != vis[b[i]] ) ans = min( ans, cost[i]);
    }
    if(ans == 2000000000) puts("-1");
    else printf("%d\n", ans);
}