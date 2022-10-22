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
#define dump(x) cerr << #x << " = " << (x) << endl
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

const int B = 1500;
const int maxn = 200010;

int a[maxn];

int main() {
	string s; cin >> s;
	int n = s.size();
	V<int> v1;
	rep(i, n) {
		a[i+1] = a[i] + (s[i] == '1');
		if (s[i] == '1') v1.pb(i);
	}
	v1.pb(n);

	ll ans = 0;

	rep(l, n) {
		int p = lower_bound(ALL(v1), l) - v1.begin();

		for (int d = 1; d <= B; ++d) {
			if (v1[p] == n) break;
			int r = v1[p]+1, r2 = v1[p+1]+1;
			int tol = r;
			tol += (l % d - tol % d);
			if (tol < r) tol += d;

			if (tol < r2) {
				int num = (r2 - 1 - tol) / d + 1;
				ans += num;
			}

			++p;
		}
	}

	for (int k = 1; k <= n / B; ++k) {
		V<pair<ll,int>> vec(n+1);
		for (int i = 0; i <= n; ++i) {
			ll v = (ll)a[i]*k - (ll)i;
			vec[i] = mp(v, a[i]);
		}
		sort(ALL(vec));

		rep(j, vec.size()) {
			if (j == 0 || (vec[j-1].fi != vec[j].fi)) {
				V<int> vp;
				int k = j;
				while (k < vec.size() && vec[k].fi == vec[j].fi) {
					int num = lower_bound(ALL(vp), vec[k].se - B) - vp.begin();
					ans += num;
					vp.pb(vec[k].se);
					++k;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}