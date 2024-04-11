#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
#include <bitset>
using namespace std;
typedef long long LL;

const int N = 300005;
int n , m , Q;
int f[N] , dis[N] , D[N];
int pre[N] , mcnt;
struct edge
{
    int x , next;
}e[N << 1];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}

pair<int , int> f1[N] , f2[N];
int d[N];
bool vis[N];
void dfs1(int x , int fa , vector<int>& res)
{
    res.push_back(x);
  f1[x] = make_pair(0 , x) , f2[x] = make_pair(-1 << 30 , -1);
  vis[x] = 1;
  for (int i = pre[x]; ~i ; i = e[i].next)
  {
    int y = e[i].x; if (y == fa) continue;
    dfs1(y , x , res);
    pair<int , int> tmp(f1[y].first + 1 , y);
    if (tmp > f1[x])
      f2[x] = f1[x] , f1[x] = tmp;
    else if (tmp > f2[x])
      f2[x] = tmp;
  }
}

void dfs2(int x , int fa)
{
  for (int i = pre[x]; ~i ; i = e[i].next)
  {
    int y = e[i].x; if (y == fa) continue;
    if (y != f1[x].second)
      d[y] = max(f1[x].first , d[x]) + 1;
    else
      d[y] = max(f2[x].first , d[x]) + 1;
    dfs2(y , x);
  }
}

void merge(int x , int y) {
    x = getf(x) , y = getf(y);
    if (x == y) return;
    int newd = max(max(D[x] , D[y]) , dis[x] + dis[y] + 1);
    int pa = min(max(dis[x] , 1 + dis[y]) , max(dis[y] , 1 + dis[x]));
    if (max(dis[x] , 1 + dis[y]) == pa) {
        f[y] = x , dis[x] = max(dis[x] , 1 + dis[y]) , D[x] = newd;
    } else {
        f[x] = y , dis[y] = max(dis[y] , 1 + dis[x]) , D[y] = newd;
    }
}

void work() {
    int i , j , k , x , y , z;
    scanf("%d%d%d",&n,&m,&Q);
    for (i = 1 ; i <= n ; ++ i) {
        f[i] = i;
    }
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge){x , pre[y]} , pre[y] = mcnt ++;
        e[mcnt] = (edge){y , pre[x]} , pre[x] = mcnt ++;
    }
    for (i = 1 ; i <= n ; ++ i) {
        if (vis[i])
            continue;
        vector<int> node;
        dfs1(i , 0 , node) , dfs2(i , 0);
        pair<int , int> res(1 << 30 , -1);
        int DD = 0;
        for (j = 0 ; j < node.size() ; ++ j) {
            x = node[j];
            z = max(f1[x].first , d[x]);
            res = min(res , make_pair(z , x));
            DD = max(DD , z);
        }
        x = res.second; f[x] = x , D[x] = DD , dis[x] = max(f1[x].first , d[x]);
        for (j = 0 ; j < node.size() ; ++ j) {
            y = node[j];
            f[y] = x;
        }
    }

    while (Q --) {
        scanf("%d",&i);
        if (i == 1) {
            scanf("%d",&x);
            printf("%d\n" , D[getf(x)]);
        } else {
            scanf("%d%d",&x,&y);
            merge(x , y);
        }

    }

}


int main()
{
   // freopen("~input.txt" , "r" , stdin);
//    while (~scanf("%d%d",&n,&K))
        work();
    return 0;
}