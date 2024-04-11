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

const ll MAXN = 5e5 + 10;
const ll INF = 8e18;
const ll SIG = 26;

string s, t;
int n, fen[MAXN];
queue<int> q[SIG];

inline void update(int ind, int val) {
	for (++ind; ind < 2 * n + 10; ind += ind & -ind) //
		fen[ind] += val;
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	return ans;
}

inline void solve() {
	for (int i = 0; i < 2 * n + 100; i++) {
		fen[i] = 0;
	}

	for (int i = 0; i < SIG; i++) {
		while (!q[i].empty())
			q[i].pop();
	}

	ll ans = INF, tans = 0;
	cin >> n >> s >> t;

	s = "." + s + ".";
	t = "." + t + ".";
	for (int i = 1; i <= n; i++)
		q[int(s[i] - 'a')].push(i);

	int pos = 1, c = int(s[1] - 'a');
	for (int i = 1; i <= n; i++) {
		int f = query(pos), x = int(t[i] - 'a');
		for (int k = 0; k < x; k++) {
			if (!q[k].empty()) {
				int j = q[k].front();
				ans = min(ans, tans + j - pos - (query(j) - f));
			}
		}

		if (q[x].empty()) break;
		int j = q[x].front();
		q[x].pop();

		if (x == c) {
			pos = n + 100;
			for (int k = 0; k < SIG; k++) {
				if (!q[k].empty() && q[k].front() < pos) {
					pos = q[k].front();
					c = k;
				}
			}
		
			continue;
		}

		tans += j - pos - (query(j) - f);
		update(j, 1);
	}

	cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}