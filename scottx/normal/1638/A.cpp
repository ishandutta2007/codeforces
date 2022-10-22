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
		rep(i, 0, n - 1) scanf("%d", &a[i]);
		int pos = -1;
		rep(i, 0, n - 1) if (a[i] != i + 1) {
			pos = i;
			break;
		}
		if (pos != -1) {
			rep(i, 0, n - 1) if (a[i] == pos + 1) {
				reverse(a.begin() + pos, a.begin() + i + 1);
				break;
			}
		}
		for (auto& x: a) printf("%d ", x);
		puts("");
	}
}