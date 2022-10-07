#include <cstdio>

using namespace std;

const int MAXN = 100100;
const int MAXC = 50;

char str[MAXN];

bool vis[MAXC];

int conv(char c) {
	return c - 'A';
}

bool islet(char c) {
	return c >= 'A' && c <= 'Z';
}

int main() {
	scanf("%s", str);

	int zeros = 0;
	int prod = 1;
	int nxt = 10;
	for(int i = 0; str[i]; ++i) {
		char c = str[i];
		if (islet(c)) {
			if (!vis[conv(c)]) {
				vis[conv(c)] = true;
				if (i == 0) {
					prod *= nxt - 1;
				} else
					prod *= nxt;
				--nxt;
			}
		} else if (c == '?') {
			if (i == 0) {
				prod *= 9;
			} else {
				++zeros;
			}
		}
	}

	printf("%d", prod);
	for(int i = 0; i < zeros; ++i) {
		printf("0");
	}
	printf("\n");
	return 0;
}