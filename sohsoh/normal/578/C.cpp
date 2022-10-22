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
const ld INF = 1e5;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ld dp[MAXN], B[MAXN], A[MAXN], n;

ld max_sum() {
	dp[0] = 0;
	ld ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(ld(0), dp[i - 1] + B[i]);
		ans = max(ans, dp[i]);
	}

	return ans;
}

ld min_sum() {
	dp[0] = 0;
	ld ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = min(ld(0), dp[i - 1] + B[i]);
		ans = min(ans, dp[i]);
	}

	return ans;
}

ld calc(ld x) {
	for (int i = 1; i <= n; i++) B[i] = A[i] - x;
	return max(abs(min_sum()), abs(max_sum()));	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	ld L = -INF, R = INF;
	int step = 200;
	while (step--) {
		ld mid1 = L + (R - L) / ld(3), mid2 = L + ld(2) * ((R - L) / ld(3));
		if (calc(mid1) < calc(mid2)) R = mid2;
		else L = mid1;
	}

	cout << setprecision(6) << fixed;
	cout << calc(L) << endl;
	return 0;
}