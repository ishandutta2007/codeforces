#include <cstdio>

using namespace std;

int N, M, H;

int main() {
	scanf("%d %d %d", &N, &M, &H);
	int total = 0;
	int other = 0;
	for(int i = 1; i <= M; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (i != H) other += tmp;
		total += tmp;
	}
	total--;

	if (total < N - 1) {
		printf("-1\n");
	} else {
		double rat = 1;
		for(int i = 0; i < N - 1; ++i) {
			rat *= other - i;
			rat /= total - i;
		}
		double ans = 1 - rat;
		printf("%.10lf\n", ans);
	}
	return 0;
}