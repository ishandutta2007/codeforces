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

const int N = 22;
int n , m;
char str[50][N];
LL opt[1 << 20];
double f[1 << 20];
int main() {
    int i , j , k;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%s", str[i]);
    m = strlen(str[0]);
    for (i = 0 ; i < n ; ++ i)
        for (j = i + 1 ; j < n ; ++ j) {
            int x = 0;
            for (k = 0 ; k < m ; ++ k)
                x |= (str[i][k] == str[j][k]) << k;
            opt[x] |= 1LL << i;
            opt[x] |= 1LL << j;
        }
    for (j = 0 ; j < m ; ++ j)
        for (i = 0 ; i < 1 << m ; ++ i)
            if (~i >> j & 1)
                opt[i] |= opt[i ^ (1 << j)];
    for (i = (1 << m) - 1 ; i >= 0 ; -- i) {
        if (!opt[i]) continue;
        int x = 0;
        for (j = 0 ; j < m ; ++ j)
            if (~i >> j & 1) {
                f[i] += f[i ^ (1 << j)];
                ++ x;
            }
        f[i] = f[i] / x + 1.0 * __builtin_popcountll(opt[i]) / n;
    }
    printf("%.15f\n" , f[0]);
    return 0;
}