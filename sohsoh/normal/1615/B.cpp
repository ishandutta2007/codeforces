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

const ll MAXN = 3e5 + 10;
const ll LOG = 25;

int ps[MAXN][LOG];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++) {
		for (int j = 0; j < LOG; j++) {
			ps[i][j] = ps[i - 1][j];
			if (i & (1 << j)) {
				ps[i][j]++;
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int ans = 0, l, r;
		cin >> l >> r;
		for (int j = 0; j < LOG; j++) {
			if (ps[r][j] - ps[l - 1][j] > ans)
				ans = ps[r][j] - ps[l - 1][j];
		}

		cout << r - l + 1 - ans << endl;
	}
	return 0;
}