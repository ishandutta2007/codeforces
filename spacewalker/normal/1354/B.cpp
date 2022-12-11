#include <bits/stdc++.h>

using namespace std;

constexpr int NMAX = 200010;
constexpr int INF = 1000000000;


char strng[NMAX];

int nextOcc[3][NMAX];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", strng);
		int n = strlen(strng);
		for (int k = 0; k < 3; ++k) {
			for (int i = n - 1; i >= 0; --i) {
				if (strng[i] == (char)(k + '1')) nextOcc[k][i] = i;
				else nextOcc[k][i] = (i == n - 1 ? INF : nextOcc[k][i+1]);
			}
		}
		int ans = INF;
		for (int i = 0; i < n; ++i) {
			int needLast = -1;
			for (int k = 0; k < 3; ++k) needLast = max(needLast, nextOcc[k][i]);
			ans = min(ans, needLast - i + 1);
		}
		if (ans > n) printf("0\n");
		else printf("%d\n", ans);
	}
	return 0;
}