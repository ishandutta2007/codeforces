#include <cstdio>

const int N = 1e7 + 34;
const int M = 1e4 + 34;

#define min(a, b) (a < b ? a : b)

int a[N], n, m, x, l, r;
int p[M], len;
bool u[M];

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    for (int i = 2; i < M; i++) {
        if (!u[i]) {
            p[len++] = i;
            for (int j = i * i; j < M; j += i)
                u[j] = true;
        }
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        for (int j = 0; p[j] * p[j] <= x; j++) {
            if (x % p[j] == 0) {
                a[p[j]]++;
                while (x % p[j] == 0) {
                    x /= p[j];
                }
            }
        }
        if (x > 0)
            a[x]++;
    }
    for (int i = 1; i < N; i++)
        a[i] += a[i - 1];

    scanf("%d", &m);
    while (m --> 0) {
        scanf("%d%d", &l, &r);
        l = min(l, N - 1);
        r = min(r, N - 1);
        printf("%d\n", a[r] - a[l - 1]);
    }
    return 0;
}