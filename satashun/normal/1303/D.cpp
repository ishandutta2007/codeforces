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

int main() {
	int TC; cin >> TC;
	while (TC--) {
		ll n; int m; cin >> n >> m;
		V<int> a(m);
		ll s = 0;
		rep(i, m) {
			cin >> a[i];
			s += a[i];
		}
		if (s < n) {
			puts("-1");
			continue;
		}

		V<int> cnt(64);
		rep(i, m) {
			int c = 0;
			int x = a[i];
			while (x % 2 == 0) {
				x /= 2;
				++c;
			}
			++cnt[c];
		}

		ll ans = 0;

		rep(i, 60) {
			if ((n >> i) & 1) {
				if (cnt[i] == 0) {
					for (int j = i + 1; j < 64; ++j) {
						if (cnt[j] > 0) {
							--cnt[j];
							cnt[i] += 2;
							ans += j - i;
							for (int k = i + 1; k < j; ++k) {
								++cnt[k];
							}
							break;
						}
					}
				}
				cnt[i]--;
			}
			cnt[i+1] += cnt[i] / 2;
		}
		cout << ans << endl;
	}
	return 0;
}