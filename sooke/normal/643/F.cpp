#include <bits/stdc++.h>

const int N = 135;

int n, p, q, cnt[N];
unsigned ans, rem, c[N];

void insert(int x, int sgn) {
    for (int d = 2; d <= p; d++) {
        for (; x % d == 0; x /= d) {
            cnt[d] += sgn;
        }
    }
    rem *= x;
}

int main() {
    scanf("%d%d%d", &n, &p, &q);
    p = std::min(p, n - 1); rem = 1;
    for (int i = 0; i <= p; i++) {
        c[i] = rem;
        for (int d = 2; d <= p; d++) {
            for (int j = 0; j < cnt[d]; j++) {
                c[i] *= d;
            }
        }
        if (i == p) { continue; }
        insert(n - i, 1); insert(i + 1, -1);
    }
    for (int m = 1; m <= q; m++) {
        unsigned res = 0, pwr = 1;
        for (int i = 0; i <= p; i++) {
            res += c[i] * pwr;
            pwr *= m;
        }
        ans ^= res * m;
    }
    printf("%u\n", ans);
    return 0;
}