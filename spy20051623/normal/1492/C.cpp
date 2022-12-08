#include <bits/stdc++.h>
using namespace std;
int l[200005], r[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m, i, j, maxm, mark = 0;
	string ss1, ss2;
	char ch, last;
	cin >> n >> m;
	cin >> ss1 >> ss2;
	i = j = 0;
	while (i < m) {
		while (ss2[i] != ss1[j])
			++j;
		l[i] = j;
		++j;
		++i;
	}
	i = m - 1;
	j = n - 1;
	while (i >= 0) {
		while (ss2[i] != ss1[j])
			--j;
		r[i] = j;
		--j;
		--i;
	}
	maxm = -1;
	for (i = 1; i < m; ++i) {
		maxm = max(maxm, r[i] - l[i - 1]);
	}
	cout << maxm << endl;
	return 0;
}