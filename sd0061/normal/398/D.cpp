#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 400005
#define foreach(it , A) for (typeof(A.begin()) it = A.begin() ; it != A.end() ; ++ it)
int n , m , Q , M;
bool on[N];
int deg[N];
pair<int , int> e[N];
struct query
{
    int id;
    int x , y;
}q[N];
vector<int> g[N];
int bcnt , id[N] , ans[N] , lyb[550];
bool B[550][N];
void work()
{
    int i , j , x , y ;
    char str[10];
    scanf("%d%d%d%d",&n,&m,&Q,&j);
    while (j --)
        scanf("%d",&x) , on[x] = 1;
    for (i = 0 ; i < m ; ++ i)
        scanf("%d%d",&x,&y) , e[i] = make_pair(x , y) , ++ deg[x] , ++ deg[y] , ++ M;
    for (i = 0 ; i < Q ; ++ i)
    {
        scanf("%s%d" , str , &q[i].x);
        if (*str == 'O') q[i].id = 0;
        if (*str == 'F') q[i].id = 1;
        if (*str == 'A') q[i].id = 2 , scanf("%d" , &q[i].y) , ++ deg[q[i].x] , ++ deg[q[i].y] , ++ M;
        if (*str == 'D') q[i].id = 3 , scanf("%d" , &q[i].y);
        if (*str == 'C') q[i].id = 4;
    }
    M = sqrt(2 * M);
    for (i = 1 ; i <= n ; ++ i)
        if (deg[i] >= M)
            id[i] = ++ bcnt , lyb[bcnt] = i;
    for (i = 0 ; i < m ; ++ i)
    {
        x = e[i].first , y = e[i].second;
        if (deg[x] < M)
            g[x].push_back(y);
        else
            B[id[x]][y] = 1;
        if (deg[y] < M)
            g[y].push_back(x);
        else
            B[id[y]][x] = 1;
        if (deg[x] < M && on[x]) ++ ans[y];
        if (deg[y] < M && on[y]) ++ ans[x];
    }

    for (i = 0 ; i < Q ; ++ i)
    {
        x = q[i].x , y = q[i].y;
        if (q[i].id < 2)
        {
            on[x] = !q[i].id;
            if (deg[x] < M)
            {
                foreach(it , g[x])
                    q[i].id ? -- ans[*it] : ++ ans[*it];
            }
        }
        else if (q[i].id == 2)
        {
            if (deg[x] < M)
            {
                if (on[x]) ++ ans[y];
                g[x].push_back(y);
            }
            else
                B[id[x]][y] = 1;
            if (deg[y] < M)
            {
                if (on[y]) ++ ans[x];
                g[y].push_back(x);
            }
            else
                B[id[y]][x] = 1;
        }
        else if (q[i].id == 3)
        {
            if (deg[x] < M)
            {
                if (on[x]) -- ans[y];
                foreach(it , g[x])
                    if (*it == y)
                    {
                        g[x].erase(it);
                        break;
                    }
            }
            else
                B[id[x]][y] = 0;
            if (deg[y] < M)
            {
                if (on[y]) -- ans[x];
                foreach(it , g[y])
                    if (*it == x)
                    {
                        g[y].erase(it);
                        break;
                    }
                }
            else
                B[id[y]][x] = 0;
        }
        else if (q[i].id == 4)
        {
            int res = ans[x];
            for (j = 1 ; j <= bcnt ; ++ j)
                if (on[lyb[j]] && B[j][x])
                    ++ res;
            printf("%d\n" , res);
        }
    }
}

int main()
{
    work();
    return 0;
}