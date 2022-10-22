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

const int N = 2005;
int n , m;
char s[N] , t[N];
int pre[N] , val[N];
int f[N][N];

void work() {
    int i , j , k , x;
    scanf("%s%s", s + 1 , t + 1);
    n = strlen(s + 1) , m = strlen(t + 1);
    for (i = 1 ; i <= n ; ++ i) {
        x = 0;
        for (j = i , k = m ; j > 0 && k ; -- j) {
            if (s[j] == t[k])
                -- k;
            else
                ++ x;
        }
        if (k == 0) {
            pre[i] = j;
            val[i] = x;
        } else {
            pre[i] = -1;
        }
    }
    memset(f , 0xC0 , sizeof(f));
    f[0][0] = 0;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 0 ; j <= n ; ++ j) {
            f[i][j] = max(f[i][j] , f[i - 1][j]);
            if (j)
                f[i][j] = max(f[i][j] , f[i - 1][j - 1]);
            if (~pre[i] && j >= val[i])
                f[i][j] = max(f[i][j] , f[pre[i]][j - val[i]] + 1);
        }
    }
    for (i = 0 ; i <= n ; ++ i)
        printf("%d%c" , f[n][i] , " \n"[i == n]);
}

int main() {
    work();
    return 0;
}