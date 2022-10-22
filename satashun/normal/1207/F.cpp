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

const int B = 710;
const int maxn = 500010;

ll a[maxn];
ll sum[B][B];

int main() {
	int q; scanf("%d", &q);
	rep(i, q) {
		int tp, x, y;
		scanf("%d %d %d", &tp, &x, &y);
		if (tp == 1) {
			a[x] += y;
			for (int j = 1; j < B; ++j) {
				int m = x % j;
				sum[j][m] += y;
			}
		} else {
			ll ans = 0;
			if (x >= B) {
				for (int j = (y == 0 ? x : y); j <= 500000; j += x) {
					ans += a[j];
				}
			} else {
				ans = sum[x][y];
			}
			printf("%lld\n", ans);
		}
	}

	return 0;
}