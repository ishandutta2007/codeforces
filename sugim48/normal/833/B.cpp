#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;

template <class Unko>
struct segtree {
	using T1 = typename Unko::T1;
	using T2 = typename Unko::T2;
	int N, H;
	vector<T1> a;
	vector<T2> b;
	segtree(int _N, vector<T1> &a0) {
		for (N = 1, H = 0; N < _N; N *= 2, H++);
		a.resize(N * 2);
		copy(a0.begin(), a0.end(), a.begin() + N);
		for (int i = N - 1; i; i--)
			a[i] = Unko::op11(a[i << 1], a[i << 1 | 1]);
		b.assign(N * 2, Unko::id2());
	}
	void up(int i) {
		while (i >>= 1) {
			T1 xl = Unko::op21(b[i << 1], a[i << 1]);
			T1 xr = Unko::op21(b[i << 1 | 1], a[i << 1 | 1]);
			a[i] = Unko::op11(xl, xr);
		}
	}
	void down(int i0) {
		for (int h = H; h > 0; h--) {
			int i = i0 >> h;
			a[i] = Unko::op21(b[i], a[i]);
			b[i << 1] = Unko::op22(b[i], b[i << 1]);
			b[i << 1 | 1] = Unko::op22(b[i], b[i << 1 | 1]);
			b[i] = Unko::id2();
		}
	}
	T1 get(int l, int r) {
		if (l == r) return Unko::id1();
		l += N; r += N;
		down(l); down(r - 1);
		T1 xl = Unko::id1(), xr = Unko::id1();
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) xl = Unko::op11(xl, Unko::op21(b[l], a[l])), l++;
			if (r & 1) r--, xr = Unko::op11(Unko::op21(b[r], a[r]), xr);
		}
		return Unko::op11(xl, xr);
	}
	void set(int l0, int r0, T2 y) {
		if (l0 == r0) return;
		l0 += N; r0 += N;
		down(l0); down(r0 - 1);
		for (int l = l0, r = r0; l < r; l >>= 1, r >>= 1) {
			if (l & 1) b[l] = Unko::op22(y, b[l]), l++;
			if (r & 1) r--, b[r] = Unko::op22(y, b[r]);
		}
		up(l0); up(r0 - 1);
	}
};

struct unko {
	using T1 = int;
	using T2 = int;
	static T1 id1() { return -INF; }
	static T2 id2() { return 0; }
	static T1 op11(const T1 &xl, const T1 &xr) {
		return max(xl, xr);
	}
	static T1 op21(const T2 &y, const T1 &x) {
		return x + y;
	}
	static T2 op22(const T2 &yl, const T2 &yr) {
		return yl + yr;
	}
};

int main() {
	int N, K; cin >> N >> K;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]), a[i]--;
	vector<int> dp(N + 1, -INF);
	dp[0] = 0;
	while (K--) {
		vector<int> prev(N, -1);
		segtree<unko> st(N + 1, dp);
		vector<int> _dp(N + 1);
		_dp[0] = -INF;
		rep(i, N) {
			int x = a[i];
			if (prev[x] != -1) st.set(0, prev[x] + 1, -1);
			st.set(0, i + 1, +1);
			prev[x] = i;
			_dp[i + 1] = st.get(0, i + 1);
		}
		dp = _dp;
	}
	cout << dp[N] << endl;
}