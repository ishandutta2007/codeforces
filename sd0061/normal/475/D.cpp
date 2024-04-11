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
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , q , a[N] , ca;
int f[17][N] , LOG[N];

inline int GCD(int l , int r) {
    int j = LOG[r - l + 1];
    return __gcd(f[j][l] , f[j][r - (1 << j) + 1]);
}
map<int , LL> res;
void work() {
    int i , j , x , y , z;
    scanf("%d",&n);
    for (int i = 0 ; 1 << i <= n ; ++ i)
        LOG[1 << i] = i;
    for (int i = 2 ; i <= n ; ++ i)
        if (!LOG[i])
            LOG[i] = LOG[i - 1];
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , f[0][i] = a[i];
    for (j = 1 ; 1 << j <= n ; ++ j)
        for (i = 1 ; i + (1 << j) - 1 <= n ; ++ i)
            f[j][i] = __gcd(f[j - 1][i] , f[j - 1][i + (1 << j - 1)]);
    for (i = 1 ; i <= n ; ++ i) {
        x = i;
        while (x <= n) {
            y = GCD(i , x);
            int l = x , r = n , m;
            while (l < r) {
                m = l + r + 1 >> 1;
                if (GCD(i , m) == y)
                    l = m;
                else
                    r = m - 1;
            }
            // i [x , l] y
            res[y] += l - x + 1;
            x = l + 1;
        }
    }
    scanf("%d",&q);
    while (q --) {
        scanf("%d",&x);
        if (res.count(x))
            printf("%I64d\n" , res[x]);
        else
            puts("0");
    }
}

int main() {
    work();
    return 0;
}