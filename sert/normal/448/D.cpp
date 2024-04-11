#include <cstdio>
#include <cmath>
//#include <ctime>

#define max(a, b) (a > b ? a : b)

const double EPS = 5e-9;
int nn, mm;

long long cnt(long long y) {
    long long ans = 0;
    double x1, x2;
    int c1, c2;
    for (long long c = 2; c <= nn + mm; c++) {
        if ((c / 2) * (c - c / 2) <= y)
            continue;
        x2 = sqrtl(c * c - 4.0 * y);
        x1 = (c - x2) * 0.5;
        x2 = (c + x2) * 0.5;
        //cout << c << " " << x1 << " " << x2 << "\n";
        c1 = x1 + EPS;
        c2 = x2 - EPS;
        c1++;
        c1 += max(0, int(c) - c1 - nn);;
        c2 -= max(0, c2 - mm);

        ans += max(0, c2 - c1 + 1);
    }
    return ans;
}

int main() {
    long long n, m;
    long long k;
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    nn = n;
    mm = m;
    /*for (int i = 1; i <= n * m; i++) {
        cout << i << " " << cnt(i) << "\n";
    }*/

    long long l, r;
    l = 0;
    r = n * m;
    while (r - l > 1) {
        if (cnt((l + r) / 2) + k <= n * m)
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    printf("%I64d\n", r);
    //printf("%d", clock());
    return 0;
}