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
	int N, K;
	cin >> N >> K;
	int lim = (N + K-1 - 1) / (K - 1);
	vi cap(N*K);
	vi done(N);
	vector<pii> ans(N);
	vi prev(N, -1);
	rep(i,0,N*K) {
		int x;
		cin >> x;
		--x;
		if (done[x]) continue;
		if (prev[x] == -1) {
			prev[x] = i;
			continue;
		}
		for (int j = prev[x]; j <= i; j++) if (cap[j] == lim) goto fail;
		for (int j = prev[x]; j <= i; j++) cap[j]++;
		done[x] = 1;
		ans[x] = {prev[x], i};
fail:
		prev[x] = i;
	}
	rep(i,0,N) {
		assert(done[i]);
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
	}
	exit(0);
}