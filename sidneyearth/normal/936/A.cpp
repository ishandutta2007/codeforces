#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll k, d, t;
	scanf("%I64d%I64d%I64d", &k, &d, &t);
	ll p = (k + d - 1) / d * d;
	ll q = (2 * t) / (p + k);
	double ans = (double)p * q;
	ans += min((double)k / t, 1 - ((double)p + k) / (2.0 * t) * q) * t;
	ans += max(0.0, 1 - (p + k) / (2.0 * t) * q - (double)k / t) * (2 * t);
	printf("%.12lf\n", ans);
	return 0;
}