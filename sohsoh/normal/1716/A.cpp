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
		int n;
		cin >> n;
		if (n == 1) cout << 2 << endl;
		else if (n == 2 || n == 3) cout << 1 << endl;
		else {
			int k = n / 3;
			if (n % 3 == 0) cout << k << endl;
			else cout << k + 1 << endl;
		}
	}
	return 0;
}