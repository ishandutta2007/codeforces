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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 6005;
int n , pre[N] , mcnt;
int val[N];
struct edge {
    int x , next;
}e[N << 1];

int S[N] , top , res;

void dfs(int x , int fa) {
    int upd = lower_bound(S , S + top , val[x]) - S;
    int tmp = S[upd] , flag = 0; S[upd] = val[x];
    if (upd == top) ++ top , flag = 1; res = max(res , top);
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x);
        }
    }
    top -= flag , S[upd] = tmp;
}

void work() {
    int i , x , y;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&val[i]);
    memset(pre , -1, sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    res = 0;
    for (i = 1 ; i <= n ; ++ i)
        dfs(i , 0);
    cout << res << endl;
}

int main() {
    work();
    return 0;
}