#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int t;

const int K = 1900;

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &t);
	int u, v, x = 0, le = -INF, ri = INF;
	while (t --) {
		scanf("%d %d", &u, &v);
		if (v == 1) le = max(le, K - x);
		else ri = min(ri, K - 1 - x);
		x += u;
	}
	if (le > ri) puts("Impossible");
	else if (ri > INF / 2) puts("Infinity");
	else printf("%d\n", ri + x);

	return 0;
}