#include <bits/stdc++.h>
using namespace std;

int n;
pair <int, int> p[100100];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d", &p[i].first), p[i].second = i;
	sort(p, p + n);
	if (n > 1 && p[0].first == p[1].first) puts("Still Rozdil");
	else printf("%d\n", p[0].second + 1);
	return 0;
}