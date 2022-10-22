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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		V<int> cnt(n), ims(n + 1), acm(n + 1);

		rep(i, n) {
			int x; cin >> x;
			--x;
			++cnt[x];
		}

		rep(i, n) if (cnt[i]) {
			++ims[cnt[i]];
			acm[cnt[i]] += cnt[i];
		}

		for (int i = 1; i <= n; ++i) {
			ims[i] += ims[i-1];
			acm[i] += acm[i-1];
		}

		int ans = n;
		for (int x = 2; x <= n; ++x) {
			int a = 0;
			int p = 0;
			int la = -1;

			for (int num = 1; num * x - num <= n; ++num) {
				int l = max(0, num * x - num - 1), r = min(n, num * x);
				chmax(l, la);
				chmax(r, l);
				if (la > l) break;
				a += num * (ims[r] - ims[l]);
				p += acm[r] - acm[l];
				la = r;
			}
			if (p == n) {
				chmin(ans, a);
			}
		}
		cout << ans << endl;
	}

	return 0;
}