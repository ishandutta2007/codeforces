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
typedef unsigned long long ULL;
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 100005;
const int Q = 1e9 + 7;
int n , m , pre[N] , mcnt;
bool c[N];
struct edge {
    int x , next;
}e[N];
LL f[N][2];

LL inv(int x) {
    return x == 1 ? 1 : (Q - Q / x) * inv(Q % x) % Q;
}

void dfs(int x) {
    if (c[x]) {
        f[x][1] = 1;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            LL tmp = f[x][1];
            f[x][1] = 0;
            dfs(y);
            f[x][1] += tmp * f[y][0] % Q;
            f[x][1] %= Q;
            f[x][1] += tmp * f[y][1] % Q;
            f[x][1] %= Q;
        }
    } else {
        LL value = 1;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            dfs(y);
            value = value * ((f[y][0] + f[y][1]) % Q) % Q;
        }
        f[x][0] = value;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            f[x][1] += value * inv((f[y][0] + f[y][1]) % Q) % Q * f[y][1] % Q;
            f[x][1] %= Q;
        }
    }

}

void work() {
    int i , j , x , y;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d",&x);
        e[mcnt] = (edge) {i , pre[x]} , pre[x] = mcnt ++;
    }
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&c[i]);
    }
    dfs(0);
    printf("%d\n" , (int) f[0][1]);
}

int main() {
   // freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}