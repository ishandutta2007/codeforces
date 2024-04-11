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
const ll LOG = 35;

ll n, k, A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		ll tans = -k * n;	
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			tans += A[i];
		}

		ll ans = max(tans, 0ll);
		for (int i = n; i > 0; i--) {
			tans += k;
			for (int j = i; j <= min(n, i + LOG); j++) {
				tans -= A[j];
				A[j] /= 2;
				tans += A[j];
			}

			ans = max(ans, tans);
		}

		cout << ans << endl;
	}
	return 0;
}