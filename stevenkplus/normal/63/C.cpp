#include <cstdio>

using namespace std;

const int MAXN = 1010;

int guesses[MAXN];
int hit[MAXN];
int miss[MAXN];

int N;

bool digseen[10];

int num[4];

bool check(int n) {
	for(int i = 0; i < 10; ++i) digseen[i] = false;
	int cop = n;
	for(int i = 0; i < 4; ++i) {
		if (digseen[cop % 10]) return false;
		digseen[cop % 10] = true;
		num[i] = cop % 10;
		cop /= 10;
	}

	for(int i = 0; i < N; ++i) {
		int h = 0;
		int m = 0;
		cop = guesses[i];
		for(int j = 0; j < 4; ++j) {
			int dig = cop % 10;
			if (num[j] == dig) {
				++h;
			} else if (digseen[dig]) {
				++m;
			}
			cop /= 10;
		}
		if (h != hit[i] || m != miss[i]) return false;
	}
	return true;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d %d %d", guesses + i, hit + i, miss + i);
	}

	int ans = -2;
	for(int i = 0; i < 10000; ++i) {
		if (check(i)) {
			if (ans == -2) {
				ans = i;
			} else {
				ans = -1;
				break;
			}
		}
	}

	if (ans == -2) {
		printf("Incorrect data\n");
	} else if (ans == -1) {
		printf("Need more data\n");
	} else {
		printf("%04d\n", ans);
	}
	return 0;
}