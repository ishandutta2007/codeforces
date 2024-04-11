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

template<class T, class U> bool chmax(T& t, const U& u) { if (t < u) { t = u; return 1; } return 0; }
template<class T, class U> bool chmin(T& t, const U& u) { if (t > u) { t = u; return 1; } return 0; }

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

int cnt[1000];

int main() {
	int n; string s; cin >> n >> s;
	for (char c : s) {
		++cnt[c];
	}

	int one = cnt['n'], zero = cnt['z'];
	V<int> ans;
	rep(i, one) ans.pb(1);
	rep(i, zero) ans.pb(0);

	int sz = ans.size();
	rep(i, sz) printf("%d%c", ans[i], i == sz - 1 ? '\n' : ' ');


	return 0;
}