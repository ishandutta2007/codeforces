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
int n , K;
int a[5][N] , p[5][N] , f[N];
bool g[N][N] , vis[N];

int F(int x) {
    if (vis[x]) return f[x];
    vis[x] = 1; f[x] = 0;
    for (int y = 1 ; y <= n ; ++ y) {
        if (g[x][y]) {
            f[x] = max(f[x] , F(y));
        }
    }
    return ++ f[x];
}

void work() {
    int i , j , k;
    scanf("%d%d",&n,&K);
    for (j = 0 ; j < K ; ++ j)
        for (i = 1 ; i <= n ; ++ i) {
            scanf("%d",&a[j][i]);
            p[j][a[j][i]] = i;
        }
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j) {
            if (i == j)
                continue;
            for (k = 0 ; k < K ; ++ k)
                if (p[k][i] > p[k][j])
                    break;
            if (k >= K)
                g[i][j] = 1;
        }
    int res = 0;
    for (i = 1 ; i <= n ; ++ i)
        res = max(res , F(i));
    cout << res << endl;
}

int main() {
    work();
    return 0;
}