#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m, a, b; scanf("%d %d %d %d", &n, &m, &a, &b);
		if (n * a != m * b) {
			printf("NO\n");
			continue;
		}
		int g = gcd(n, m);
		int simpN = n / g, simpM = m / g;
		vector<vector<bool>> smallGrid(g, vector<bool>(g));
		int cdem = b / simpN;
		for (int i = 0; i < g; ++i) {
			for (int k = 0; k < cdem; ++k) smallGrid[i][(i + k) % g] = true;	
		}
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (smallGrid[i / simpN][j / simpM]) printf("1");
				else printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}