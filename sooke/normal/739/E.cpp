#include <cstdio>
#include <cstdlib>

const double eps = 1e-12;

const int N = 2e3 + 5;

int n, maxa, maxb, a[N], b[N];
double x, y, resx, ansx, ansy, f[N], p[N], q[N];

void solve0() {
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        a[i] = a[i - 1];
        b[i] = b[i - 1];
        if (f[i] < f[i - 1] + p[i] - x) {
            f[i] = f[i - 1] + p[i] - x;
            a[i] = a[i - 1] + 1;
            b[i] = b[i - 1];
        }
        if (f[i] < f[i - 1] + q[i] - y) {
            f[i] = f[i - 1] + q[i] - y;
            a[i] = a[i - 1];
            b[i] = b[i - 1] + 1;
        }
        if (f[i] < f[i - 1] + p[i] + q[i] - p[i] * q[i] - x - y) {
            f[i] = f[i - 1] + p[i] + q[i] - p[i] * q[i] - x - y;
            a[i] = a[i - 1] + 1;
            b[i] = b[i - 1] + 1;
        }
    }
}

void solve1() {
    for (double l = -1, r = 1; l <= r; ) {
        x = (l + r) / 2; solve0();
        if (a[n] <= maxa) {
            r = x - eps; resx = x;
        } else {
            l = x + eps;
        }
    }
}

void solve2() {
    for (double l = -1, r = 1; l <= r; ) {
        y = (l + r) / 2; solve1();
        x = resx; solve0();
        if (b[n] <= maxb) {
            r = y - eps; ansx = x; ansy = y;
        } else {
            l = y + eps;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &maxa, &maxb);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
        if (p[i] < 0.5) {
            p[i] += eps * (rand() % 10000);
        } else {
            p[i] -= eps * (rand() % 10000);
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &q[i]);
        if (q[i] < 0.5) {
            q[i] += eps * (rand() % 10000);
        } else {
            q[i] -= eps * (rand() % 10000);
        }
    }
    solve2();
    x = ansx; y = ansy; solve0();
    printf("%.5f\n", f[n] + a[n] * x + b[n] * y);
    return 0;
} //