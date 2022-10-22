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
const ll MOD = 1e9 + 7;

ll s, ans, A[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], A[i]--;

	for (int i = 1; i <= n; i++) {
		ans = (ans + s * min(A[i], A[i - 1]) + A[i]) % MOD;
		s = (s * min({A[i - 1], A[i], A[i + 1]}) + min(A[i], A[i + 1])) % MOD;
	}

	cout << ans << endl;
	return 0;
}