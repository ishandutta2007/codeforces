#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 100005
#define M 300005
int a[N];
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[M];
int low[N] , dfn[N] , ncnt;
bool f[N];
stack<int> S;
LL ans , sum ,  Q = 1e9 + 7;

void dfs(int x) {
    low[x] = dfn[x] = ++ ncnt;
    f[x] = 1 , S.push(x);
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!dfn[y]) {
            dfs(y);
            low[x] = min(low[x] , low[y]);
        } else if (f[y]){
            low[x] = min(low[x] , dfn[y]);
        }
    }
    if (low[x] == dfn[x]) {
        int mn = 1 << 30 , cnt = 0 , i;
        do {
            i = S.top() , f[i] = 0 , S.pop();
            if (a[i] < mn)
                mn = a[i] , cnt = 1;
            else if (a[i] == mn)
                ++ cnt;
        }while (i != x);
        ans += mn , sum *= cnt , sum %= Q;
    }

}

void work() {
    int i , x , y;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
    }
    ans = 0 , sum = 1;
    for (i = 1 ; i <= n ; ++ i)
        if (!dfn[i])
            dfs(i);
    printf("%I64d %I64d\n" , ans , sum);
}

int main()
{
    work();
    return 0;
}