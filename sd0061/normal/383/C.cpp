#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define N 200005

int n , m , a[N] , d[N] , pre[N] , mcnt , ncnt;
int L[N] , R[N];
struct edge
{
    int x , next;
}e[N << 1];
void dfs(int x , int F , int dep)
{
    L[x] = ++ ncnt ,  d[x] = dep;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != F)
            dfs(e[i].x , x , dep ^ 1);
    R[x] = ncnt;
}
int c[2][N];
void add(int s , int x , int w)
{
    for (int i = x ; i <= n ; i += i & -i)
        c[s][i] += w;
}
int sum(int s , int x)
{
    int res = 0;
    for (int i = x ; i > 0 ; i -= i & -i)
        res += c[s][i];
    return res;
}

void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" ,&a[i]);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0 , 1);

    while (m --)
    {
        scanf("%d",&j);
        if (j == 1)
        {
            scanf("%d%d",&x , &y);
            add(d[x] , L[x] , y);
            add(d[x] , R[x] + 1 , -y);
            add(!d[x] , L[x] , -y);
            add(!d[x] , R[x] + 1 , y);
        }
        else
        {
            scanf("%d",&x);
            printf("%d\n" , a[x] + sum(d[x] , L[x]));
        }
    }
}

int main()
{
    work();
    return 0;
}