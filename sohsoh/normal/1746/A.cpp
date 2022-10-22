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
		int n, k;
		cin >> n >> k;
		int s = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			s += x;
		}

		if (n < k) cout << (s == n ? "YES" : "NO") << endl;
		else cout << (s ? "YES" : "NO") << endl;
	}
	return 0;
}