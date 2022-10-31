#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct dsu {
	vector<int> p, s;

	dsu(int n) : p(n), s(n, 1) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		while (x != p[x])
			x = p[x];
		return x;
	}

	void spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return;
		if (s[x] > s[y])
			swap(x, y);
		p[x] = y;
		s[y] += s[x];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		a--, b--;
		dsu d(n);
		vector<pair<int, int>> gr;
		while (m--) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			gr.emplace_back(x, y);
		}

		string w(n, 0);
		w[a] = w[b] = 1;

		for (auto [x, y] : gr)
			if (w[x] + w[y] == 0)
				d.spoji(x, y);

		string sa(n, 0), sb(n, 0);

		for (auto [x, y] : gr) {
			if (x == a || y == a)
				sa[d.e(x+y-a)] = 1;
			if (x == b || y == b)
				sb[d.e(x+y-b)] = 1;
		}

		ll p = 0, q = 0;

		for (int i=0; i<n; i++) {
			if (i == a || i == b)
				continue;
			if (i == d.e(i) && sa[i] && !sb[i])
				p += d.s[i];
			if (i == d.e(i) && sb[i] && !sa[i])
				q += d.s[i];
		}

		cout << p*q << '\n';
	}
}