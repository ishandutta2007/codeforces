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

const int maxn = 150000;

int main() {
	int n; cin >> n;

	multiset<int> lx, rx, ly, ry;
	V<pair<pii, pii>> vec(n);

	rep(i, n) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vec[i] = mp(mp(a, b), mp(c, d));
		lx.insert(a);
		rx.insert(c);
		ly.insert(b);
		ry.insert(d);
	}

	rep(i, n) {
		int a, b, c, d;
		tie(a, b) = vec[i].fi;
		tie(c, d) = vec[i].se;
		lx.erase(lx.find(a));
		ly.erase(ly.find(b));
		rx.erase(rx.find(c));
		ry.erase(ry.find(d));

		if (*lx.rbegin() <= *rx.begin() && *ly.rbegin() <= *ry.begin()) {
			cout << *lx.rbegin() << " " << *ly.rbegin() << endl;
			return 0;
		}
		lx.insert(a);
		rx.insert(c);
		ly.insert(b);
		ry.insert(d);
	}
	
	return 0;
}