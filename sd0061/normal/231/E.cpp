#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define N 100005
int n , m , pre[N] , mcnt , Q = 1e9 + 7;
pair<int , int> E[N];
struct edge
{
    int x , next;
}e[N << 1];
int id[N] , ncnt , cnt[N] , dep[N] , F[17][N] , val[N] , p[N];
bool f[N];
stack<int> S;
void dfs(int x , int fa)
{
    S.push(x) , f[x] = 1;
    for (int i = pre[x] , j ; ~i ; i = e[i].next)
        if (e[i].x != fa && !id[e[i].x])
        {
            int y = e[i].x;
            if (!f[y])
                dfs(y , x);
            else
            {
                ++ ncnt;
                do
                {
                    j = S.top() , S.pop();
                    id[j] = ncnt , ++ cnt[ncnt];
                }while (j != y);
            }
        }
    if (!S.empty() && S.top() == x)
        id[S.top()] = ++ ncnt , cnt[ncnt] = 1 , S.pop();
}

void DFS(int x , int fa)
{
    dep[x] = dep[fa] + 1 , F[0][x] = fa , val[x] = val[fa] + (cnt[x] > 2);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != fa)
            DFS(e[i].x , x);
}

int LCA(int x , int y)
{
    if (dep[x] < dep[y]) swap(x , y);
    for (int i = 16 ; i >= 0 ; -- i)
        if (dep[x] - dep[y] >> i & 1)
            x = F[i][x];
    if (x == y) return y;
    for (int i = 16 ; i >= 0 ; -- i)
        if (F[i][x] != F[i][y])
            x = F[i][x] , y = F[i][y];
    return F[0][x];
}

void work()
{
    int i , j , x , y , z;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    p[0] = 1;
    for (i = 1 ; i <= n ; ++ i)
        p[i] = (p[i - 1] + p[i - 1]) % Q;
    for (i = 0 ; i < m ; ++ i)
    {
        scanf("%d%d",&x,&y) , E[i] = make_pair(x , y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 0 ; i < m ; ++ i)
    {
        x = id[E[i].first] , y = id[E[i].second];
        if (x == y) continue;
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    DFS(1 , 0);
    for (j = 1 ; 1 << j < ncnt ; ++ j)
        for (i = 1 ; i <= ncnt ; ++ i)
            F[j][i] = F[j - 1][F[j - 1][i]];
    scanf("%d",&m);
    while (m --)
    {
        scanf("%d%d",&x,&y);
        x = id[x] , y = id[y] , z = LCA(x , y);
        printf("%d\n" , p[val[x] + val[y] - val[z] - val[z] + (cnt[z] > 2)]);
    }
}

int main()
{
    work();
    return 0;
}