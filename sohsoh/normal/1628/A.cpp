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

const ll MAXN = 2e5 + 10;

queue<int> dq[MAXN];
int pref_mn[MAXN], p, n;

inline void solve() {
	for (int i = 0; i < n + 5; i++) {
		while (!dq[i].empty())
			dq[i].pop();
	}

	cin >> n;	
	for (int i = 0; i < n + 5; i++)
		pref_mn[i] = -1;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		dq[x].push(i);
		pref_mn[x] = i;
	}

	p = n;
	for (int i = 1; i <= n; i++)
		pref_mn[i] = min(pref_mn[i], pref_mn[i - 1]);

	int ind = 1;
	vector<int> ans;
	while (ind <= n) {
		while (p > 0 && pref_mn[p - 1] < ind) p--;
		ans.push_back(p);
		for (int i = 0; i < p; i++) {
			ind = max(ind, dq[i].front());
			dq[i].pop();
		}

		ind++;
		for (int i = 0; i < p; i++)
			while (!dq[i].empty() && dq[i].front() < ind)
				dq[i].pop();
	}

	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}