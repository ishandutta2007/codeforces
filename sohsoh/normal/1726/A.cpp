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

int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		
		if (n == 1) cout << 0 << endl;
		else {
			int ans = A[n] - A[1];
			ans = max(ans, *max_element(A + 1, A + n + 1) - A[1]);
			ans = max(ans, A[n] - *min_element(A + 1, A + n + 1));
			for (int i = 1; i < n; i++)
				ans = max(ans, A[i] - A[i + 1]);
			cout << ans << endl;
		}
	}
	return 0;
}