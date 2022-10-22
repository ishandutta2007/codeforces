#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		rep(i, 0, n - 1) scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		printf("%d\n", a[n - 1] + a[n - 2]);
	}
}