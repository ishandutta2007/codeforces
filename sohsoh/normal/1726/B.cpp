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
		int n, m;
		cin >> n >> m;
		if (m < n || (m % 2 == 1 && n % 2 == 0)) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			if (n & 1) {
				for (int i = 1; i < n; i++)
					cout << 1 << sep;
				cout << m - n + 1 << endl;
			} else {
				for (int i = 1; i < n - 1; i++)
					cout << 1 << sep;
				cout << (m - n + 2) / 2  << sep << (m - n + 2) / 2 << endl;

			}
		}
	}
	return 0;
}