// orz
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e3 + 10;

ll ans = 0, mn[MAXN][MAXN], bal[MAXN][MAXN], A[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	       	bal[i][i] = A[i];
		if (i % 2 == 0) bal[i][i] = -A[i], mn[i][i] = -A[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			bal[i][j] = bal[i][j - 1] + (j % 2 == 1 ? A[j] : -A[j]);
			mn[i][j] = min(mn[i][j - 1], bal[i][j]);
		}
	}

	for (int i = 1; i <= n; i += 2) {
		for (int j = i + 1; j <= n; j += 2) {
			if (j == i + 1) {
				ans += min(A[i], A[i + 1]);
				continue;
			}

			ll l = -mn[i + 1][j - 1], r = l + bal[i + 1][j - 1];
			ans += max(0ll, min(A[i] - l + 1, A[j] - r + 1));
		}
	}

	cout << ans << endl;
	return 0;
}