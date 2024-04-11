#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 110;
int ar[MAXN];

int N;
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i + 1);
	}
	int moves = 0;
	for(int i = N; i >= 1; --i) {
		if (ar[i] > 0) {
			int j = i / 2;
			if (j <= 0) {
				if (i * 2 + 1 > N) {
					printf("-1\n");
					return 0;
				}
				moves += ar[i];
				break;
			}
			if (j * 2 + 1 > N) {
				printf("-1\n");
				return 0;
			}
			int k = ar[j * 2 + 1];
			int p = ar[j * 2];
			if (max(p,k) < 0) continue;
			moves += max(p, k);
			ar[j * 2 + 1] -= max(p,k);
			ar[j * 2] -= max(p,k);
			ar[j] -= max(p,k);
		}
	}
	printf("%d\n", moves);
	return 0;
}