#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vi par(N), dep(N, 1), s(N);
	rep(i,1,N) cin >> par[i], --par[i];
	rep(i,0,N) cin >> s[i];
	rep(i,1,N) dep[i] = dep[par[i]] + 1;
	vi minch(N, INT_MAX);
	rep(i,1,N) {
		minch[par[i]] = min(minch[par[i]], s[i]);
	}
	rep(i,1,N) if (dep[i] % 2 == 0) {
		int a;
		if (minch[i] == INT_MAX) a = 0;
		else {
			a = minch[i] - s[par[i]];
			if (a < 0) {
				cout << -1 << endl;
				return 0;
			}
		}
		s[i] = a + s[par[i]];
	}

	ll res = 0;
	rep(i,0,N) {
		int a = (i == 0 ? s[i] : s[i] - s[par[i]]);
		res += a;
	}
	cout << res << endl;

	exit(0);
}