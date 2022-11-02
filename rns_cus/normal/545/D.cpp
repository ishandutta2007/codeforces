#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, x, ans;
multiset <int> s;
multiset <int> :: iterator it;

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &x), s.insert(x);
	int t = 0;
	while (!s.empty()) {
		it = s.lower_bound(t);
		if (it == s.end()) break;
		ans ++;
		t += *it;
		s.erase(it);
	}
	printf("%d\n", ans);
	return 0;
}