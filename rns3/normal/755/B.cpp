#include <bits/stdc++.h>
using namespace std;

#define N 2000

int n, m, u = 0, v = 0;
string a[N], b[N], x;

int main() {
	scanf("%d %d", &n, &m);
	while (n --) {
		cin >> x;
		int tag = 1;
		for (int i = 1; i <= u && tag; i ++) if (x == a[i]) tag = 0;
		if (tag) a[++u] = x;
	}
	sort (a + 1, a + u + 1);
	while (m --) {
		cin >> x;
		int tag = 1;
		for (int i = 1; i <= v && tag; i ++) if (x == b[i]) tag = 0;
		if (tag) b[++v] = x;
	}
	sort (b + 1, b + v + 1);
	int t = 0;
	for (int i = 1, j = 1; i <= u && j <= v;) {
		if (a[i] == b[j]) {
			t ++;
			i ++, j ++;
		}
		else if (a[i] > b[j]) j ++;
		else i ++;
	}
	if (u > v || u >= v && t % 2) puts("YES");
	else puts("NO");
	return 0;
}