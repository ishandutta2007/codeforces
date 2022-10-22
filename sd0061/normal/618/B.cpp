#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 105;

int n , a[N][N] , b[N];
bool f[N];

int main() {

    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= n ; ++ j)
            scanf("%d" , &a[i][j]);
    for (int k = 1 ; k <= n ; ++ k) {
        int mn = 1 << 30; int p = 0;
        for (int i = 1 ; i <= n ; ++ i) {
            if (f[i]) continue;
            int s = 0;
            for (int j = 1 ; j <= n ; ++ j) {
                if (f[j]) continue;
                s += a[i][j];
            }
            if (s < mn) {
                mn = s;
                p = i;
            }
        }
        b[p] = k , f[p] = 1;
    }
    for (int i = 1 ; i <= n ; ++ i)
        printf("%d%c" , b[i] , " \n"[i == n]);
    
    return 0;
}