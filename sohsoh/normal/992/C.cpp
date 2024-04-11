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

inline ll poww(ll a, ll b) {
	a %= MOD;

	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll x, k;
	cin >> x >> k;

	if (x == 0) return cout << 0 << endl, 0; 
	cout << (x % MOD * poww(2, k + 1) - poww(2, k) + 1 + MOD) % MOD << endl;
	return 0;
}