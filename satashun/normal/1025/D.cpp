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

const int maxn = 710;

bool con[maxn][maxn];
bool dpL[maxn][maxn], dpR[maxn][maxn];

int main() {
	int n; cin >> n;
	V<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) rep(j, n) if (__gcd(a[i], a[j]) != 1) {
		con[i][j] = 1;
	}

	rep(r, n) {
		for (int l = r; l >= 0; --l) {
			if (l == r) {
				dpL[l][r] = dpR[l][r] = 1;
			} else {
				for (int m = l; m < r; ++m) {
					if (con[m][r] && dpR[l][m] && dpL[m][r-1]) {
						dpR[l][r] = 1;
					}
				}
				for (int m = l + 1; m <= r; ++m) {
					if (con[m][l] && dpR[l+1][m] && dpL[m][r]) {
						dpL[l][r] = 1;
					}
				}
			}
		}
	}

	bool ok = 0;
	rep(i, n) if (dpR[0][i] && dpL[i][n-1]) {
		ok = 1;
	}
	puts(ok ? "Yes" : "No");
	return 0;
}