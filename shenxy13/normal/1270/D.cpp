#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	int n, k, p, a;
	scanf("%d %d", &n, &k);
	map<int, int> smth;
	for (int i = 1; i <= k + 1; ++i) {
		printf("? ");
		for (int j = 1; j <= k + 1; ++j) {
			if (i != j) printf("%d ", j);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d %d", &p, &a);
		++smth[a];
	}
	printf("! %d", (--smth.end()) -> second);
	return 0;
}