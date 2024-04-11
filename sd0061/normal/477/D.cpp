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
const int N = 5005;
const int Q = 1e9 + 7;
int n;
int LCP[N][N];
int f[N][N] , d[N][N];
int g[N][N] , h[N][N];
char str[N];

void add(int& A , const int& B) {
    A += B;
    if (A >= Q)
        A -= Q;
}
void Min(int& A , const int& B) {
    if (B < A)
        A = B;
}
void work() {
    int i , j , k , x , l;
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    for (i = n ; i > 0 ; -- i)
        for (j = n ; j >= i ; -- j) {
            if (str[i] == str[j])
                LCP[i][j] = LCP[i + 1][j + 1] + 1;
            else
                LCP[i][j] = 0;
        }
    memset(g , 63 , sizeof(g));
    memset(h , 63 , sizeof(h));
    f[0][0] = 1 , g[0][0] = 0;
    for (j = 0 ; j <= n ; ++ j) {
        for (i = 0 ; i <= j ; ++ i) {
            add(f[i][j] , d[i][j]);
            add(d[i][j + 1] , d[i][j]);
            Min(g[i][j] , h[i][j]);
            Min(h[i][j + 1] , h[i][j]);
        }
        if (j == n) break;
        for (i = 0 ; i <= j ; ++ i) {
            if (g[i][j] == 0x3f3f3f3f)
                continue;
            l = j - i + 1;
            if (str[j + 1] == '0' && (l > 1 || str[j] == '1'))
                continue;
            x = min(LCP[i][j + 1] , l);
            k = j + l;
            if (x < l && str[i + x] > str[j + 1 + x])
                ++ k;
            add(d[j + 1][k] , f[i][j]);
            Min(h[j + 1][k] , g[i][j] + 1);
        }
    }
    int res = 0;
    for (i = 1 ; i <= n ; ++ i)
        add(res , f[i][n]);
    printf("%d\n" , res);
    res = 1 << 30 , x = 1;
    int sum = 0;
    for (i = n ; i >= 1 && i >= n - 25 ; -- i) {
        if (str[i] == '1')
            add(sum , x);
        x <<= 1;
        if (x >= Q)
            x -= Q;
        if (g[i][n] != 0x3f3f3f3f) {
            Min(res , g[i][n] + sum);
        }
    }
    if (res != 1 << 30) {
        printf("%d\n" , res);
        return;
    }
    for ( ; i >= 1 ; -- i) {
        if (str[i] == '1')
            add(sum , x);
        x <<= 1;
        if (x >= Q)
            x -= Q;
        if (g[i][n] != 0x3f3f3f3f) {
            printf("%d\n" , (g[i][n] + sum) % Q);
            break;
        }
    }
}

int main() {
    work();
    return 0;
}