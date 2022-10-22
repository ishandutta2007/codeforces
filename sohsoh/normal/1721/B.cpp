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
		int n, m, x, y, d;
		cin >> n >> m >> x >> y >> d;
		
		if ((x + d < n || x - d > 1) && (y + d < m || y - d > 1) && !(x + d >= n && y + d >= m) && 
				!(x - d <= 1 && y - d <= 1)) cout << n + m - 2 << endl;
		else cout << -1 << endl;
	}
	return 0;
}