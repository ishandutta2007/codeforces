#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n, k, p[N], dep[N], head[N], nxt[N << 1], to[N << 1], eid;
void addedge(int u, int v){
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}

int thre, sum;
int dfs(int i, int pre){
    int dist = 1;
    for(int e = head[i]; e; e = nxt[e])
        if(to[e] != pre)
            dist = max(dist, dfs(to[e], i));
    if(dep[i] > 0 && dist >= thre - 1){
        sum++;
        return 1;
    }
    return dist + 1;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        memset(head + 1, 0, sizeof(int) * n);
        eid = 1;
        dep[1] = -1;
        for (int i = 2; i <= n; i++){
            scanf("%d", &p[i]);
            addedge(p[i], i);
            dep[i] = dep[p[i]] + 1;
        }
        int l = 2, r = n;
        while(l < r){
            int mid = (l + r) >> 1;
            thre = mid;
            sum = 0;
            dfs(1, 0);
            if(sum <= k)
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", l - 1);
    }
    return 0;
}