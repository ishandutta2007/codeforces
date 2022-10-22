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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 505;
int n , m , Q;
int C[N][N] , f[N][N];
char str[N];
int cnt[N];
void work () {
    int i , j , k , l;
    scanf("%d%d%d",&n,&m,&Q);
    for (i = 0 ; i <= n ; ++ i) {
        C[i][0] = 1;
        for (j = 1 ; j <= i ; ++ j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Q;
        }
    }
    for (i = 0 ; i < m ; ++ i) {
        scanf("%s" , str);
        for (j = 0 ; j < n ; ++ j)
            if (str[j] == '1')
                ++ cnt[j];
    }
    k = 0;
    for (i = 0 ; i < n ; ++ i)
        k += (cnt[i] == 1);
    f[m][k] = 1;
    for (i = m ; i < n ; ++ i) {
        for (k = 0 ; k <= n && k <= i + i; ++ k) {
            if ((i + i - k) % 2 != 0) continue;
            l = (i + i - k) >> 1;
            j = n - k - l;
            if (j < 0) continue;
            if (!f[i][k]) continue;
            if (j >= 2)
                f[i + 1][k + 2] += (LL)f[i][k] * C[j][2] % Q , f[i + 1][k + 2] %= Q;
            if (j && k)
                f[i + 1][k] += (LL)f[i][k] * j * k % Q , f[i + 1][k] %= Q;
            if (k >= 2)
                f[i + 1][k - 2] += (LL)f[i][k] * C[k][2] % Q , f[i + 1][k - 2] %= Q;
        }
    }
    int res = 0;
    for (i = 0 ; i <= n ; ++ i)
        res += f[n][i] , res %= Q;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}