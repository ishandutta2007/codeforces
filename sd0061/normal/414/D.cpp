#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
#define N 100005
int n , pre[N] , mcnt;
int k , p;
struct edge {
    int x , next;
}e[N << 1];
int dep[N];

void dfs(int x , int fa , int D) {
    dep[x] = D;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x , D + 1);
        }
    }
}

void work()
{
    int i , j , x , y;
    scanf("%d%d%d",&n,&k,&p);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0 , 0);
    sort(dep + 1 , dep + n + 1);
    int res = 0;
    LL sum = 0;
    for (i = j = 2 ; i <= n ; ++ i) {
        while (sum > p) {
            sum -= dep[i] - dep[j];
            ++ j;
        }
        res = max(res , i - j + 1);
        sum += (i - j + 1) * (dep[i + 1] - dep[i]);
    }
    cout << min(k , res) << endl;
}


int main()
{
    work();
    return 0;
}