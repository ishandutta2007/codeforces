#include <bits/stdc++.h>
using namespace std;
int a[100005];
int ne[100005];
int fa[100005];

int gcd(int x, int y) {
	int t;
	while (t = x % y) {
		x = y;
		y = t;
	}
	return y;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j, k, m;
	vector<int> del;
	cin >> t;
	while (t--) {
		cin >> n;
		del.clear();
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			ne[i] = i % n + 1;
			fa[i] = 0;
		}
		i = 1;
		m = 1;
		while (fa[i] != i) {
			if (fa[i]) {
				fa[m] = fa[i];
				i = fa[i];
			} else if (gcd(a[i], a[ne[i]]) == 1) {
				del.push_back(ne[i]);
				j = ne[i];
				ne[i] = ne[ne[i]];
				if (fa[j])
					fa[ne[i]] = fa[j];
				if (fa[ne[i]] == ne[i])
					fa[ne[i]] = 0;
				a[j] = ne[j] = fa[j] = 0;
				m = i = ne[i];
			} else {
				fa[m] = ne[i];
				i = ne[i];
			}
		}
		cout << del.size() << ' ';
		for (i = 0; i < del.size(); ++i) {
			cout << del[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}