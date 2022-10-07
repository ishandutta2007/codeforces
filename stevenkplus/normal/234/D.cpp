#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 110;
bool isFav[MAXN];
int numFav[MAXN];
int maxFav[MAXN];

int M, K;
int N;

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	scanf("%d %d", &M, &K);
	for(int i = 0; i < K; ++i) {
		int tmp;
		scanf("%d", &tmp);
		isFav[tmp] = true;
	}
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%*s");
		int D;
		scanf("%d", &D);
		int fav = 0;
		int free = 0;
		int notFav = M - K;
		for(int j = 0; j < D; ++j) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 0) {
				free++;
			} else if (isFav[tmp]) {
				fav++;
			} else {
				notFav--;
			}
		}
		numFav[i] = fav + max(0, free - notFav);
		maxFav[i] = min(fav + free, K);
	}
	for(int i = 0; i < N; ++i) {
		int m1 = 0;
		int m2 = 0;
		for(int j = 0; j < N; ++j) {
			if (i != j) {
				m1 = max(m1, numFav[j]);
				m2 = max(m2, maxFav[j]);
			}
		}
		int res;
		if (numFav[i] >= m2) {
			res = 0;
		} else if (maxFav[i] < m1) {
			res = 1;
		} else {
			res = 2;
		}
		printf("%d\n", res);
	}
	return 0;
}