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

int n, m;

inline int solve() {
	vector<int> vec;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	if (m == 1) return cout << 2 << endl, 0;
	sort(all(vec));
	priority_queue<int> pq;
	for (int i = 0; i < m - 1; i++)
		pq.push(vec[i + 1] - vec[i] - 1);
	
	pq.push(n - vec[m - 1] + vec[0] - 1);

	int t = 0, ans = 0;
	while (!pq.empty()) {
		int x = pq.top();
		pq.pop();

		x -= t * 2;
		if (x > 0) ans += max(1, x - 1);
		t += 2;
	}

	cout << n - ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}