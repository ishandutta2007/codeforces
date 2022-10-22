// Sohsoh84 :)))
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

ll s, n, k, f;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	while (k--) {
		ll a, b;
		cin >> a >> b;
		s += b;
		f = (f + a * b) % n;
	}

	if (s < n) cout << 1 << endl;
	else if (s > n) cout << -1 << endl;
	else cout << ((f == (n * (n - 1) / 2) % n) ? 1 : -1) << endl; 
	return 0;
}