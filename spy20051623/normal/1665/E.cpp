#include <bits/stdc++.h>

using namespace std;

struct node {
	vector<int> v;
	node *s[2]{};

	~node() {
		if (s[0]) delete s[0];
		if (s[1]) delete s[1];
	}
};

int a[100005];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	node *root = new node;
	for (int i = 1; i <= n; ++i) {
		node *p = root;
		for (int j = 29; j >= 0; --j) {
			int b = a[i] >> j & 1;
			if (!p->s[b]) p->s[b] = new node;
			p = p->s[b];
			p->v.push_back(i);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		node *p = root;
		int ans = 0;
		vector<int> v;
		for (int i = 29; i >= 0; --i) {
			if (!p->s[0]) p->s[0] = new node;
			node *t = p->s[0];
			int sum = 0;
			for (int j: v) if ((a[j] >> i & 1) == 0) ++sum;
			int cnt = upper_bound(t->v.begin(), t->v.end(), r) - lower_bound(t->v.begin(), t->v.end(), l);
			sum += cnt;
			if (sum >= 2) {
				vector<int> vv;
				for (int j: v) if ((a[j] >> i & 1) == 0) vv.push_back(j);
				v = vv;
				p = t;
			} else {
				ans |= 1 << i;
				if (cnt == 1) v.push_back(*lower_bound(t->v.begin(), t->v.end(), l));
				if (!p->s[1]) p->s[1] = new node;
				p = p->s[1];
			}
		}
		cout << ans << '\n';
	}
	delete root;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}