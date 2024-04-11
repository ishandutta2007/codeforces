#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1005;

int n , m , a[N];
long double f[2][100005];

void work() {
    scanf("%d%d" , &n , &m);
    int w = n * m;
    if (m == 1) {
        puts("1");
        return;
    }
    int cur = 0 , nxt = 1 , sum = 0;
    memset(f[cur] , 0 , sizeof(f[cur]));
    f[cur][0] = 1;
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        sum += x;
        memset(f[nxt] , 0 , sizeof(f[nxt]));
        for (int j = 0 ; j <= w ; ++ j) {
            //printf("%d %d %f\n" , i , j , f[cur][j]);
            long double p = f[cur][j] / (m - 1);
            if (j + 1 <= w) f[nxt][j + 1] += p;
            if (j + x <= w) f[nxt][j + x] -= p;
            if (j + x + 1 <= w) f[nxt][j + x + 1] += p;
            if (j + m + 1 <= w) f[nxt][j + m + 1] -= p;
        }
        for (int j = 1 ; j <= w ; ++ j) {
            f[nxt][j] += f[nxt][j - 1];
        }
        swap(cur , nxt);
    }
    long double res = 0;
    for (int i = 0 ; i < sum ; ++ i)
        res += f[cur][i];
    printf("%.20f\n" , (double)res * (m - 1) + 1);
}

int main() {
    work();
    return 0;
}