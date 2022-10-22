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

const ll MAXN = 1e5 + 10;
const ll SQ = 320;

int n;
unordered_set<int> st[MAXN];
vector<pll> F;
vector<int> vec[MAXN];
ll ans = 0;

inline bool f(int x, int y) {
	if (x < 0 || x >= MAXN) return false;
	return st[x].find(y) != st[x].end();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		st[x].insert(y);
		vec[x].push_back(y);
	}

	for (int i = 0; i < MAXN; i++) sort(all(vec[i]));

	for (int x = 0; x < MAXN; x++) {
		if (vec[x].size() > SQ) continue;

		for (int i = 0; i < vec[x].size(); i++) {
			for (int j = i + 1; j < vec[x].size(); j++) {
				int a = vec[x][i], b = vec[x][j];
				int len = b - a;
				ans += (f(x + len, a) && f(x + len, b));

				if (x >= len && vec[x - len].size() > SQ)
					ans += (f(x - len, a) && f(x - len, b));
			}
		}
	}

	for (int x = 0; x < MAXN; x++) {
		st[x].clear();
		if (vec[x].size() > SQ)
			for (int y : vec[x])
				F.push_back({y, x});
		vec[x].clear();
	}

	for (pll e : F) {
		int x = e.X, y = e.Y;	
		st[x].insert(y);
		vec[x].push_back(y);
	}

	for (int x = 0; x < MAXN; x++) {
		if (vec[x].size() > SQ) continue;

		for (int i = 0; i < vec[x].size(); i++) {
			for (int j = i + 1; j < vec[x].size(); j++) {
				int a = vec[x][i], b = vec[x][j];
				int len = b - a;
				ans += (f(x + len, a) && f(x + len, b));
			}
		}
	}

	cout << ans << endl;
	return 0;
}