#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MD = 1000000009;

const int MAXN = 500100;
const int MAXK = 524288;

struct mt
{
    int a[2][2];
    void init(int aa, int bb, int cc, int dd) {
        a[0][0] = aa, a[0][1] = bb, a[1][0] = cc, a[1][1] = dd;
    }
};

mt
mult(const mt &a, const mt &b)
{
    mt res;
    res.init((1ll * a.a[0][0] * b.a[0][0] + 1ll * a.a[0][1] * b.a[1][0]) % MD,
            (1ll * a.a[0][0] * b.a[0][1] + 1ll * a.a[0][1] * b.a[1][1]) % MD,
            (1ll * a.a[1][0] * b.a[0][0] + 1ll * a.a[1][1] * b.a[1][0]) % MD,
            (1ll * a.a[1][0] * b.a[0][1] + 1ll * a.a[1][1] * b.a[1][1]) % MD);
    return res;
}

mt sm[MAXN];
int sum_cov[2 * MAXK];
int sum_beg[2 * MAXK][2];
int end_cnt[2 * MAXK];
int part_sum[MAXN];
int n, m;
int fib[MAXN];

inline void
add(int &dst, int src)
{
    dst += src;
    if (dst >= MD) {
        dst -= MD;
    }
}

inline void
sub(int &dst, int src)
{
    dst -= src;
    if (dst < 0) {
        dst += MD;
    }
}

void
precalc()
{
    sm[0].init(1, 0, 0, 1);
    sm[1].init(1, 1, 1, 0);
    for (int i = 2; i < MAXN; ++i) {
        sm[i] = mult(sm[i - 1], sm[1]);
    }
    fib[1] = fib[2] = 1;
    for (int i = 3; i < MAXN; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MD;
    }
}

void
addFib(int l, int r)
{
    for (int v = 1, f = 1, t = n + 1; f <= l && t >= r; ) {
        add(sum_cov[v], fib[r - l + 2]);
        sub(sum_cov[v], 1);
        if (f == t - 1) {
            break;
        }
        int mid = (f + t) / 2;
        v *= 2;
        if (r <= mid) {
            t = mid;
        } else if (l >= mid) {
            v++, f = mid;
        } else {
            break;
        }
    }
    for (int v = 1, f = 1, t = n + 1; ; ) {
        if (t < r) {
            for (int i = 0; i < 2; ++i) {
                add(sum_beg[v][i], fib[t - l + 2 - i]);
            }
            add(end_cnt[v], 1);
        }
        if (f == t - 1) {
            break;
        }
        int mid = (f + t) / 2;
        v *= 2;
        if (l >= mid) {
            v++, f = mid;
        } else {
            t = mid;
        }
    }
    for (int v = 1, f = 1, t = n + 1; ; ) {
        if (f > l) {
            add(sum_cov[v], fib[r - l + 2]);
            sub(sum_cov[v], 1);
            for (int i = 0; i < 2; ++i) {
                sub(sum_beg[v][i], fib[t - l + 2 - i]);
            }
            sub(end_cnt[v], 1);
        }
        if (f == t - 1) {
            break;
        }
        int mid = (f + t) / 2;
        v *= 2;
        if (r <= mid) {
            t = mid;
        } else {
            v++, f = mid;
        }
    }
}

int
getSum(int r)
{
    int a = 0, b = 0;
    int res = 0;
    int v, f, t;
    for (v = 1, f = 1, t = n + 1; ; ) {
        if (f == t - 1) {
            break;
        }
        int mid = (f + t) / 2;
        v *= 2;
        if (r > mid) {
            add(res, sum_cov[v]);
            const mt &mult_m = sm[mid - f];
            int ta = (1ll * mult_m.a[0][0] * a + 1ll * mult_m.a[0][1] * b) % MD;
            int tb = (1ll * mult_m.a[1][0] * a + 1ll * mult_m.a[1][1] * b) % MD;
            a = (ta + sum_beg[v][0]) % MD;
            b = (tb + sum_beg[v][1]) % MD;
            sub(res, end_cnt[v]);
            f = mid, v++;
        } else {
            t = mid;
        }
    }
    add(res, sum_cov[v]);
    const mt &mult_m = sm[t - f];
    a = (1ll * mult_m.a[0][0] * a + 1ll * mult_m.a[0][1] * b + sum_beg[v][0]) % MD;
    sub(res, end_cnt[v]);
    add(res, a);
    return res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    precalc();
    part_sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        cin >> cur;
        part_sum[i] = (part_sum[i - 1] + cur) % MD;
    }
    for (int i = 0; i < m; ++i) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp == 1) {
            addFib(l, r + 1);
        } else {
            int tmp = getSum(r + 1);
            if (l != 1) {
                sub(tmp, getSum(l));
            }
            add(tmp, part_sum[r]);
            sub(tmp, part_sum[l - 1]);
            cout << tmp << '\n';
        }
    }
    return 0;
}