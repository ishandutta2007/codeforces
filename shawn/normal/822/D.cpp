#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int rd() {
    int x = 0; char c = getchar();
    while (c > '9' || c < '0') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x;
}

const long long P = 1e9 + 7;
const int N = 5e6 + 10;

long long t, L, R, fac[N], pri[N], f[N], ans;

int main() {
    t = rd(), L = rd(), R = rd();
    for (int i = 2; i <= R; i ++) {
        if (!fac[i]) fac[i] = i, pri[++pri[0]] = i;
        for (int j = 1; j <= pri[0] && i * pri[j] <= R; j ++) {
            fac[i * pri[j]] = pri[j];
            if (i % pri[j] == 0) break;
        }
    }
    for (int i = 2; i <= R; i ++) {
        if (fac[i] == i) f[i] = 1ll * i * (i - 1) / 2;
        else f[i] = (1ll * f[i / fac[i]] + 1ll * i * (fac[i] - 1) / 2);
    }
    long long g = 1;
    for (int i = L; i <= R; i ++) {
        ans = (1ll * ans + 1ll * f[i] % P * g % P) % P;
        g = 1ll * g * t % P;
    }
    printf("%lld\n", ans);
    return 0;
}