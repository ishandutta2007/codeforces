#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll k, d, t, x;

int main() {
    cin >> k >> d >> t;
    x = (k + d - 1) / d * d;
    t *= 2;
    ll rlt = t / (x + k) * 2 * x;
    ll y = t % (x + k);
    if (y < 2 * k) rlt += y;
    else rlt += 2 * k + (y - 2 * k) * 2;
    printf("%.12lf\n", 0.5 * rlt);
}