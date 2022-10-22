#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;

ll n, k;

ll get(ll x)
{
	ll u = x;
	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			while (x % i == 0) {
				x /= i;
			}
			u = u / i * (i-1);
		}
	}
	if (x > 1) {
		u = u / x * (x-1);
	}

	return u;
}

int main() {
	cin >> n >> k;
	ll t = (k + 1) / 2;

	rep(i, t) {
		n = get(n);
		if (n == 1) break;
	}
	
	cout << n % MOD << endl;

	return 0;
}