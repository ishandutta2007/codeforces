#include <bits/stdc++.h>

using namespace std;

struct dt {
	long long num{};
	int len{};
	int l{}, r{};
};

map<string, dt> m;

void solve() {
	m.clear();
	int n;
	scanf("%d", &n);
	long long ans;
	while (n--) {
		string u, s, t, p;
		cin >> u >> p;
		if (p == ":=") {
			cin >> s;
			dt d;
			int len = s.length();
			d.len = len;
			if (len >= 1) {
				if (s.substr(0, 1) == "a")
					d.l = 1;
				if (s.substr(len - 1, 1) == "h")
					d.r = 1;
			}
			if (len >= 2) {
				if (s.substr(0, 2) == "ha")
					d.l = 2;
				if (s.substr(len - 2, 2) == "ha")
					d.r = 2;
			}
			if (len >= 3) {
				if (s.substr(0, 3) == "aha")
					d.l = 3;
				if (s.substr(len - 3, 3) == "hah")
					d.r = 3;
			}
			if (len >= 4) {
				if (s.substr(0, 4) == "haha")
					d.num = 1;
				if (s.substr(len - 4, 4) == "haha")
					d.num = 1;
			}
			m[u] = d;
			ans = d.num;
		} else {
			cin >> s >> p >> t;
			dt d;
			d.num = m[s].num + m[t].num;
			d.l = m[s].l;
			d.r = m[t].r;
			d.len = m[s].len + m[t].len;
			if (d.len > 100)
				d.len = 100;
			if (m[s].r + m[t].l == 4) {
				++d.num;
			}
			if (m[s].r + m[t].l == 6) {
				d.num += 2;
			}
			if (m[s].r == m[s].len) {
				if (d.l < 2 && d.l <= m[s].r + m[t].l - 2)
					d.l += 2;
			}
			if (m[t].l == m[t].len) {
				if (d.r < 2 && d.l <= m[s].r + m[t].l - 2)
					d.r += 2;
			}
			m[u] = d;
			ans = d.num;
		}
	}
	printf("%lld\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}