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
	V<pair<pii, pii>> vec;
	V<int> alive(n);
	rep(i, n) alive[i] = 1;

	vector<pii> ans;

	rep(i, n) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vec.eb(mp(a, b), mp(c, i));
	}

	sort(ALL(vec));

	rep(i, n-1) {
		if (vec[i].fi == vec[i+1].fi) {
			int a = vec[i].se.se;
			int b = vec[i+1].se.se;
			alive[a] = 0;
			alive[b] = 0;
			ans.eb(a, b);
			i++;
		}
	}

	{
		V<pair<pii, pii>> nx;
		for (auto &t : vec) if (alive[t.se.se]) {
			nx.eb(t);
		}
		vec = nx;
	}

	int sz = vec.size();
	rep(i, sz-1) {
		if (vec[i].fi.fi == vec[i+1].fi.fi) {
			int a = vec[i].se.se;
			int b = vec[i+1].se.se;
			alive[a] = 0;
			alive[b] = 0;
			ans.eb(a, b);
			i++;
		}
	}

	{
		V<pair<pii, pii>> nx;
		for (auto &t : vec) if (alive[t.se.se]) {
			nx.eb(t);
		}
		vec = nx;
	}

	sz = vec.size();

	for (int i = 0; i < (int)vec.size(); i += 2) {
		int a = vec[i].se.se;
		int b = vec[i+1].se.se;
		ans.eb(a, b);
	}

	for (auto &p : ans) {
		printf("%d %d\n", p.fi + 1, p.se + 1);
	}

	return 0;
}