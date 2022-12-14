#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;
int T, n;
ll x[N], y[N], z[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ll l0 = -3e18, r0 = 3e18, l1 = -3e18, r1 = 3e18, l2 = -3e18, r2 = 3e18, l3 = -3e18, r3 = 3e18;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld%lld%lld", x + i, y + i, z + i);
			l0 = max(l0, x[i] + y[i] + z[i]);
			r0 = min(r0, x[i] + y[i] + z[i]);
			l1 = max(l1, x[i] + y[i] - z[i]);
			r1 = min(r1, x[i] + y[i] - z[i]);
			l2 = max(l2, x[i] - y[i] + z[i]);
			r2 = min(r2, x[i] - y[i] + z[i]);
			l3 = max(l3, -x[i] + y[i] + z[i]);
			r3 = min(r3, -x[i] + y[i] + z[i]);
		}
		ll l = 0, r = 3e18, ansx = 0, ansy = 0, ansz = 0;
		while (l < r) {
			ll mid = (l + r) / 2;
			ll L0 = l0 - mid, R0 = r0 + mid, L1 = l1 - mid, R1 = r1 + mid, L2 = l2 - mid, R2 = r2 + mid, L3 = l3 - mid, R3 = r3 + mid;
			if (L0 % 2) ++L0; if (R0 % 2) --R0;
			if (L1 % 2) ++L1; if (R1 % 2) --R1;
			if (L2 % 2) ++L2; if (R2 % 2) --R2;
			if (L3 % 2) ++L3; if (R3 % 2) --R3;
			if ((double)L1 + L2 + L3 >= L0 - 1e18) {
				if ((double)L1 + L2 + L3 >= 9e18) L0 = 9e18;
				else L0 = max(L0, L1 + L2 + L3);
			}
			if ((double)R1 + R2 + R3 <= R0 + 1e18) {
				if ((double)R1 + R2 + R3 <= -9e18) R0 = -9e18;
				else R0 = min(R0, R1 + R2 + R3);
			}
			if (L0 <= R0 && L1 <= R1 && L2 <= R2 && L3 <= R3) {
				if (L1 + L2 + L3 < L0) {
					if (R1 + L2 + L3 >= L0)
						L1 = L0 - L2 - L3;
					else {
						L1 = R1;
						if (L1 + R2 + L3 >= L0)
							L2 = L0 - L1 - L3;
						else {
							L2 = R2;
							L3 = L0 - L1 - L2;
						}
					}
				}
				ansx = (L1 + L2) / 2, ansy = (L1 + L3) / 2, ansz = (L2 + L3) / 2;
				r = mid;
				continue;
			}
			L0 = l0 - mid, R0 = r0 + mid, L1 = l1 - mid, R1 = r1 + mid, L2 = l2 - mid, R2 = r2 + mid, L3 = l3 - mid, R3 = r3 + mid;
			if (L0 % 2 == 0) ++L0; if (R0 % 2 == 0) --R0;
			if (L1 % 2 == 0) ++L1; if (R1 % 2 == 0) --R1;
			if (L2 % 2 == 0) ++L2; if (R2 % 2 == 0) --R2;
			if (L3 % 2 == 0) ++L3; if (R3 % 2 == 0) --R3;
			if ((double)L1 + L2 + L3 >= L0 - 1e18) {
				if ((double)L1 + L2 + L3 >= 9e18) L0 = 9e18;
				else L0 = max(L0, L1 + L2 + L3);
			}
			if ((double)R1 + R2 + R3 <= R0 + 1e18) {
				if ((double)R1 + R2 + R3 <= -9e18) R0 = -9e18;
				else R0 = min(R0, R1 + R2 + R3);
			}
			if (L0 <= R0 && L1 <= R1 && L2 <= R2 && L3 <= R3) {
				if (L1 + L2 + L3 < L0) {
					if (R1 + L2 + L3 >= L0)
						L1 = L0 - L2 - L3;
					else {
						L1 = R1;
						if (L1 + R2 + L3 >= L0)
							L2 = L0 - L1 - L3;
						else {
							L2 = R2;
							L3 = L0 - L1 - L2;
						}
					}
				}
				ansx = (L1 + L2) / 2, ansy = (L1 + L3) / 2, ansz = (L2 + L3) / 2;
				r = mid;
				continue;
			}
			l = mid + 1;
		}
		printf("%lld %lld %lld\n", ansx, ansy, ansz);
	}
	return 0;
}