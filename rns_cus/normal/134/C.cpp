#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
#define N 2000200

int n, sum, x, st[N], en[N];

set <pii> s;
set <pii> :: iterator it;
pii p, q[N];

int main() {
	scanf("%d %d", &n, &sum);
	if (sum & 1) {puts("No"); return 0;}
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		if (x >= n) {puts("No"); return 0;}
		p.first = -x, p.second = i;
		if (p.first) s.insert(p);
	}
	int runs = 0, deg;
	while (!s.empty()) {
		it = s.begin();
		p = *it;
		deg = -p.first;
		for (int i = 1; i <= deg; i ++) {
			it ++;
			if (it == s.end()) {puts("No"); return 0;}
			q[i] = *it;
			st[runs] = p.second, en[runs++] = q[i].second;
		}
		for (int i = 0; i <= deg; i ++) it = s.begin(), s.erase(it);
		for (int i = 1; i <= deg; i ++) {
			q[i].first ++;
			if (q[i].first) s.insert(q[i]);
		}
	}
	puts("Yes"); cout << runs << endl;
	for (int i = 0; i < runs; i ++) printf("%d %d\n", st[i], en[i]);
	return 0;
}