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

#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}
#define debug(...) cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

constexpr ll INF = TEN(18) * 3;

V<int> vec[3];

int main() {
	dump(INF);
	int TC; scanf("%d", &TC);
	while (TC--) {
		int n[3];
		rep(i, 3) cin >> n[i];
		rep(i, 3) {
			vec[i].resize(n[i]);
			rep(j, n[i]) {
				cin >> vec[i][j];
			}
			sort(ALL(vec[i]));
		}

		ll ans = INF;

		V<int> pm(3);
		iota(ALL(pm), 0);
		do {
			rep(j, n[pm[1]]) {
				ll y = vec[pm[1]][j];
				auto itl = upper_bound(ALL(vec[pm[0]]), y);
				auto itr = lower_bound(ALL(vec[pm[2]]), y);
				if (itl != vec[pm[0]].begin() and itr != vec[pm[2]].end()) {
					ll x = *(--itl);
					ll z = *itr;
					chmin(ans, (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z));
				}
			}
		} while (next_permutation(ALL(pm)));
		cout << ans << endl;
	}

	return 0;
}