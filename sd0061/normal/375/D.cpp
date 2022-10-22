#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int N = 100002;
typedef unsigned long long ULL;
int n , m , pre[N] , mcnt , c[N];
int M , sq[N];
struct edge
{
    int x , next;
}e[N << 1];
int L[N] , R[N] , ncnt;
void dfs(int x , int fa)
{
    L[x] = ++ ncnt , sq[ncnt] = c[x];
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != fa)
            dfs(e[i].x , x);
    R[x] = ncnt;
}
struct query
{
  int l , r ,  k , id;
  bool operator < (const query& p) const{
    int ll = l / M , rr = p.l / M;
    if (ll != rr) return ll < rr;
    return r < p.r;  }
}q[N];
int ans[N] , cnt[N];
int D , d[N];

void work()
{
    int i , x , y , l , r;
    scanf("%d%d",&n,&m);
    M = sqrt(n);
    for (i = 1 ; i <= n; ++ i)
        scanf("%d",&c[i]) , d[D ++] = c[i];
    sort(d , D + d);
    D = unique(d , D + d) - d;
    for (i = 1 ; i <= n; ++ i)
        c[i] = lower_bound(d , d + D , c[i]) - d;
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0);
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d",&x,&y);
        q[i] = (query) {L[x] , R[x] , y , i};
    }
    sort(q + 1 , q + m + 1);
    memset(cnt , 0 , sizeof(cnt));
    memset(c , 0 , sizeof(c));
    l = 1 , r = 0 , c[0] = D;
    for (i = 1 ; i <= m ; ++ i)
    {
        x = q[i].l , y = q[i].r;
        while (l < x)
        {
            -- c[cnt[sq[l]]];
            -- cnt[sq[l]];
            ++ l;
        }
        while (l > x)
        {
            -- l;
            ++ cnt[sq[l]];
            ++ c[cnt[sq[l]]];
        }
        while (r < y)
        {
            ++ r;
            ++ cnt[sq[r]];
            ++ c[cnt[sq[r]]];
        }
        while (r > y)
        {
            -- c[cnt[sq[r]]];
            -- cnt[sq[r]];
            -- r;
        }
        ans[q[i].id] = c[q[i].k];
    }
    for (i = 1 ; i <= m ; ++ i)
        printf("%d\n" , ans[i]);
}

int main()
{
//    freopen("1.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
//    while (scanf("%d%d",&n,&k) , n || k)
        work();
    return 0;
}