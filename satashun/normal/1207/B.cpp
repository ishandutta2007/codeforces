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

int A[60][60];
bool f[60][60];

int main() {
	int n, m; cin >> n >> m;
	rep(i, n) rep(j, m) cin >> A[i][j];

	vector<pii> pos;

	rep(i, n-1) {
		rep(j, m-1) {
			if (A[i][j] && A[i+1][j] && A[i][j+1] && A[i+1][j+1]) {
				f[i][j] = f[i+1][j] = f[i][j+1] = f[i+1][j+1] = 1;
				pos.eb(i, j);
			}
		}
	}

	rep(i, n) rep(j, m) if (A[i][j] && !f[i][j]) {
		puts("-1");
		return 0;
	}

	cout << pos.size() << endl;
	for (auto p : pos) {
		cout << p.fi + 1 << " " << p.se + 1 << endl;
	}
	return 0;
}