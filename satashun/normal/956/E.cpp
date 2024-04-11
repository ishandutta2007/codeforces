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

bool dp[10010]; //only not important

const int M = 10001;

int dp2[10010];

int main() {
	int n, l, r; cin >> n >> l >> r;
	int s = 0;

	V<int> a(n);

	rep(i, n) {
		cin >> a[i];
		s += a[i];
	}

	V<int> v1, v2;

	rep(i, n) {
		int b; cin >> b;
		if (b == 0) {
			v2.pb(a[i]);
		} else {
			v1.pb(a[i]);
		}
	}

	{
		int sz = v2.size();
		bitset<M> bt;
		bt.set(0);
		for (int x : v2) {
			bt |= (bt << x);
		}

		for (int i = 0; i < M; ++i) {
			dp[i] = bt[i];
		}
	}

	tie(l, r) = mp(s - r, s - l);
	dump(mp(l, r));

	sort(ALL(v1));
	int sz = v1.size();
	rep(i, sz) {
		for (int j = r; j >= v1[i]; --j) {
			if (j - v1[i] <= r - l) {
				chmax(dp2[j], dp2[j-v1[i]] + 1);
			} else {
				chmax(dp2[j], dp2[j-v1[i]]);
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= r; ++j) {
		if (dp[r-j]) {
			chmax(ans, dp2[j]);
		}
	}
	cout << ans << endl;

	return 0;
}