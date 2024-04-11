#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 2005;
const LL Q = 1e9 + 7;
int n , d , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
int a[N];
LL f[N];

void dfs(int x , int fa , int top) {
    f[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa && make_pair(a[y] , y) > make_pair(a[top] , top) && a[y] <= a[top] + d) {
            dfs(y , x , top);
            f[x] *= f[y] + 1;
            f[x] %= Q;
        }
    }
}

int main() {
    int i , x , y;
    scanf("%d%d",&d,&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    int ans = 0;
    for (i = 1 ; i <= n ; ++ i) {
        dfs(i , 0 , i);
        ans += f[i] , ans %= Q;
    }
    cout << ans << endl;
    return 0;
}