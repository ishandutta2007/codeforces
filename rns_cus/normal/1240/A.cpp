#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, p[N], a, x, b, y;
long long K, d;

bool check(int m) {
    int i = m / d, j = m / a - i, k = m / b - i;
    assert(i + j + k <= n);
    long long rlt = 0;
    for (int q = 0; q < i; q ++) rlt += p[q] * (x + y);
    for (int q = 0; q < j; q ++) rlt += p[i+q] * x;
    for (int q = 0; q < k; q ++) rlt += p[i+j+q] * y;
    return rlt >= K;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) scanf("%d", &p[i]), p[i] /= 100;
        sort(p, p + n, greater <int> () );
        scanf("%d %d %d %d %I64d", &x, &a, &y, &b, &K);
        if (x < y) swap(x, y), swap(a, b);
        d = 1ll * a * b / __gcd(a, b);
        if (!check(n)) puts("-1");
        else {
            int le = 0, ri = n;
            while (le < ri - 1) {
                int mi = le + ri >> 1;
                if (check(mi)) ri = mi;
                else le = mi;
            }
            printf("%d\n", ri);
        }
    }

    return 0;
}