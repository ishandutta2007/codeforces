#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, sg[5][MAXN], m, k;

void build(int ind) {
	for (int i = n - 1; i > 0; --i) sg[ind][i] = max(sg[ind][i << 1], sg[ind][i << 1 | 1]);
}

int rmq(int ind, int l, int r) {
	int ans = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ans = max(ans, sg[ind][l++]);
		if (r & 1) ans = max(ans, sg[ind][--r]);
	}

	return ans;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", sg[j] + n + i);
		}
	}

	for (int j = 0; j < m; j++) build(j);
	
	ll ans = 0, X[5] = {0, 0, 0, 0, 0}, RX[5] = {0, 0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
		int L = 1, R = n - i;
		while (L < R) {
			int mid = (L + R + 1) >> 1;
			ll sum = 0;
			for (int j = 0; j < m; j++) X[j] = rmq(j, i, i + mid), sum += X[j];
			if (sum > k) R = mid - 1;
			else L = mid;
		}
	
		ll sum = 0;
		for (int j = 0; j < m; j++) X[j] = rmq(j, i, i + L), sum += X[j];
		
		if (sum <= k && L > ans) {
			ans = L;
			memcpy(RX, X, sizeof X);
		}
	}

	for (int i = 0; i < m; i++) cout << RX[i] << sep;
	cout << endl;
	return 0;
}