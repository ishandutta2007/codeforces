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

const int maxn = 200010;

int cnt[maxn][26];

int main() {
	string s; cin >> s;
	int n = s.size();

	rep(i, n) {
		rep(c, 26) {
			cnt[i+1][c] = cnt[i][c];
		}
		++cnt[i+1][s[i]-'a'];
	}

	int q; cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		--l; --r;

		if (r == l) {
			puts("Yes");
			continue;
		}

		if (s[r] != s[l]) {
			puts("Yes");		
		} else {
			int num = 0;
			rep(c, 26) {
				if (cnt[r+1][c] - cnt[l][c] > 0) {
					++num;
				}
			}
			if (num >= 3) {
				puts("Yes");
			} else {
				puts("No");
			}
		}
	}
	return 0;
}