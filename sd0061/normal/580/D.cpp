#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 18;
int n , m , K;
int g[N][N] , a[N];
LL f[N][1 << N];


int main() {
    scanf("%d%d%d" , &n , &m , &K);
    memset(f , 0xC0 , sizeof(f));
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        f[i][1 << i] = a[i];
    }
    for (int i = 0 ; i < K ; ++ i) {
        int x , y , v;
        scanf("%d%d%d" , &x , &y , &v);
        -- x , -- y;
        g[x][y] = max(g[x][y] , v);
    }
    LL res = -1LL << 60;
    for (int i = 0 ; i < 1 << n ; ++ i) {
        for (int x = 0 ; x < n ; ++ x) {
            if (f[x][i] < 0) continue;
            if (__builtin_popcount(i) == m)
                res = max(res , f[x][i]);
            for (int y = 0 ; y < n ; ++ y)
                if (~i >> y & 1)
                    f[y][i | (1 << y)] = max(f[y][i | (1 << y)] , f[x][i] + a[y] + g[x][y]);
        }
    }
    cout << res << endl;
    return 0;
}