#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const long double EPS = 1e-12;

int mn, mx, n;
long double p[N];

long double f(long double x) {
    mn = mx = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] - x * i > p[mx] - x * mx)
            mx = i;
        if (p[i] - x * i < p[mn] - x * mn)
            mn = i;
    }
    return (p[mx] - x * mx) - (p[mn] - x * mn);
}

long double l, r, m1, m2, f1, f2;
int a[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i + 1] = p[i] + a[i];
    }

    l = -120000;
    r = 120000;

    //cout << f(2.5) << "\n";
    //cout << f(3) << "\n";
    //return 0;

    while (clock() < 1200) {
        m1 = (l + l + r) / 3.0;
        m2 = (l + r + r) / 3.0;
        f1 = f(m1);
        f2 = f(m2);
        if (f1 < f2)
            r = m2;
        else
            l = m1;
    }

    cout.precision(10);
    cout << fixed << f((l + r) / 2.0);
    //cout << "\n" << l << "\n";

    return 0;
}