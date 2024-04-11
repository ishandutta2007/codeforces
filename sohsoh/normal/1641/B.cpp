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

inline int solve() {
	deque<int> dq;
	map<int, int> mp;
	int cnt = 0, n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mp[x]++;
		dq.push_back(x);
	}

	for (pll e : mp)
		if (e.Y & 1) return cout << -1 << endl, 0;

	vector<pll> ans;
	vector<int> len_ans;
	while (!dq.empty()) {
		int x = dq.front();
		dq.pop_front();
		vector<int> vec;

		while (dq.front() != x) {
			vec.push_back(dq.front());
			dq.pop_front();
		}

		int m = vec.size();
		dq.pop_front();
		// cnt + m + 2
		int ind = 0;
		for (int e : vec) {
			ans.push_back({cnt + m + 2 + ind, e});
			ind++;
		}

		len_ans.push_back(2 * m + 2);
		cnt += 2 * m + 2;
		for (int e : vec)
			dq.push_front(e);
	}

	cout << ans.size() << endl;
	for (pll e : ans)
		cout << e.X << sep << e.Y << endl;
	cout << len_ans.size() << endl;
	for (int e : len_ans)
		cout << e << sep;
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