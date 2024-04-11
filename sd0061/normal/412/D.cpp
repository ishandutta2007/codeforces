#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
typedef long long LL;
using namespace std;
#define N 100005

int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N];
bool f[N];

void dfs(int x) {
    if (f[x]) return; f[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        dfs(e[i].x);
    printf("%d\n" , x);
}

void work()
{
    int i , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d" , &x , &y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
    }
    for (i = 1 ; i <= n ; ++ i)
        if (!f[i])
            dfs(i);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
//while (scanf("%d",&n) , n)
        work();
    return 0;
}