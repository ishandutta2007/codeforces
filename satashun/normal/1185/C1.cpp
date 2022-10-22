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

int num[110];

int main() {
	int n, m; cin >> n >> m;

	ll s = 0;

	rep(i, n) {
		int t; cin >> t;

		int cnt = 0;
		int zan = m - t;
		for (int i = 1; i <= 100; ++i) {
			int dec = min(zan / i, num[i]);
			cnt += dec;
			zan -= i * dec;
		}

		++num[t];
		printf("%d%c", i - cnt, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}