#include <cstdio>

using namespace std;

const int MAXN = 100100;

int N;
int ar[MAXN];

bool works(int a, int b) {
	if (ar[a] == ar[b]) return false;
	int prev = -1;
	bool up = true;
	bool down = true;
	for(int i = 0; i < N; ++i) {
		int j = i;
		if (j == b) {
			j = a;
		} else if (j == a) {
			j = b;
		}
		if (prev == -1) {
			prev = ar[j];
		}
		if (ar[j] < prev) {
			up = false;
		}
		if (ar[j] > prev) {
			down = false;
		}
		prev = ar[j];
	}
	return !(up || down);
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	if (N < 100) {
		for(int i = 0; i < N; ++i) {
			for(int j = i + 1; j < N; ++j) {
				if (works(i, j)) {
					printf("%d %d\n", i + 1, j + 1);
					return 0;
				}
			}
		}
		printf("-1\n");
	} else {
		int first = ar[0];
		bool allsame = true;
		for(int i = 0; i < N; ++i) {
			if (first != ar[i]) {
				allsame = false;
			}
		}
		if (allsame) {
			printf("-1\n");
			return 0;
		}
		for(int i = 1; i < 4; ++i) {
			for(int k = 0; k < i; ++k) {
				if (ar[i] == ar[k]) {
					for(int j = i + 1; j < N; ++j) {
						if (works(i, j)) {
							printf("%d %d\n", i + 1, j + 1);
							return 0;
						}
					}
				}
			}
			for(int j = 0; j < i; ++j) {
				if (works(i, j)) {
					printf("%d %d\n", i + 1, j + 1);
					return 0;
				}
			}
		}
	}
	return 0;
}