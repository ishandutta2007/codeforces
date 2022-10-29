#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <functional>

using namespace std;

#define maxn 3005000

typedef long long ll;

int n, l, t;
ll a[maxn];

int getAns(ll a, ll b) {
	if (a + 2 * t < b) return 0;
	return (a + 2 * t - b) / l + 1;
}

int main() {
	scanf("%d%d%d", &n, &l, &t);
	for (int i = 0; i < n; ++i) {
		int cur;
		scanf("%d", &cur);
		a[i] = cur;
		a[i + n] = cur + l;
	}
	double ans = 0.0;
	if (n == 1) {
		printf("0.0\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		int cntMin, cntMax;
		if (a[i] + 2 * t < a[i + 1])
			cntMax = 0;
		else
			cntMax = (a[i] + 2 * t - a[i + 1]) / l + 1;
		if (a[i] + 2 * t < a[i + n - 1])
			cntMin = 0;
		else
			cntMin = (a[i] + 2 * t - a[i + n - 1]) / l + 1;
		if (cntMax == cntMin) {
			ans += 1. * (n - 1) * cntMax / 2.;
			continue;
		}
		int ll1 = 1, rr = n - 1;
		while (ll1 < rr - 1) {
			int mm = (ll1 + rr) / 2;
			if (getAns(a[i], a[i + mm]) == cntMax)
				ll1 = mm;
			else
				rr = mm;
		}
		ans += 1. * ll1 * cntMax / 2. + 
			1. * (n - rr) * cntMin / 2.; 
	}
	printf("%.16lf\n", ans / 2.);
	return 0;
}