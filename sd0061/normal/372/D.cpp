#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int N = 100005;
int n , m , pre[N] , mcnt , ncnt;
struct edge
{
    int x , next;
}e[N << 1];
int f[17][N] , L[N] , id[N];
set< pair<int , int> > h;

void dfs(int x , int fa , int dep)
{
    f[0][x] = fa , id[x] = ++ ncnt , L[x] = L[fa] + 1;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != fa)
            dfs(e[i].x , x , dep + 1);
}
int LCA(int x , int y)
{
    int i;
    if (L[x] < L[y]) swap(x , y);
    for (i = 16 ; i >= 0 ; -- i)
        if (L[x] - L[y] >= (1 << i))
            x = f[i][x];
    if (x == y) return y;
    for (i = 16 ; i >= 0 ; -- i)
        if (f[i][x] && f[i][x] != f[i][y])
            x = f[i][x] , y = f[i][y];
    return f[0][x];
}
int dist(int x , int y)
{
    int z = LCA(x , y);
    return L[x] + L[y] - L[z] - L[z];
}

void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0 , 0);
    for (j = 1 ; 1 << j < n ; ++ j)
        for (i = 1 ; i <= n ; ++ i)
            f[j][i] = f[j - 1][f[j - 1][i]];
    set< pair<int , int> >::iterator it;
    int num = 0 , ans = 0;
    for (i = 1 , j = 1 ; i <= n ; ++ i)
    {
        it = h.lower_bound(make_pair(id[i] , i));
        if (it == h.begin() || it == h.end())
        {
            if (h.size() > 0)
            {
                num -= dist(h.begin() -> second , (-- h.end()) -> second);
                num += dist(h.begin() -> second , i );
                num += dist(i , (-- h.end()) -> second);
            }
        }
        else
        {
            set< pair<int , int> >::iterator ti = it;
            -- it;
            num -= dist(ti -> second , it -> second);
            num += dist(ti -> second , i );
            num += dist(i , it -> second);
        }
        h.insert(make_pair(id[i] , i));

        while (j <= i && num + 2 > m + m)
        {
            set< pair<int , int> >::iterator itl , itr;
            itl = itr = it = h.lower_bound(make_pair(id[j] , j));
            if (itl == h.begin()) itl = -- h.end(); else -- itl;
            if (itr == -- h.end()) itr = h.begin(); else ++ itr;
            //printf("%d : %d %d %d\n" , j , itl->second , it->second , itr->second);
            num -= dist(it -> second , itl -> second);
            num -= dist(it -> second , itr -> second);
            num += dist(itl -> second , itr -> second);
            h.erase(it);
            ++ j;
        }
        ans = max(ans , i - j + 1);
    }
    printf("%d\n" , ans);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}