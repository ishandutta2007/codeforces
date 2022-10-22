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

const ll MOD = TEN(9) + 7;

int main() {
	int TC; cin >> TC;
	while (TC--) {
		int x; string s;
		cin >> x >> s;
		ll len = s.size();
		bool flg = (s.size() >= x);

		rep(i, x) {
			int num = s[i] - '0';
			if (!flg) {
				int cl = s.size();
				rep(tt, num-1) {
					for (int j = i + 1; j < cl; ++j) {
						s.pb(s[j]);
					}
				}
				len = s.size();
				if (len >= x) {
					flg = 1;
				}
			} else {
				len += (num - 1) * (len - i - 1);
				len %= MOD;
				if (len < 0) len += MOD;
			}
		}
		printf("%lld\n", len);
	}
	return 0;
}