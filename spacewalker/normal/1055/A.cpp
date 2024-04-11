#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int canStop[2000][2];

int main() {
	int n, s; scanf("%d %d", &n, &s);
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < n; ++i) scanf("%d", &canStop[i][k]);
	}
	if (s == 1) {
		printf("YES\n");
		return 0;
	}
	int lastPossible = -1;
	for (int i = 0; i < n; ++i) {
		if (canStop[i][0] && canStop[i][1]) lastPossible = i;
	}
	bool isPossible = (canStop[0][0]) && (canStop[s-1][0] || (canStop[s-1][1] && lastPossible >= s-1));
	printf((isPossible ? "YES\n" : "NO\n"));
	return 0;
}