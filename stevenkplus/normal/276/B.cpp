#include <cstdio>

int conv(char c) {
	return c - 'a';
}

const int MAXC = 30;
const int MAXN = 10100;
int cnts[MAXC];

char str[MAXN];

int main() {
	scanf("%s", str);
	for(int i = 0; str[i]; ++i) {
		++cnts[conv(str[i])];
	}

	int ans = 0;
	for(int i = 0; i < MAXC; ++i) {
		if (cnts[i] % 2) ++ans;
	}

	if (ans <= 1 || ans % 2 == 1) {
		printf("First\n");
	} else {
		printf("Second\n");
	}
	return 0;
}