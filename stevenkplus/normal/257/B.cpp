#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;

int main() {
	scanf("%d %d", &N, &M);
	int ans = max(N, M) - 1;
	int ans2 = min(N, M);
	printf("%d %d\n", ans, ans2);

	return 0;
}