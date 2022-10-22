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
#define dump(x) cout << #x << " = " << (x) << endl
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

int main() {
	int n; cin >> n;
	V<ll> b(n), a(n, -1);
	int p = -1; ll mx = -1;

	rep(i, n) {
		cin >> b[i];
		if (mx < b[i]) {
			mx = b[i];
			p = i;
		}
	}

	if (mx == 0) {
		puts("YES");
		rep(i, n) cout << 1 << (i == n - 1 ? '\n' : ' ');
		return 0;
	}

	bool ok = 0;
	int pp = p;

	rep(t, n) {
		int pr = (pp - 1 + n) % n;
		if (b[pr] != mx) {
			ok = 1;
			break;
		}
		pp = pr;
	}

	if (!ok) {
		puts("NO");
		return 0;
	}

	p = pp;
	ll la = mx;
	a[p] = b[p];

	rep(t, n-1) {
		int pr = (p - 1 + n) % n;
		la += b[pr];
		if (la == mx) {
			la += mx;
		}
		a[pr] = la;
		p = pr;
	}

	puts("YES");
	rep(i, n) cout << a[i] << (i == n - 1 ? '\n' : ' ');

	return 0;
}