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

const ll MAXN = 1e6 + 10;
const ll T = 100;

int n, A[MAXN], B[MAXN];

inline ld solve(ld x) {
	ld mn = 0, mx = 1e9;
	for (int i = 1; i <= n; i++) {
		mn = max(mn, A[i] - (x - B[i]));
		mx = min(mx, A[i] + (x - B[i]));
	}

	return (mn <= mx) ? mn : -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		for (int i = 1; i <= n; i++) cin >> B[i];

		ld L = 0, R = 1e9;
		int x = T;

		while (x--) {
			ld mid = (L + R) / 2;
			if (solve(mid) >= 0) R = mid;
			else L = mid;
		}

		cout << setprecision(10) << fixed << solve(R) << endl;
	}
	return 0;
}