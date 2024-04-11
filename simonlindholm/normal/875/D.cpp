#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 0;

template <class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = jmp[i][j] |
			jmp[i][min(N - 1, j + (1 << i))];
	}

	T query(int a, int b) {
		if (b <= a) return inf;
		int dep = 31 - __builtin_clz(b - a);
		return jmp[dep][a] | jmp[dep][b - (1 << dep)];
	}
};

template <class T>
struct RMQ2 {
	vector<vector<T>> jmp;

	RMQ2(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = max(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
		assert(a < b);
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};


template<class F, class G, class T>
void rec(int from, int to, F f, G g, int& i, T& p, T q) {
	if (p == q) return;
	if (from == to) {
		g(i, to, p);
		i = to; p = q;
	} else {
		int mid = (from + to) >> 1;
		rec(from, mid, f, g, i, p, f(mid));
		rec(mid+1, to, f, g, i, p, q);
	}
}
template<class F, class G>
void constantIntervals(int from, int to, F f, G g) {
	if (to <= from) return;
	int i = from; auto p = f(i), q = f(to-1);
	rec(from, to-1, f, g, i, p, q);
	g(i, to, q);
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vi v(N);
	vector<pii> v2(N);
	rep(i,0,N) {
		cin >> v[i];
		v2[i] = pii(v[i], -i);
	}
	RMQ<int> rmq(v);
	RMQ2<pii> rmq2(v2);

	ll res = 0;
	rep(l,0,N) {
		constantIntervals(l+1, N, [&](int b) {
			return rmq.query(l, b+1);
		}, [&](int a, int b, int val) {
			// in [a,b), or is 'val'
			pii ma = rmq2.query(l, b);
			int ind = -ma.second;
			if (ma.first != val) ind = b;
			res += max(ind - a, 0);
		});
	}
	cout << res << endl;
	exit(0);
}