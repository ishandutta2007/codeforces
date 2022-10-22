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
		int p = -10, ans = 0;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == '0') {
				ans += max(0, p - i + 3);
				p = i;
			}
		}

		cout << ans << endl;
	}
	return 0;
}