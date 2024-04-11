#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
LL a[N];
LL mx[N] , mn[N];

void dfs(int x , int fa) {
    mx[x] = mn[x] = 0;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x);
            mx[x] = max(mx[x] , mx[y]);
            mn[x] = max(mn[x] , mn[y]);           
        }
    }
    a[x] = a[x] - mx[x] + mn[x];
    if (a[x] > 0)
        mx[x] += a[x];
    else
        mn[x] -= a[x];                                                  
}

void work() {
    int i , x , y;
    memset(pre , -1 , sizeof(pre));
    scanf("%d",&n);
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    for (i = 1 ; i <= n ; ++ i)
        scanf("%lld" , &a[i]);
    dfs(1 , 0);
    cout << mx[1] + mn[1] << endl;
}

int main() {
    work();
    return 0;
}