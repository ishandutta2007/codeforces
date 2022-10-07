#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 110;
int ar[MAXN];

int N, M, K;

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	sort(ar, ar + N);

	int need = M - K;
	int taken = 0;
	int cur = N - 1;
	while (cur >= 0 && need > 0) {
		need -= ar[cur] - 1;
		++taken;
		--cur;
	}

	if (need > 0) {
		printf("-1\n");
	} else {
		printf("%d\n", taken);
	}

	return 0;
}