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
		bool flag = false, ans = true;
		int n;
		cin >> n;

		int lst = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (x == lst) {
				lst = x;
				continue;
			}

			if (x < lst) flag = true;
			else if (flag) ans = false;
			lst = x;
		}

		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}