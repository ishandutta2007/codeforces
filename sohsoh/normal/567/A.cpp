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

int A[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	for (int i = 1; i <= n; i++) {
		int ans = int(2e9) + 5;
		if (i > 1) ans = min(ans, A[i] - A[i - 1]);
		if (i < n) ans = min(ans, A[i + 1] - A[i]);
		cout << ans << sep << max(A[n] - A[i], A[i] - A[1]) << endl;
	}
	return 0;
}