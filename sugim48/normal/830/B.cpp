#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const ll INF = INT_MAX;

struct bit {
	vector<int> v;
	bit(int n) : v(n + 1) {}
	int sum(int i) {
		int res = 0;
		for (; i > 0; i -= i & -i) res += v[i];
		return res;
	}
	void add(int i, int x) {
		for (i++; i < v.size(); i += i & -i) v[i] += x;
	}
};

template <class Monoid>
struct segtree {
	using T = typename Monoid::T;
	int N;
	vector<T> a;
	segtree(const vector<T> &a0) {
		for (N = 1; N < a0.size(); N <<= 1);
		a.resize(N << 1);
		copy(a0.begin(), a0.end(), a.begin() + N);
		for (int i = N - 1; i; i--)
			a[i] = Monoid::op(a[i << 1], a[i << 1 | 1]);
	}
	segtree(int N, const T &x = Monoid::id()) :
		segtree(vector<T>(N, x)) {}
	T get(int l, int r) {
		T xl = Monoid::id(), xr = Monoid::id();
		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) xl = Monoid::op(xl, a[l++]);
			if (r & 1) xr = Monoid::op(a[--r], xr);
		}
		return Monoid::op(xl, xr);
	}
	void set(int i, const T &x) {
		a[i += N] = x;
		while (i >>= 1) a[i] = Monoid::op(a[i << 1], a[i << 1 | 1]);
	}
};

struct monoid {
	using T = i_i;
	static T id() { return i_i(100001, -1); }
	static T op(const T &l, const T &r) {
		return min(l, r);
	}
};

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	bit b(N);
	rep(i, N) b.add(i, 1);
	segtree<monoid> st(N);
	rep(i, N) st.set(i, i_i(a[i], i));
	int t = N, l = 0;
	ll ans = 0;
	while (t) {
		i_i p = st.get(l, N);
		int i = p.second;
		if (p.first != st.get(0, N).first) {
			ans += b.sum(N) - b.sum(l);
			l = 0;
		}
		else {
			ans += b.sum(i + 1) - b.sum(l);
			b.add(i, -1);
			st.set(i, i_i(100001, -1));
			t--;
			l = i + 1;
		}
	}
	cout << ans << endl;
}