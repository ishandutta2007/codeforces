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
	string S; cin >> S;
	V<pii> vec;

	for (char c : S) {
		if (vec.size() == 0 || vec.back().fi != c) {
			vec.eb(c, 1);
		} else {
			vec.back().se++;
		}
	}

	int sz = vec.size();
	int ans = 0;
	if (sz & 1) {
		bool ok = (vec[sz / 2].se >= 2);
		rep(i, sz/2) {
			if (vec[i].fi == vec[sz-1-i].fi && vec[i].se + vec[sz-1-i].se >= 3) {
				//;
			} else {
				ok = 0;
			}
		}
		if (ok) {
			ans = vec[sz/2].se + 1;
		}
	}
	cout << ans << endl;

	return 0;
}