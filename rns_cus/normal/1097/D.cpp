#include <bits/stdc++.h>
using namespace std;

#define N 10010

long long n;
int k, rlt = 1, rev[N], tp[70];

const int mod = 1e9 + 7;

int powmod(int a, int n) {
    int rlt = 1;
    while (n) {
        if (n & 1) rlt = 1ll * rlt * a % mod;
        a = 1ll * a * a % mod, n >>= 1;
    }
    return rlt;
}

int main() {
    scanf("%I64d %d", &n, &k);
    for (int i = 1; i < N; i ++) rev[i] = powmod(i, mod - 2);
    for (int i = 2; 1ll * i * i <= n; i ++) {
        if (n % i == 0) {
            int al = 0, cnt = tp[0] = 1;
            while (n % i == 0) n /= i, al ++;
            for (int j = 1; j <= al; j ++)
                tp[j] = 1ll * tp[j-1] * i % mod;
            for (int l = 0; l < k; l ++) {
                int sum = 0;
                for (int j = 0; j <= al; j ++) {
                    sum = (sum + tp[j]) % mod;
                    tp[j] = 1ll * sum * rev[j+1] % mod;
                }
            }
            rlt = 1ll * rlt * tp[al] % mod;
        }
    }
    if (n > 1) {
        int cnt = 1;
        tp[0] = 1, tp[1] = n % mod;
        for (int i = 0; i < k; i ++) {
            int sum = 0;
            for (int j = 0; j <= 1; j ++) {
                sum = (sum + tp[j]) % mod;
                tp[j] = 1ll * sum * rev[j+1] % mod;
            }
        }
        rlt = 1ll * rlt * tp[1] % mod;
    }
    printf("%d\n", rlt);
}