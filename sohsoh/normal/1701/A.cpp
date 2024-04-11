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
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int x;
			cin >> x;
			cnt += x;
		}

		if (cnt == 0) cout << 0 << endl;
		else if (cnt < 4) cout << 1 << endl;
		else cout << 2 << endl;
	}
	return 0;
}