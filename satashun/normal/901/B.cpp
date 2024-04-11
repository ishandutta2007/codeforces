#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
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

void out(const V<int>& v) {
	int d = v.size() - 1;
	cout << d << endl;
	rep(i, d+1) {
		cout << v[i] << (i == d ? '\n' : ' ');
	}
}

int main() {
	int n; cin >> n;

	VV<int> vec;
	vec.pb({1});
	vec.pb({0, 1});

	for (int i = 1; i <= n; ++i) {
		V<int> c(i + 2);
		rep(j, vec[i].size()) {
			c[j+1] += vec[i][j];
		}
		rep(j, vec[i-1].size()) {
			c[j] += vec[i-1][j];
		}
		for (auto &x : c) {
			x %= 2;
		}
		vec.pb(c);
	}
	out(vec[n]);
	out(vec[n-1]);
	return 0;
}