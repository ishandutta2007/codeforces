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
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) cout << 0 << endl;
		else {
			int s = x * x + y * y;
			int d = round(sqrt(s));
			cout << (d * d == s ? 1 : 2) << endl;
		}
	}
	return 0;
}