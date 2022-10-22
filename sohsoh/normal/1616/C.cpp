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

ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		
		ll ans = n - 1;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ll tans = 0;
				for (int k = 1; k <= n; k++) {
					if (k == i || k == j) continue;
					// (A[j] - A[i]) / (j - i) == (A[k] - A[i]) / (k - i)
					if ((A[j] - A[i]) * (k - i) != (A[k] - A[i]) * (j - i)) {
						tans++;
					}
				}

			
				ans = min(ans, tans);
			}
		}

		cout << ans << endl;
	}	
	return 0;
}