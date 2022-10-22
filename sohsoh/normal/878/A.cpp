#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll O[MAXN], Z[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	fill(O, O + MAXN, 1);
	fill(Z, Z + MAXN, 0);
	while (n--) {
		char c;
		ll x;
		cin >> c >> x;
		for (int i = 9; i >= 0; i--) {
			ll bt = (x & (1ll << i));
			if (bt) bt = 1;
			if (c == '&') O[i] &= bt, Z[i] &= bt;
			if (c == '|') O[i] |= bt, Z[i] |= bt;
			if (c == '^') O[i] ^= bt, Z[i] ^= bt;
		}
	}

	cout << 3 << endl;

	bitset<10> bt;
	for (int i = 0; i < 10; i++) {
		if (Z[i] == 1 && O[i] == 0) bt[i] = 1;
		else bt[i] = 0;
	}

	cout << "^ " << bt.to_ullong() << endl;
	
	for (int i = 0; i < 10; i++) {
		if (Z[i] == 1 && O[i] == 1) bt[i] = 1;
		else bt[i] = 0;
	}

	cout << "| " << bt.to_ullong() << endl;	
	for (int i = 0; i < 10; i++) {
		if (Z[i] == 0 && O[i] == 0) bt[i] = 0;
		else bt[i] = 1;
	}

	
	cout << "& " << bt.to_ullong() << endl;	
	return 0;
}