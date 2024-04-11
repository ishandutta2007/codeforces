#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1100;
pii ar[MAXN];

int N, K;

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		ar[i] = pii(tmp, i + 1);
	}
	sort(ar, ar + N);
	printf("%d\n", ar[N - K].first);
	for(int i = 0; i < K; ++i) {
		int x = ar[N - 1 - i].second;
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}