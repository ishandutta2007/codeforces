#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

const int maxn = 200010;

ll a[maxn];

int n;

ll delta[maxn];
ll minodd[maxn];
ll mineven[maxn];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		delta[i] = a[i] - delta[i-1];
	}
	minodd[n] = maxn*3000000000LL;
	mineven[n] = maxn*3000000000LL;
	// cout << "this " << minodd[n] << " " << mineven[n] << endl;
	for (int i = n-1; i >= 0; i--) {
		mineven[i] = mineven[i+1];
		minodd[i] = minodd[i+1];
		if ((i+1)%2 == 0) mineven[i] = min(mineven[i], delta[i+1]);
		else minodd[i] = min(minodd[i], delta[i+1]);
	}

	if (mineven[0] >= 0 && minodd[0] >= 0 && delta[n] == 0) {
		cout << "YES" << endl;
		return;
	}

	for (int i = 1; i < n; i++) {

		if (delta[i-1] < 0) { //illegal at the start
			cout <<"NO" << endl;
			return;
		}
		//look at swapping i, i+1
		ll mdelta1 = a[i+1] - delta[i-1];
		ll mdelta2 = a[i] - mdelta1;

		if (mdelta1 < 0 || mdelta2 < 0) continue;

		ll oddchange = (a[i+1]-a[i])*2LL;

		if ((i+1)%2 == 1) oddchange = 0LL-oddchange;

		if (n%2 == 0) {
			if (delta[n] - oddchange != 0) continue;
		}
		else {
			if (delta[n] + oddchange != 0) continue;
		}

		if (mineven[i+1] - oddchange < 0) continue;
		if (minodd[i+1] + oddchange < 0) continue;

		// cout << " swapping " << i << " and " << i+1 << endl;

		cout << "YES" << endl;
		return;

	}

	cout << "NO" << endl;

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}