#include <bits/stdc++.h>

using namespace std;

vector<int> v;

void solve() {
	int n;
	scanf("%d", &n);
	printf("%d\n", v[n - 1]);
}

int main() {
//	freopen("in.txt", "r", stdin);
	for (int i = 1; i <= 1666; ++i) {
		if (i % 10 != 3 && i % 3) v.push_back(i);
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}