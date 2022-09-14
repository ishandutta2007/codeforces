
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, t, num = 0;
	scanf("%d", &n);
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		int l = -1, r = num, m;
		while (r - l > 1) {
			m = (l + r) / 2;
			if (a[m].back() > t)
				l = m;
			else
				r = m;			
		}
		if (a[r].empty())
			num++;
		a[r].push_back(t);
	}
	for (int i = 0; i < num; i++) {
		for (int j : a[i])
			printf("%d ", j);
		printf("\n");
	}
}