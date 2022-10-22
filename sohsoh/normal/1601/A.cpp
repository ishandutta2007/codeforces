//: // ////: ///  / : //// / :
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int 			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 50;

int n, cnt[LOG];

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < LOG; j++)
			if (x & (1ll << j))
				cnt[j]++;
	}

	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 0; j < LOG; j++)
			if (cnt[j] % i)
				flag = false;
		if (flag) cout << i << sep;
	}

	cout << endl;
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		solve();
	}
	return 0;
}