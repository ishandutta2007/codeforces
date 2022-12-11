#include <bits/stdc++.h>

using namespace std;

int main() {	
	int n; scanf("%d", &n);
	vector<int> deg(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y; scanf("%d %d", &x, &y); --x; --y;
		++deg[x]; ++deg[y];
	}
	for (int i = 0; i < n; ++i) {
		if (deg[i] == 2) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}