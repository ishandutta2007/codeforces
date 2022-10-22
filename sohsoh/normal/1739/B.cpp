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

int n, D[MAXN], A[MAXN];

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> D[i];
	A[1] = D[1];

	for (int i = 2; i <= n; i++) {
		if (D[i] == 0) {
			A[i] = A[i - 1];
			continue;
		}

		if (A[i - 1] - D[i] >= 0) return cout << -1 << endl, 0;
		A[i] = A[i - 1] + D[i];
	}

	for (int i = 1; i <= n; i++)
		cout << A[i] << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}