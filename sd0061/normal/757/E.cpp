#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int Q = 1e9 + 7;
int fac[N];
bool f[N];
int c[N][22];
int main() {
    for (int i = 2 ; i < N ; ++ i) {
        if (!f[i]) {
            fac[i] = i;
            for (int j = i + i ; j < N ; j += i) {
                if (!fac[j]) fac[j] = i;
                f[j] = 1;
            }
        }
    }
    c[0][0] = 1;
    for (int i = 1 ; i < 22 ; ++ i) {
        c[0][i] = 2;
    }
    for (int i = 1 ; i < N ; ++ i) {
        c[i][0] = c[i - 1][0];
        for (int j = 1 ; j < 22 ; ++ j) {
            c[i][j] = (c[i - 1][j] + c[i][j - 1]) % Q;
        }
    }
    int T;
    scanf("%d" , &T);
    while (T --) {
        int r , n;
        scanf("%d%d" , &r , &n);
        int res = 1;
        while (n > 1) {
            int x = fac[n] , y = 0 , v = 1;
            while (n % x == 0) {
                n /= x;
                y ++;
            }
            res = (long long) res * c[r][y] % Q;
        }
        printf("%d\n" , res);
    }
}