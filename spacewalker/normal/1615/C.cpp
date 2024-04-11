#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 100010;

char src[NMAX], dst[NMAX], sflip[NMAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		scanf("%s", src); scanf("%s", dst);
		int ans = NMAX;
		// case 1: needs even number
		int o2z = 0, z2o = 0;
		for (int i = 0; i < n; ++i) {
			if (src[i] == '0' && dst[i] == '1') ++z2o;
			if (src[i] == '1' && dst[i] == '0') ++o2z;
		}
		if (o2z == z2o) ans = min(ans, o2z + z2o);
		// case 2: needs odd number
		for (int i = 0; i < n; ++i) {
			sflip[i] = (src[i] == '0' ? '1' : '0');
		}
		o2z = 0, z2o = 0;
		int hz = 0, ho = 0;
		for (int i = 0; i < n; ++i) {
			if (sflip[i] == '0') {
				(dst[i] == '0' ? hz : z2o)++;
			} else if (sflip[i] == '1') {
				(dst[i] == '1' ? ho : o2z)++;
			}
		}
		if (z2o - o2z == 1) ans = min(ans, z2o + o2z);
		if (ans == NMAX) printf("-1\n");
		else printf("%d\n", ans);
	}
}