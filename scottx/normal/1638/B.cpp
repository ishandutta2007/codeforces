#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		int mx[2] = { 0, 0 };
		bool err = 0;
		rep(i, 0, n - 1) {
			scanf("%d", &a[i]);
			if (mx[a[i] & 1] > a[i]) {
				err = 1;
			}
			mx[a[i] & 1] = max(mx[a[i] & 1], a[i]);
		}
		puts(err ? "NO" : "YES");
	}
}