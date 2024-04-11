#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<double, int> d_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const ll INF = LLONG_MAX / 2;
const int MOD = 1e9 + 7;

int main() {
	int N, K; cin >> N >> K;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]), a[i]--;
	vector<ll> dp(N + 1, INF);
	dp[0] = 0;
	while (K--) {
		vector<ll> _dp(N + 1);
		vector<i_i> lrs;
		lrs.pb(i_i(0, N + 1));
		vector<int> opti(N + 2);
		opti[0] = 0, opti[N + 1] = N;
		while (!lrs.empty()) {
			vector<int> ms, lbs, ubs;
			vector<i_i> _lrs;
			for (i_i lr: lrs) {
				int l = lr.first, r = lr.second;
				if (r - l > 1) {
					int m = (l + r) / 2;
					ms.pb(m);
					lbs.pb(opti[l]);
					ubs.pb(opti[r]);
					_lrs.pb(i_i(l, m));
					_lrs.pb(i_i(m, r));
				}
			}
			lrs = _lrs;
			int l = 0, k = 0;
			vector<int> b(N);
			ll cost = 0;
			rep(r, N + 1) {
				for (; k < ms.size() && ms[k] == r; k++) {
					ll mi = INF;
					for (;;) {
						if (dp[l] + cost < mi) {
							mi = dp[l] + cost;
							opti[ms[k]] = l;
						}
						if (l == ubs[k]) break;
						if (l < N) {
							b[a[l]]--;
							cost -= b[a[l]];
							l++;
						}
					}
					_dp[ms[k]] = mi;
				}
				if (r < N) {
					cost += b[a[r]];
					b[a[r]]++;
				}
			}
		}
		dp = _dp;
	}
	cout << dp[N] << endl;
}