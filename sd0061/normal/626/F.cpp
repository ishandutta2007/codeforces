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
const int N = 205;
const int Q = 1e9 + 7;
int n , K , a[N];
int f[2][101][1005];

inline void add(int &A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}

int main() {
    scanf("%d%d" , &n , &K);
    // n = 200  , K = 1000;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        //a[i] = rand() % 500 + 1;
    }
    sort(a , a + n);
    a[n] = a[n - 1];
    int cur = 0 , nxt = 1;
    f[cur][0][0] = 1;
    for (int i = 0 ; i < n ; ++ i) {
        memset(f[nxt] , 0 , sizeof(f[nxt]));
        for (int j = 0 ; j <= i && j + j <= n ; ++ j) {
            for (int k = 0 ; k <= K ; ++ k) {                
                if (!f[cur][j][k])
                    continue;
                // printf("%d %d %d : %d\n" , i , j , k , f[cur][j][k]);
                int w = f[cur][j][k];
                int d = (a[i + 1] - a[i]);
                if (d * j + k <= K)
                    add(f[nxt][j][d * j + k] , (LL)w * (j + 1) % Q);
                if (j + 1 <= 100 && k + d * j + d <= K)
                    add(f[nxt][j + 1][k + d * j + d] , w);
                if (j && k + d * j - d <= K)
                    add(f[nxt][j - 1][k + d * j - d] , (LL)w * j % Q);
            }
        }
        swap(cur , nxt);
    }
    int res = 0;
    for (int i = 0 ; i <= K ; ++ i)
        add(res , f[cur][0][i]);
    printf("%d\n" , res);
    return 0;
}