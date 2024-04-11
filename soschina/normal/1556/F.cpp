#include <cstdio>
using namespace std;
const int N = 17, N2 = 65536, N3 = 43046721, p = 1e9 + 7, X = 2e6 + 1;

int inv[X], n, x[N], onetomany[N][N2], manytomany[N2], f[N2];

int main(){
    inv[1] = 1;
    for(int i = 2; i < X; i++)
        inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for (int i = 0; i < n; i++){
        onetomany[i][0] = 1;
        for (int s = 1; s < (1 << n); s++)
            if(!(s & (1 << i)))
                onetomany[i][s] = 1ll * onetomany[i][(s - 1) & s] * x[i] % p * inv[x[i] + x[__builtin_ctz(s)]] % p;
    }
    int ans = 0;
    for (int s = 1; s < (1 << n); s++){
        manytomany[0] = 1;
        int us = ((1 << n) - 1) ^ s;
        for (int t = (s - 1) & s; t > 0; t = (t - 1) & s){
            int now = s ^ t;
            manytomany[now] = 1ll * manytomany[(now - 1) & now] * onetomany[__builtin_ctz(now)][us] % p;
            f[s] = (f[s] - 1ll * f[t] * manytomany[now]) % p;
        }
        manytomany[s] = 1ll * manytomany[(s - 1) & s] * onetomany[__builtin_ctz(s)][us] % p;
        f[s] = ((f[s] + p) % p + manytomany[s]) % p;
        ans = (ans + 1ll * __builtin_popcount(s) * f[s]) % p;
    }
    printf("%d", ans);
    return 0;
}