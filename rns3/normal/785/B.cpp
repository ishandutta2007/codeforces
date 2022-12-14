#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 10000000000

int n, m, st, en, stmax1 = 0, enmin1 = INF, stmax2 = 0, enmin2 = INF;

int main() {
	scanf("%d", &n);
	while (n --) {
		scanf("%d %d", &st, &en);
		stmax1 = max(stmax1, st);
		enmin1 = min(enmin1, en);
	}
	scanf("%d", &m);
	while (m --) {
		scanf("%d %d", &st, &en);
		stmax2 = max(stmax2, st);
		enmin2 = min(enmin2, en);
	}
	int rlt = max(0, max(stmax1 - enmin2, stmax2 - enmin1));
	printf("%d\n", rlt);
	return 0;
}