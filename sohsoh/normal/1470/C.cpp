#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll CST = 2; // !!!!!

int n, k, sq;

inline int Query(int p) {
	cout << "? " << p << endl;
	int k;
	cin >> k;
	return k;
}

int main() {
	cin >> n >> k;
	sq = sqrt(n);
	for (int i = 0; i < sq + CST; i++) Query(1);
	int pos = 0;
	for (int i = 1; i <= n; i += sq - 1) {
		int c = Query(i);
		if (c < k) pos = i;
	}

	int L = 0, R = n - 1;
	while (L < R) {
		int mid = (L + R + 1) >> 1;
	       	int P = pos + mid;
		if (P > n) P -= n;
		if (Query(P) < k) L = mid;
		else R = mid - 1;	
	}

	int ans = pos + L + 1;
	while (ans > n) ans -= n;
	cout << "! " << ans << endl;
	return 0;
}