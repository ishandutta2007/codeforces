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

void out(const V<int>& vec) {
	int sz = vec.size();
	rep(i, sz) {
		printf("%d%c", vec[i] + 1, i == sz - 1 ? '\n' : ' ');
	}
}

int main() {
	int h; cin >> h;
	V<int> a(h + 1);

	for (int i = 0; i <= h; ++i) {
		cin >> a[i];
	}

	V<pii> v(h + 1);
	int now = 0;
	rep(i, h + 1) {
		v[i].fi = now;
		now += a[i];
		v[i].se = now;
	}

	V<int> par(now, -1);
	for (int i = 1; i <= h; ++i) {
		for (int j = v[i].fi; j < v[i].se; ++j) {
			par[j] = v[i-1].fi;
		} 
	}

	rep(i, h) {
		if (a[i] >= 2 && a[i+1] >= 2) {
			V<int> par2 = par;
			par2[v[i+1].fi] = v[i].fi + 1;
			puts("ambiguous");
			out(par);
			out(par2);
			return 0;
		}
	}
	puts("perfect");

	return 0;
}