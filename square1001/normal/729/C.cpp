#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;
int n, m; ll s, t, c[200009], v[200009], p[200009];
int main() {
	scanf("%d%d%lld%lld", &n, &m, &s, &t);
	for (int i = 0; i < n; i++) scanf("%lld%lld", &c[i], &v[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &p[i]); p[m + 1] = s;
	sort(p, p + m + 2);
	vector<ll> x;
	for (int i = 0; i <= m; i++) x.push_back((p[i + 1] - p[i]) * 2);
	sort(x.begin(), x.end());
	vector<ll> sum(m + 2);
	for (int i = 0; i <= m; i++) sum[i + 1] = sum[i] + x[i];
	ll ret = 1LL << 60;
	for (int i = 0; i < n; i++) {
		if (x[m] > 2 * v[i]) continue;
		int ptr = lower_bound(x.begin(), x.end(), v[i]) - x.begin();
		ll t2 = (sum[ptr] >> 1) + 3 * (s - (sum[ptr] >> 1)) - (m + 1 - ptr) * v[i];
		if(t2 <= t) ret = min(ret, c[i]);
	}
	printf("%lld\n", (ret != (1LL << 60) ? ret : -1));
	return 0;
}