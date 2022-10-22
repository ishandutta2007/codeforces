#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
typedef long long LL;
const int N = 155;
using namespace std;

int n , K , s , a[N];
int f[2][N][N * N / 2];

int main() {
    scanf("%d%d%d" , &n , &K , &s);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    if (s >= n * (n - 1) / 2) {
        sort(a , a + n);
        int res = 0;
        for (int i = 0 ; i < K ; ++ i)
            res += a[i];
        printf("%d\n" , res);
        return 0;
    }
    int cur = 0 , nxt = 1;
    memset(f[cur] , 0x3f , sizeof(f[cur]));
    f[0][0][0] = 0;
    for (int i = 0 ; i < n ; ++ i) {
        memset(f[nxt] , 0x3f , sizeof(f[nxt]));
        for (int j = 0 ; j <= i ; ++ j) {
            for (int k = 0 ; k <= s ; ++ k) {
                if (f[cur][j][k] == 0x3f3f3f3f)
                    continue;
                f[nxt][j][k] = min(f[nxt][j][k] , f[cur][j][k]);
                if (k + i - j <= s)
                    f[nxt][j + 1][k + i - j] = min(f[nxt][j + 1][k + i - j] , f[cur][j][k] + a[i]);
            }
        }        
        swap(cur , nxt);
    }
    int res = 1 << 30;
    for (int j = 0 ; j <= s ; ++ j)
        res = min(res , f[cur][K][j]);    
    printf("%d\n" , res);
    return 0;
}