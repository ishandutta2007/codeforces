
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s, t;
	map<string, int> m;
	int n, a, b, k, f, x, y;
	cin >> n >> a >> b >> k >> f;
	vector<int> c(601*601);
	int last = -1, cc, ts = 0;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		if (m[s] == 0)
			m[s] = m.size();
		x = m[s] - 1;
		if (m[t] == 0)
			m[t] = m.size();
		y = m[t] - 1;
		cc = (x == last) ? b : a;
		last = y;
		if (x > y)
			swap(x, y);
		c[x * 601 + y] += cc;
		ts += cc;
	}
	sort(c.rbegin(), c.rend());
	int ans = ts, cs = 0;
	for (int i = 0; i < min((int) c.size(), k); i++) {
		cs += c[i];
		ans = min(ans, ts - cs + f * (i + 1));
	}
	cout << ans;
}