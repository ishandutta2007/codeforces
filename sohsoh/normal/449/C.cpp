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

int F[MAXN], n;
vector<pll> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	set<int> rem;
	for (int i = 2; i <= n; i++) rem.insert(i);

	if (n == 1 || n == 2 || n == 3) return cout << 0 << endl, 0;

	for (int i = 3; i <= n; i++) {
		if (__builtin_popcount(i) == 1 || F[i]) continue;
		if (i * 2 > n) {
			rem.erase(i);
			continue;
		}

		queue<int> q;
		for (int j = i; j <= n; j += i) {
			if (F[j]) continue;
			F[j] = i;
			q.push(j);
		}

		if (q.size() & 1) {
			int v = q.front();
			q.pop();
			q.pop();
			q.push(v);
		}

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			int u = q.front();
			q.pop();

			rem.erase(u);
			rem.erase(v);

			ans.push_back({u, v});
		}
	}

	int lst = 0;
	for (int e : rem) {
		if (lst) {
			ans.push_back({e, lst});
			lst = 0;
		} else lst = e;
	}

	cout << ans.size() << endl;
	for (pll e : ans)
		cout << e.X << sep << e.Y << endl;
	return 0;
}