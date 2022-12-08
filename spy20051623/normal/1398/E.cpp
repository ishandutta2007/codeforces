#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	set<int> a, b, c, d, e;
	long long s = 0, t = 0;
	while (n--) {
		int k, x;
		cin >> k >> x;
		if (x > 0) {
			if (!k) {
				a.insert(x);
				s += x;
				if (!e.empty() && x > *e.begin()) {
					if (a.find(*e.begin()) != a.end()) c.insert(*e.begin());
					else d.insert(*e.begin());
					t -= *e.begin();
					e.erase(e.begin());
					t += x;
					e.insert(x);
				} else {
					c.insert(x);
				}
			} else {
				b.insert(x);
				s += x;
				d.insert(x);
				if (!c.empty() && *--c.end() > *--d.end()) {
					t += *--c.end();
					e.insert(*--c.end());
					c.erase(--c.end());
				} else {
					t += *--d.end();
					e.insert(*--d.end());
					d.erase(--d.end());
				}
			}
		} else {
			x = -x;
			if (!k) {
				a.erase(x);
				s -= x;
				if (e.find(x) != e.end()) {
					t -= x;
					e.erase(x);
					if (!c.empty() && *--c.end() > *--d.end()) {
						t += *--c.end();
						e.insert(*--c.end());
						c.erase(--c.end());
					} else {
						t += *--d.end();
						e.insert(*--d.end());
						d.erase(--d.end());
					}
				} else {
					c.erase(x);
				}
			} else {
				b.erase(x);
				s -= x;
				if (e.find(x) != e.end()) {
					t -= x;
					e.erase(x);
				} else {
					if (a.find(*e.begin()) != a.end()) c.insert(*e.begin());
					else d.insert(*e.begin());
					t -= *e.begin();
					e.erase(e.begin());
					d.erase(x);
				}
			}
		}
		cout << s + t - (!e.empty() && d.empty() ? *e.begin() - (!c.empty() ? *--c.end() : 0) : 0) << '\n';
	}
	return 0;
}