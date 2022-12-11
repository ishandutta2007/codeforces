#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> a, b;
int n;

void Check(int Delta) {
	for (int i = 0; i < b.size(); i++) b[i] = mp((a[i].fi + Delta) % n, (a[i].se + Delta) % n);
	for (int i = 0; i < b.size(); i++) if (b[i].fi > b[i].se) swap(b[i].fi, b[i].se);
	sort(b.begin(), b.end());
	if (a == b) {
		printf("Yes\n");
		exit(0);
	}
}

int main() {
	int m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		if (x > y) swap(x, y);
		a.push_back(mp(x, y)), b.push_back(mp(x, y));
	}
	sort(a.begin(), a.end());
	for (int i = 1; i * i <= n; i++) {
		if (n % i) continue;
		Check(i);
		if (i != 1 && i * i != n) Check(n / i);
	}
	printf("No\n");
	return 0;
}