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

ll cnt[MAXN], s, t, n;

inline int solve() {
	t = 0, s = 0;
	for (int i = 0; i < n + 5; i++)
		cnt[i] = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	bool flag = false;
	priority_queue<int> pq;
	for (int i = 0; i <= n; i++) {
		if (t < i || flag) {
			cout << -1 << sep;
			flag = true;
			continue;
		}

		if (i) {
			while (cnt[i - 1]--) {
				pq.push(i - 1);
			}

			s += pq.top();
			pq.pop();
		}

		cout <<  1ll * i * (i - 1) / 2 - s + cnt[i] << sep;

		t += cnt[i];
	}

	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}