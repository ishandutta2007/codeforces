#include <bits/stdc++.h>

const int MAXN = 3e5 + 5;
const int MAXM = 1.5e7 + 5;

int prime[MAXM], divisor[MAXM];
bool notprime[MAXM];

void GetPrime() {
    const int Lim = 1.5e7;
    
    for (int i = 2; i <= Lim; ++i) {
        if (!notprime[i]) {
            prime[++*prime] = i;
            divisor[i] = i;
        }
        for (int j = 1; j <= *prime && 1LL * i * prime[j] <= Lim; ++j) {
            notprime[i * prime[j]] = 1;
            divisor[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

int n, a[MAXN];

int gcd;

std::unordered_map<int, int> cnt;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        
        if (i == 1) gcd = a[i];
        else gcd = std::__gcd(gcd, a[i]);
    }
    
    int one = 0;
    
    for (int i = 1; i <= n; ++i) {
        a[i] /= gcd;
        if (a[i] == 1) ++one;
    }
    
    if (one == n) {
        puts("-1");
        exit(0);
    }
    
    GetPrime();
    
    int ans = 0;
    
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        while (x > 1) {
            int y = divisor[x];
            ans = std::max(ans, ++cnt[y]);
            while (x % y == 0) x /= y;
        }
    }
    
    printf("%d\n", n - ans);
    
    return 0;
}