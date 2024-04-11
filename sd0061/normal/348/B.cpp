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
#include <bitset>
using namespace std;
typedef long long LL;
const int N = 100005;
int a[N];
struct edge {
    int x , next;
}e[N << 1];
int deg[N];
LL F , sum , LCM;
int n , pre[N] , mcnt;

bool dfs(int x , int fa , LL w) {
    if (w > sum)
        return 0;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            ++ deg[x];
        }
    }
    if (!deg[x]) {
        LCM = LCM / __gcd(LCM , w) * w;
        F = min(F , a[x] * w);
    }
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            if (!dfs(y , x , w * deg[x]))
                return 0;
        }
    }
    return 1;
}

void work() {
    int i , x , y;
    sum = 0;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    memset(pre , -1 , sizeof(pre));
    mcnt = 0;
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    LCM = 1 , F = 1LL << 62;
    if (!dfs(1 , 0 , 1)) {
        cout << sum << endl;
        return;
    }
    cout << sum - F / LCM * LCM << endl;
}

int main() {
    work();
    return 0;
}