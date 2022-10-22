#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		set<vector<int> > S;
		int tot = 0;
		while (1) {
			vector<int> a(n);
			iota(a.begin(), a.end(), 1);
			shuffle(a.begin(), a.end(), rng);
			bool err = 0;
			rep(i, 2, n - 1) if (a[i - 2] + a[i - 1] == a[i]) err = 1;
			if (err) continue;
			tot += S.insert(a).second;
			if (tot == n) break;
		}
		for (auto& x: S) {
			for (auto& y: x) printf("%d ", y);
			puts("");
		}
	}
}