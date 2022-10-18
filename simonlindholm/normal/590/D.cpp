#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

vector<vi> solve(const vi& v) {
	int K = sz(v);
	int maxt = K*(K-1) / 2;
	vector<vi> res(K+1, vi(maxt+1, -(1 << 29)));
	res[0][0] = 0;
	rep(it,0,K) {
		int elem = v[it];
		for (int i = it+1; i --> 0;) {
			vi& in = res[i];
			vi& out = res[i+1];
			int takes = it - i;
			rep(t,0,maxt+1 - takes)
				out[t + takes] = max(out[t + takes], in[t] + elem);
		}
	}
	rep(i,0,K+1) {
		int best = -(1 << 29);
		rep(j,0,maxt+1) {
			res[i][j] = best = max(res[i][j], best);
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	int N, K, S;
	cin >> N >> K >> S;
	vi a(N), b, c;
	rep(i,0,N) cin >> a[i];
	int sumk = 0;
	rep(i,0,K) b.push_back(a[i]), sumk += a[i];
	rep(i,K,N) c.push_back(-a[i]);
	reverse(all(b));
	auto B = solve(b);
	auto C = solve(c);
	int res = 0;
	rep(bad,0,min(K, N-K)+1) {
		vi& B2 = B[bad];
		vi& C2 = C[bad];
		int lim = S - bad * bad;
		rep(t0,0,sz(B2)) {
			int t1 = min(lim - t0, sz(C2)-1);
			if (t1 < 0) continue;
			res = max(res, B2[t0] + C2[t1]);
		}
	}
	cout << sumk - res << endl;
}