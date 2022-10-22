#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 20;
const ld EPS = 1e-9;

int n, k;
ld dp[1 << MAXN], A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int t = 0;
	for (int i = 0; i < n; i++) cin >> A[i], t += (A[i] > EPS);
	k = min(k, t);

	dp[0] = 1;
	for (int mask = 1; mask < (1 << n); mask++) {
		ld s = 0;
		for (int i = 0; i < n; i++)
			if (mask & (1 << i) && A[i] > EPS)
				s += A[i];

		s = 1 - s;
		for (int i = 0; i < n; i++)
			if (mask & (1 << i) && A[i] > EPS)
				dp[mask] += dp[mask ^ (1 << i)] * (A[i] / (s + A[i]));
	}

	cout << setprecision(10) << fixed;

	for (int i = 0; i < n; i++) {
		ld ans = 0;
		for (int mask = 0; mask < (1 << n); mask++)
			if (__builtin_popcount(mask) == k && (mask & (1 << i)))
				ans += dp[mask];
		cout << ans << sep;
	}

	cout << endl;
	return 0;
}