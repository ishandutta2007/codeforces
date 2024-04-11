#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using LL = long long;
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		vector<int> sd((int)s.size() + 1), sr((int)s.size() + 1);
		per(i, (int)s.size() - 1, 0) {
			sd[i] = sd[i + 1] + (s[i] == 'D');
			sr[i] = sr[i + 1] + (s[i] == 'R');
		}
		LL ans = s.size();
		int d = 1, r = 1;
		int okd = 0, okr = 0;
		rep(i, 0, (int)s.size() - 1) {
			if (s[i] == 'D') {
				if (okr) ans += n - 1 - sr[0];
				++d;
				okd = 1;
			} else {
				if (okd) ans += n - 1 - sd[0];
				++r;
				okr = 1;
			}
		}
		if (!okd || !okr) {
			ans = n;
		} else {
			ans += 1LL * (n - d + 1) * (n - r + 1);
		}
		printf("%lld\n", ans);
	}
}