#include <bits/stdc++.h>
using namespace std;

#define N 100100

long long n;
int m;

int p[100], a[100];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%I64d %d", &n, &m);

        if (n % m) {
            printf("%I64d\n", n);
            continue;
        }

        int tot = 0;
        for (int x = 2; 1ll * x * x <= m; x ++) {
            if (m % x) continue;
            p[tot] = x, a[tot] = 0;
            while (m % x == 0) m /= x, a[tot] ++;
            tot ++;
        }
        if (m > 1) p[tot] = m, a[tot] = 1, tot ++;
        long long ans = n, d = n;
        for (int i = 0; i < tot; i ++) {
            int cnt = 0;
            while (n % p[i] == 0) n /= p[i], cnt ++;
            assert(cnt >= a[i]);
            long long pw = 1;
            while (cnt >= a[i]) cnt --, pw *= p[i];
            d = min(d, pw);
        }
        printf("%I64d\n", ans / d);

    }

    return 0;
}