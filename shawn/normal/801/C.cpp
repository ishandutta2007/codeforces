#include <bits/stdc++.h>

using namespace std;

typedef double DB;

const DB eps = 1e-6;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
} 

const int N = 1e5 + 10;
long long a[N], b[N], sum, n, p;
DB ans;

bool chk(DB mid) {
	DB sum = p * mid;
	for (int i = 1; i <= n; i ++) {
		DB t = mid * a[i] - b[i];
		if (t > eps) sum -= t;
		if (sum < eps) return 0;
	}
	return 1;
}

int main() {
	n = rd(), p = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd(), b[i] = rd(), sum += a[i];
	if (sum <= p) return puts("-1"), 0;
	DB l = .0, r = 10000000000.;
	for (int i = 1; i <= 300; i ++) {
		DB mid = (l + r) / 2.;
		if (chk(mid)) ans = mid, l = mid;
		else r = mid;
	}
	if (ans == 0.) puts("-1");
	else printf("%.10lf", ans);
	return 0;
}