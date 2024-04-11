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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a2, a3, a5, a6;
	cin >> a2 >> a3 >> a5 >> a6;

	ll ans = 0;
	while (true) {
		if (a2 && a5 && a6) {
			a2--;
			a5--;
			a6--;
			ans += 256;
		} else if (a2 && a3) {
			a2--;
			a3--;
			ans += 32;
		} else break;
	}	

	cout << ans << endl;
	return 0;
}