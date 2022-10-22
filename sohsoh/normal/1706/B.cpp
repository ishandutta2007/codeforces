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

int ans[MAXN], n, lst[MAXN];

inline void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) lst[i] = ans[i] = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (!lst[x]) {
			lst[x] = i;
			ans[x] = 1;
		} else {
			if ((i - lst[x]) & 1) ans[x]++;
			lst[x] = i;
		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}