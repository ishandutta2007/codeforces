#include <cstdio>

const int MAXN = 100100;
int right[MAXN];

int N;

int ar[MAXN];
int check[MAXN];
int tmp[MAXN];
bool eaten[MAXN];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
		right[i] = i + 1;
	}
	ar[N] = N + 1;

	int tocheck = 0;
	for(int i = N - 2; i >= 0; --i) {
		check[tocheck++] = i;
	}

	int ans = 0;
	while (true) {
		for(int i = 0; i < tocheck; ++i) {
			int guy = check[i];
			if (ar[guy] > ar[right[guy]]) {
				eaten[right[guy]] = true;
				right[guy] = right[right[guy]];
			} else {
				eaten[guy] = true;
			}
		}

		int cnt = 0;
		for(int i = 0; i < tocheck; ++i) {
			if (!eaten[check[i]]) {
				check[cnt] = check[i];
				++cnt;
			}
		}
		tocheck = cnt;
		if (tocheck)
			++ans;
		else break;
	}

	printf("%d\n", ans);
	return 0;
}