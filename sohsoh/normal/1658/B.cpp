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
const ll MOD = 998244353;

ll fact[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = fact[i - 1] * i % MOD;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (n & 1 ? 0 : fact[n >> 1] * fact[n >> 1] % MOD) << endl;
	}
	return 0;
}