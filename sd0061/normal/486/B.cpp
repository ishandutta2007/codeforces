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
const int N = 105;

int n , m , a[N][N] , b[N][N];

int main() {
    int i , j , k , l;
    cin >> m >> n;
    for (i = 1 ; i <= m ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            b[i][j] = 1;
    for (i = 1 ; i <= m ; ++ i)
        for (j = 1 ; j <= n ; ++ j) {
            cin >> a[i][j];
            if (a[i][j])
                continue;
            for (k = 1 ; k <= m ; ++ k) b[k][j] = 0;
            for (k = 1 ; k <= n ; ++ k) b[i][k] = 0;
        }
    for (i = 1 ; i <= m ; ++ i) {
        for (j = 1 ; j <= n ; ++ j) {
            if (!a[i][j]) continue;
            for (k = 1 ; k <= m ; ++ k)
                if (b[k][j])
                    break;
            for (l = 1 ; l <= n ; ++ l)
                if (b[i][l])
                    break;
            if (k > m && l > n) break;
        }
        if (j <= n)
            break;
    }
    if (i <= m) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (i = 1 ; i <= m ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            printf("%d%c" , b[i][j] , " \n"[j == n]);
    return 0;
}