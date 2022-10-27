#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		vector<int> v1, v2;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			if (a[i] < 0) v1.push_back(a[i]); else v2.push_back(a[i]);
		}
		sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
		LL ans = -1e18;
		for (int i = 0; i <= 5; i ++) {
			// printf("i = %d\n", i);
			LL f[2], g[2];
			// i, 5 - i;
			if (i <= v1.size() && 5 - i <= v2.size()) {
				f[0] = 1;
				for (int x = 0; x < i; x ++) f[0] *= v1[x];
				f[1] = 1;
				if(v1.size())
					for (int x = (int)v1.size() - 1; x >= (int)v1.size() - i; x --) f[1] *= v1[x];
				
				// printf("ok %lld\n", f[0]);
				g[0] = 1;
				for (int x = 0; x < 5 - i; x ++) g[0] *= v2[x];
				g[1] = 1;
				if (v2.size())
					for (int x = (int)v2.size() - 1; x >= (int)v2.size() - (5 - i); x --) g[1] *= v2[x];

				for (int ii = 0; ii < 2; ii ++) for (int jj = 0; jj < 2; jj ++)
					ans = max(ans, f[ii] * g[jj]);

			}
		}
		printf("%lld\n", ans);
	}
}