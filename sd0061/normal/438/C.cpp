#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;

const int N = 205;
int n;
LL X[N] , Y[N];
LL f[N][N] , Q = 1e9 + 7;

void work() {
    scanf("%d",&n);
    int i , j , k , l;
    LL area = 0;
    for (i = 0 ; i < n ; ++ i)
        scanf("%I64d%I64d" , &X[i] , &Y[i]);
    for (i = 0 ; i < n ; ++ i) {
        area += X[i] * Y[(i + 1) % n] - Y[i] * X[(i + 1) % n];
    }
    if (area < 0) {
        area = -area;
        reverse(X , X + n);
        reverse(Y , Y + n);
    }
    for (l = 1 ; l < n ; ++ l) {
        for (i = 0 ; i + l < n ; ++ i) {
            j = i + l;
            if (l == 1) {
                f[i][j] = 1;
            } else {
                for (k = i + 1 ; k < j ; ++ k) {
                    if ((X[k] - X[i]) * (Y[k] - Y[j]) - (Y[k] - Y[i]) * (X[k] - X[j]) < 0) {
                        f[i][j] += f[i][k] * f[k][j] % Q;
                        f[i][j] %= Q;
                    }
                }
            }
        }
    }
    printf("%d\n" , (int) f[0][n - 1]);
}

int main()
{
    work();
    return 0;
}