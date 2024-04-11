#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int N, M, K;
	cin >> N >> M >> K;
	string str;
	cin >> str;
	vi counts(26);
	trav(c, str) counts[c - 'A']++;
	ll res = LLONG_MAX;
	rep(i,0,26) {
		vi dp(N+1);
		dp[0] = 1;
		rep(j,0,26) if (j != i) {
			int co = counts[j];
			for (int k = N - co; k >= 0; k--) {
				if (dp[k]) dp[k + co] = 1;
			}
		}
		int co = counts[i];
		rep(i,0,N+1) if (dp[i]) {
			int ma = i;
			if (ma + co < N) continue; // can't split the middle with this
			ll left = N - ma;
			ll right = M - (K - (ma + co));
			right = max(right, 0LL);
			res = min(res, left * right);
		}
	}
	assert(res != LLONG_MAX);
	cout << res << endl;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	rep(i,0,N) solve();
}