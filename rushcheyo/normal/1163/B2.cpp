#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, u[N], ans;
map<int, int> b, c;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", u + i);
		if (b[u[i]] && !--c[b[u[i]]])
			c.erase(b[u[i]]);
		++c[++b[u[i]]];
		if (c.size() == 1) {
			auto a = *c.begin();
			if (a.first == 1 || a.second == 1)
				ans = i;
		}
		if (c.size() == 2) {
			auto a = *c.begin(), b = *c.rbegin();
			if ((a.first == 1 && a.second == 1) || (b.first == a.first + 1 && b.second == 1))
				ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}