#include <stdio.h>
#define ll long long

ll k, d, t;

int main() {
    scanf("%I64d %I64d %I64d", &k, &d, &t);
    ll up = (k + d - 1) / d * d, T = 2 * t, spd = up + k;
    ll g = T / spd; T -= spd * g;
    double ans;
    if (T <= k * 2) ans = g * up + 1.0 * T / 2;
    else ans = g * up + k + 1.0 * (T - 2 * k);
    printf("%.1lf\n", ans);
	return 0;
}