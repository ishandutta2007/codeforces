#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

void solve() {
	int n;
	scanf("%d", &n);
	priority_queue<pii> q;
	for (int i = 1; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		if (p) q.emplace(p, i);
	}
	vector<pii> v;
	while (q.size() > 1) {
		pii a = q.top();
		q.pop();
		pii b = q.top();
		q.pop();
		v.emplace_back(a.second, b.second);
		--a.first, --b.first;
		if (a.first) q.push(a);
		if (b.first) q.push(b);
	}
	printf("%d\n", v.size());
	for (auto &i: v) printf("%d %d\n", i.first, i.second);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}