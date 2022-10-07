#include <cstdio>

const int MAXN = 100100;

int N, M;

int ar[MAXN];

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
	}

	int idx, val;
	int add = 0;

	for(int i = 0; i < M; ++i) {
		int qtype;
		scanf("%d", &qtype);
		if (qtype == 1) {
			scanf("%d %d", &idx, &val);
			ar[idx] = val - add;
		} else if (qtype == 2) {
			scanf("%d", &val);
			add += val;
		} else {
			scanf("%d", &idx);
			int ans = ar[idx] + add;
			printf("%d\n", ans);
		}
	}

	return 0;
}