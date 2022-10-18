#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n), w(m);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}

	bool first = true;
	LL best = 1LL<<62;
	for (int h = 0; h < n; h++) {
		LL banban = -(1LL<<62);
		for (int i = 0; i < n; i++) {
			if (i == h) continue;
			for (int j = 0; j < m; j++) {
				LL p = LL(w[j])*LL(v[i]);
				banban = max(banban, p);
			}
		}
		best = min(best, banban);
	}
	cout << best << endl;
	exit(0);
}