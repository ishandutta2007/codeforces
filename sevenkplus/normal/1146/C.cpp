#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

int main() {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		int S = 0;
		for (int l = 0; l < 9; l ++) {
			vector<int> s, t;
			for (int i = 0; i < n; i ++)
				if ((i>>l)&1) s.pb(i); else t.pb(i);
			if (s.empty() || t.empty()) continue;
			printf("%d %d", (int) s.size(), (int) t.size());
			for (auto i : s) printf(" %d", i+1);
			for (auto i : t) printf(" %d", i+1);
			puts("");
			fflush(stdout);
			int T;
			cin >> T;
			if (T == -1) return 0;
			S = max(S, T);
		}
		printf("-1 %d\n", S);
		fflush(stdout);
	}
	return 0;
}