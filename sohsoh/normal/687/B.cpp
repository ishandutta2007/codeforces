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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll F = 1, n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		ll g = __gcd(x, k);
		F = F * g / __gcd(g, F);
		if (F % k == 0) return cout << "Yes" << endl, 0;
	}

	cout << "No" << endl;
	return 0;
}