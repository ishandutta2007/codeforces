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
		if (k > (n + 1) / 2) cout << -1 << endl;
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j && i % 2 == 0 && k) {
						k--;
						cout << 'R';
					} else cout << '.';
				}

				cout << endl;
			}
		}
	}
	return 0;
}