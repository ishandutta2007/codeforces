#include <cstdio>

using namespace std;

const int MAXN = 110;
bool rflip[MAXN];
bool cflip[MAXN];

int ar[MAXN][MAXN];

int N, M;

bool go() {
	for(int i = 0; i < N; ++i) {
		int sum = 0;
		for(int j = 0; j < M; ++j) {
			if (rflip[i] ^ cflip[j]) {
				sum -= ar[i][j];
			} else {
				sum += ar[i][j];
			}
		}
		if (sum < 0) {
			rflip[i] ^= 1;
			return true;
		}
	}

	for(int i = 0; i < M; ++i) {
		int sum = 0;
		for(int j = 0; j < N; ++j) {
			if (rflip[j] ^ cflip[i]) {
				sum -= ar[j][i];
			} else {
				sum += ar[j][i];
			}
		}
		if (sum < 0) {
			cflip[i] ^= 1;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			scanf("%d", ar[i] + j);
		}
	}

	while (go())
		;
	int cnt = 0;
	for(int i = 0; i < N; ++i) {
		if (rflip[i]) ++cnt;
	}
	printf("%d", cnt);
	for(int i = 0; i < N; ++i) {
		if (rflip[i]) printf(" %d", i + 1);
	}
	printf("\n");

	cnt = 0;
	for(int i = 0; i < M; ++i) {
		if (cflip[i]) ++cnt;
	}
	printf("%d", cnt);
	for(int i = 0; i < M; ++i) {
		if (cflip[i]) printf(" %d", i + 1);
	}
	printf("\n");
	return 0;
}