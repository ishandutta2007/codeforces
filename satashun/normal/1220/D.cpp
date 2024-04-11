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

template<class T, class U> bool chmax(T& t, const U& u) { if (t < u) { t = u; return 1; } else {return 0; }}
template<class T, class U> bool chmin(T& t, const U& u) { if (t > u) { t = u; return 1; } else {return 0; }}

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

int main() {
	int n; cin >> n;
	V<ll> b(n);
	rep(i, n) cin >> b[i];

	VV<int> vx(100);
	rep(i, n) {
		ll x = b[i];
		int k = 0;
		while (x % 2 == 0) {
			x /= 2;
			++k;
		}
		dump(k);
		vx[k].pb(i);
	}

	int mx = -1, p = -1;
	rep(i, 100) {
		if (mx < (int)vx[i].size()) {
			mx = (int)vx[i].size();
			p = i;
		}
	}
	dump(p);
	V<int> use(n);
	for (int i : vx[p]) {
		use[i] = 1;
	}

	int sz = n - (int)vx[p].size();
	cout << sz << endl;

	rep(i, n) {
		if (!use[i]) {
			--sz;
			cout << b[i] << (sz == 0 ? '\n' : ' ');
		}
	}

	return 0;
}