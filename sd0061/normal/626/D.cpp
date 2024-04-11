#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 2005;
const int Q = 1e9 + 7;

int n , m , a[N];
int cntw[5000] , cntl[5000];
LL f[10000];
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n; ++ i) {
        scanf("%d" , a + i);
    }
    int w = 0 , l = 0;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < n ; ++ j) {
            if (j != i) {
                ++ m;
                int x = a[j] - a[i];
                if (x > 0) {
                    ++ w;
                    ++ cntw[x];
                } else {
                    ++ l;
                    ++ cntl[-x];
                }
            }
        }
    }
    for (int i = 0 ; i < 5000 ; ++ i)
        for (int j = 0 ; j < 5000 ; ++ j)
            f[i + j] += (LL)cntw[i] * cntw[j];
    for (int i = 1 ; i < 10000 ; ++ i)
        f[i] += f[i - 1];
    double res = 0;
    for (int i = 1 ; i < 5000 ; ++ i) {
        res += (long double)cntl[i] / l * f[i - 1] / w / w;
    }
    printf("%.15f\n" , res);
    return 0;
}