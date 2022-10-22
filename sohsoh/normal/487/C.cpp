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

inline ll poww(ll a, ll b, ll MOD) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline bool prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	if (n == 4) return cout << "YES" << endl << 1 << endl << 3 << endl << 2 << endl << 4 << endl, 0;
	if (n == 1) return cout << "YES" << endl << 1 << endl, 0;
	if (!prime(n)) return cout << "NO" << endl, 0;

	cout << "YES" << endl << 1 << endl;
	for (ll i = 2; i < n; i++) 	
		cout << i * poww(i - 1, n - 2, n) % n << endl;
	cout << n << endl;
	return 0;
}