#include <cstdio>

using namespace std;

const int MAXN = 110;

int ar[MAXN][MAXN];

int N;

void read() {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			scanf("%d", ar[i] + j);
		}
	}
}

const int MAXB = 30;

int main() {
	scanf("%d", &N);
	read();
	for(int i = 0; i < N; ++i) {
		int num = 0;
		for(int b = 0; b < N; ++b) {
			if (i != b) {
				num |= ar[i][b];
			}
		}
		if (i) {
			printf(" ");
		}
		printf("%d", num);
	}
	printf("\n");
	return 0;
}