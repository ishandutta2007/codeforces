#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 100005, B = 350;
int ans, n, a[N], v[N];
int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	scanf("%d", &n);
	rep(i, 0, n - 1) scanf("%d", &a[i]);
	rep(d, -B, B) {
		rep(i, 0, n - 1) {
			v[i] = a[i] - d * i;
		}
		sort(v, v + n);
		for (int i = 0, j; i < n; i = j) {
			j = i + 1;
			while (j < n && v[i] == v[j]) ++j;
			ans = max(ans, j - i);
		}
	}
	rep(i, 0, n - 1) {
		int l = 0;
		for (int j = i + 1; j < n && j < i + B; ++j) {
			if ((a[j] - a[i]) % (j - i) == 0) {
				v[l++] = (a[j] - a[i]) / (j - i);
			}
		}
		sort(v, v + l);
		for (int i = 0, j; i < l; i = j) {
			j = i + 1;
			while (j < l && v[i] == v[j]) ++j;
			ans = max(ans, j - i + 1);
		}
	}
	printf("%d\n", n - ans);
}