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

const int maxn = 100010;

bool f[2][maxn];

int main() {
	int n, q;
	cin >> n >> q;

	multiset<int> cr, ta;

	while (q--) {
		int r, c;
		cin >> r >> c;
		--r; --c;

		if (!f[r][c]) {
			if (f[r^1][c]) {
				ta.insert(c);
			}
			if (c > 0 && f[r^1][c-1]) {
				cr.insert(c-1);
			}
			if (c+1<n && f[r^1][c+1]) {
				cr.insert(c);
			}
		} else {
			if (f[r^1][c]) {
				ta.erase(c);
			}
			if (c > 0 && f[r^1][c-1]) {
				cr.erase(cr.find(c-1));
			}
			if (c+1<n && f[r^1][c+1]) {
				cr.erase(cr.find(c));
			}			
		}

		f[r][c] ^= 1;

		bool ok = (cr.size() == 0 && ta.size() == 0);
		puts(ok ? "Yes" : "No");
	}

	return 0;
}