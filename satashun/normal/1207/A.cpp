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

int main() {
	int t; cin >> t;
	while (t--) {
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		int ans = 0;
		for (int i = 0; i <= p; ++i) {
			for (int j = 0; j <= f; ++j) {
				if (i * 2 + j * 2 > b) continue;
				int val = h * i + c * j;
				ans = max(ans, val);
			}
		}
		cout << ans << endl;
	}
	return 0;
}