#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e5 + 10;
const ll LOG = 30;

int nxt[MAXN * LOG][2], sz = 0, ind[MAXN * LOG];
map<int, vector<pll>> mp;
int n, k;
vector<int> ans;

inline void addTrie(int x, int i) {
	int v = 1;
	for (int i = LOG; i >= 0; i--) {
		int ind = ((x >> i) & 1);
		if (nxt[v][ind]) v = nxt[v][ind];
		else v = nxt[v][ind] = (++sz) + 1;
	}

	ind[v] = i;
}

inline pair<int, int> maxXor(int x) {
	int v = 1, ans = 0;
	for (int i = LOG; i >= 0; i--) {
		int ind = ((x >> i) & 1);
		if (nxt[v][ind ^ 1]) v = nxt[v][ind ^ 1], ans ^= (1 << i);
		else v = nxt[v][ind];
	}

	return {ans, ind[v]};
}

inline void clear() {
	for (int i = 0; i < sz + 10; i++)
		nxt[i][0] = nxt[i][1] = ind[i] = 0;
	sz = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if (k == 0) {
		cout << n << endl;
		for (int i = 1; i <= n; i++) cout << i << sep;
		cout << endl;
		return 0;
	}

	int f = (k == 0 ? 0 : 32 - __builtin_clz(k));

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mp[x >> f].push_back({x, i});
	}

	for (auto e : mp) {
		addTrie(e.Y.front().X, e.Y.front().Y);
		int mx = -1;
		pll mx_pair;

		for (int i = 1; i < (int) e.Y.size(); i++) {
			pll t = maxXor(e.Y[i].X);
			if (t.X > mx) mx = t.X, mx_pair = {t.Y, e.Y[i].Y};
			addTrie(e.Y[i].X, e.Y[i].Y);
		}

		if (mx >= k) ans.push_back(mx_pair.X), ans.push_back(mx_pair.Y);
		else ans.push_back(e.Y.front().Y);
		clear();
	}

	if (ans.size() < 2) return cout << -1 << endl, 0;
	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}