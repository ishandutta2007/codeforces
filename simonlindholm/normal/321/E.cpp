#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;

struct DP {
	vector<vi>& sums;
	DP(vector<vi>& sums) : sums(sums) {}
	vi old, res;

	int lo(int ind) { return 0; }
	int hi(int ind) { return ind; }
	ll f(int ind, int k) { assert(k <= ind); return old[k] + sums[k][ind]; }
	void store(int ind, int k, ll v) { res[ind] = (int)v; }

	void rec(int L, int R, int LO, int HI) {
		if (L >= R) return;
		int mid = (L + R) >> 1;
		pair<ll, int> best(1LL << 60, LO);
		rep(k,max(LO, lo(mid)),min(HI, hi(mid))+1)
			best = min(best, make_pair(f(mid, k), k));
		store(mid, best.second, best.first);
		rec(L, mid, LO, best.second);
		rec(mid+1, R, best.second, HI);
	}
	void solve(int l, int r) { rec(l, r, INT_MIN, INT_MAX); }
};

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int K;
	cin >> N >> K;
	cin.ignore(100, '\n');
	vector<vi> a(N, vi(N)), sums1(N+1, vi(N+1)), sums = sums1;
	rep(i,0,N) {
		rep(j,0,N)
			a[i][j] = cin.get() - '0', cin.ignore();
	}

	rep(i,1,N+1) {
		rep(j,1,N+1) {
			sums1[i][j] = sums1[i-1][j] + sums1[i][j-1] - sums1[i-1][j-1] + a[i-1][j-1];
		}
	}

	rep(i,0,N+1) {
		rep(j,i,N+1) {
			sums[i][j] = sums1[j][j] - sums1[i][j] - sums1[j][i] + sums1[i][i];
		}
	}

	DP dp(sums);
	int inf = 1 << 29;
	dp.old.assign(N+1, inf);
	dp.old[0] = 0;
	dp.res = dp.old;
	rep(k,0,K) {
		dp.solve(0, N+1);
		dp.res.swap(dp.old);
	}
	int res = dp.old[N];
	assert(res % 2 == 0);
	res /= 2;
	cout << res << endl;
}