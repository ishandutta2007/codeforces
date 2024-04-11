#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 35000000;
const int MD = 1051131;
const int rev2 = 525566;

int a[MAXN];
int m, s;
ll t;
int mult_coeff;

int
powMod(int x, ll st)
{
    int res = 1;
    while (st) {
        if (st & 1) {
            res = 1ll * res * x % MD;
        }
        st /= 2;
        x = 1ll * x * x % MD;
    }
    return res;
}

void
flip(int *a, int sz)
{
    for (int i = 0, *f = a, *s = a + sz; i < sz; ++i, ++f, ++s) {
        *f += *s;
        *s = *f - 2 * *s + MD;
        if (*f >= MD) {
            *f -= MD;
        }
        if (*s >= MD) {
            *s -= MD;
        }
    }
}

void
getMult(int *a, int m, int k, ll t)
{
    if (m == 0) {
        *a = 1ll * (*a) * powMod((1 + 1ll * k * rev2) % MD, t) % MD;
    } else {
        int half = 1 << (m - 1);
        flip(a, half);
        int kprime = (powMod(2, m - 1) + MD - 1) % MD;
        kprime = (kprime - 1ll * rev2 * k % MD + MD) % MD;
        getMult(a, m - 1, (k + kprime) % MD, t);
        for (int i = 0, *f = a; i < half; ++i, ++f) {
            *f = 1ll * (*f) * mult_coeff % MD;
        }
        kprime = 1ll * powMod((MD - kprime) % MD, t) * rev2 % MD;
        for (int i = 0, *f = a + half; i < half; ++i, ++f) {
            *f = 1ll * (*f) * kprime % MD;
        }
        flip(a, half);
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> t >> s;
    mult_coeff = powMod(2, t - 1);
    for (int i = 0; i < s; ++i) {
        cin >> a[i];
    }
    for (int i = s; i < (1 << m); ++i) {
        a[i] = (101 * a[i - s] + 10007) % MD;
    }
    getMult(a, m, 0, t);
    int res = 0;
    for (int i = 0; i < (1 << m); ++i) {
        res ^= a[i];
    }
    cout << res << '\n';
    return 0;
}