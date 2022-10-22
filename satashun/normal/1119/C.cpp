#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

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

const int maxn = 510;

bool p[maxn][maxn], q[maxn][maxn];

int main() {
	int n, m; cin >> n >> m;

	rep(i, n) rep(j, m) {
		int x; cin >> x;
		p[i+1][j+1] = p[i+1][j] ^ p[i][j+1] ^ p[i][j] ^ x;
	}
	rep(i, n) rep(j, m) {
		int x; cin >> x;
		q[i+1][j+1] = q[i+1][j] ^ q[i][j+1] ^ q[i][j] ^ x;
	}

	bool ok = 1;
	for (int i = 0; i <= n; ++i) {
		if (p[i][m] != q[i][m]) {
			ok = 0;
		}
	}
	for (int i = 0; i <= m; ++i) {
		if (p[n][i] != q[n][i]) {
			ok = 0;
		}
	}	
	puts(ok ? "Yes" : "No");
	return 0;
}