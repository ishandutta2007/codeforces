#include <cstdio>

const int MAXN = 50100;

char str[MAXN];
int nxt[MAXN];
int N = 0;

int main() {
	scanf("%s", str);
	while (str[N]) {
		nxt[N] = N + 1;
		++N;
	}

	int len = N;
	for(int i = 1; i <= len / 2; ++i) {
		int a = 0;
		int b = 0;
		int start = 0;
		for(int j = 0; j < i; ++j) {
			b = nxt[b];
		}
		int cnt = 0;
		while (b < N) {
			if (str[a] == str[b]) {
				++cnt;
			} else {
				start = nxt[a];
				cnt = 0;
			}
			b = nxt[b];

			if (cnt == i) {
				cnt = 0;
				len -= i;
				nxt[a] = b;
				a = start;
			} else {
				a = nxt[a];
			}
		}
	}

	int i = 0;
	while (i < N) {
		printf("%c", str[i]);
		i = nxt[i];
	}
	printf("\n");
	return 0;
}