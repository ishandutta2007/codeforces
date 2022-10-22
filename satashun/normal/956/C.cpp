#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int INF = TEN(9);

int main() {
	int n; cin >> n;
	V<int> m(n); rep(i, n) cin >> m[i];

	V<int> mx(n+1);
	rep(i, n) mx[i] = m[i] - i;
	mx[n] = -INF;
	for (int i = n-1; i >= 0; --i) {
		chmax(mx[i], mx[i+1]);
	}

	ll s = 0;
	int cnt = 0;

	rep(i, n) {
		if (cnt == m[i]) {
			++cnt;
		} else if (mx[i+1] <= cnt - i - 1) {
			s += cnt - m[i] - 1;
		} else {
			s += cnt - m[i];
			++cnt;
		}
	}
	cout << s << endl;

	return 0;
}