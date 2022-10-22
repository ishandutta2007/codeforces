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
		int n, x;
		scanf("%d%d", &n, &x);
		multiset<long long> S;
		rep(i, 0, n - 1) {
			int t;
			scanf("%d", &t);
			S.insert(t);
		}
		int ans = 0;
		while (!S.empty()) {
			long long u = *S.begin();
			S.erase(S.begin());
			if (S.count(u * x)) {
				S.erase(S.find(u * x));
			} else {
				++ans;
			}
		}
		cout << ans << endl;
	}
}