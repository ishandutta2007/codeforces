#include <bits/stdc++.h>
using namespace std;
map<int, int> r;
map<int, int> tmp;
long long t[205], x[205], y[205];
int h[100005];

int main() {
//	freopen("in.txt", "r", stdin);
	long long n, m, i, j, k, l;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		cin >> t[i] >> x[i] >> y[i];
	}
	r[0];
	for (i = 1; i <= n; ++i) {
		tmp.clear();
		for (auto it : r) {
			if (t[i] == 1) {
				j = 100000LL * it.first;
				for (k = 1; k <= y[i]; ++k) {
					j += x[i];
					l = (j - 1) / 100000 + 1;
					j = 100000LL * l;
					if (l > m)
						break;
					if (!h[l])
						tmp[l] = i;
					else
						break;
				}
			} else {
				j = it.first;
				if (j == 0)
					continue;
				for (k = 1; k <= y[i]; ++k) {
					j *= x[i];
					l = (j - 1) / 100000 + 1;
					j = l;
					if (l > m)
						break;
					if (!h[l])
						tmp[l] = i;
					else
						break;
				}
			}
		}
		for (auto it : tmp) {
			r[it.first] = it.second;
			h[it.first] = 1;
		}
	}
	for (i = 1; i <= m; ++i) {
		if (r[i] == 0)
			cout << -1 << ' ';
		else
			cout << r[i] << ' ';
	}
	return 0;
}