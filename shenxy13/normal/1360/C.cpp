#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		bool has_adj_pair = false;
		int p1 = 0, p2 = 0;
		for (int i = 0; i < n; ++i) {
			if (i != 0 && a[i] - a[i - 1] == 1) has_adj_pair = true;
			if (a[i] % 2) ++p1;
			else ++p2;
		}
		if (p1 % 2 == 0 && p2 % 2 == 0) printf("YES\n");
		else if (p1 % 2 == p2 % 2 && has_adj_pair) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}