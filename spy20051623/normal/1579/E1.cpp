#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	deque<int> q;
	int p;
	scanf("%d", &p);
	q.push_back(p);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &p);
		if (p > q.front()) q.push_back(p);
		else q.push_front(p);
	}
	for (int i: q) printf("%d ", i);
	printf("\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}