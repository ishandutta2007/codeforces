#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;

int n, k, A[MAXN], B[MAXN];

inline int check(int x) {
	int ans = 0, tans = 2;

	for (int i = 1; i <= n; i++) {
		A[i] = B[i];
		if (A[i] * 2 < x) {
			ans++;
			A[i] = INF;
		}

		if (A[i] >= x) tans = min(tans, 1);
		if (i > 1 && A[i] >= x && A[i - 1] >= x) tans = min(tans, 0);
	}

	return ans + tans;
}

inline int solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> B[i];

	int l = 0, r = INF;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid) <= k) l = mid;
		else r = mid - 1;
	}

	cout << l << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}