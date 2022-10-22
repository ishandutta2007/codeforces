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
		int n, a, b;
		cin >> n >> a >> b;
		int x = max(a, b);
		if (min(a, b) != 0 || x == 0 || (n - 1) % x) cout << -1 << endl;
		else {
			for (int i = 0; i < n - 1; i++)
				cout << i - i % x + 2 << sep;
			cout << endl;
		}
	}
	return 0;
}