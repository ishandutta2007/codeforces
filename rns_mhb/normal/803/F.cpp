#include <bits/stdc++.h>
using namespace std;

#define N 100005

const int mod = 1e9 + 7;
int n;
int a[N], cnt[N];
int e[N];

int pcnt, phi[N], mu[N], prime[N];

void ppm() {
    phi[1] = mu[1] = 1;
    for (int i = 2; i < N; i ++) {
        if (!phi[i]) prime[pcnt++] = i, phi[i] = i - 1, mu[i] = -1;
        for (int j = 0; j < pcnt && prime[j] * i < N; j ++) {
            int k = i * prime[j];
            phi[k] = phi[i] * (prime[j] - 1);
            if (i % prime[j] == 0) {
                phi[k] = phi[i] * prime[j];
                break;
            }
            mu[k] = -mu[i];
        }
    }
}

void init() {
    e[0] = 1;
    for (int i = 1; i < N-2; i ++) e[i] = 2ll * e[i-1] % mod;
    ppm();
}

int ans;

int main() {
    
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        a[x] ++;
    }
    for (int i = 1; i < N-2; i ++) {
        for (int j = 1; i * j < N - 2; j ++) {
            cnt[i] += a[i*j];
        }
    }
    for (int i = 1; i < N-2; i ++) {
        cnt[i] = (e[cnt[i]] + mod - 1) % mod;
    }
    for (int i = 1; i < N-2; i ++) {
        (ans += 1ll * mu[i] * cnt[i] % mod) %= mod;
    }
    printf("%d\n", (ans % mod + mod) % mod);
    return 0;
}