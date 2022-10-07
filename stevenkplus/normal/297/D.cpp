#include <cstdio>

const int MAXN = 1010;

int X, Y, K;

bool horiz[MAXN][MAXN]; // true-> equal
bool vert[MAXN][MAXN];
int ans[MAXN][MAXN];
char buf[MAXN];

void disp() {
	for(int i = 0; i < X; ++i) {
		for(int j = 0; j < Y; ++j) {
			if (j) printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d %d", &X, &Y, &K);

	for(int i = 0; i < X; ++i) {
		scanf("%s", buf);
		for(int j = 0; j < Y - 1; ++j) {
			horiz[i][j + 1] = buf[j] == 'E';
		}

		if (i < X - 1) {
			scanf("%s", buf);
			for(int j = 0; j < Y; ++j) {
				vert[i + 1][j] = buf[j] == 'E';
			}
		}
	}

	if (K == 1) {
		int cnt = 0;
		int tot = 0;
		for(int i = 0; i < X; ++i) {
			for(int j = 0; j < Y; ++j) {
				ans[i][j] = 1;
			}
		}

		for(int i = 0; i < X; ++i) {
			for(int j = 1; j < Y; ++j) {
				if (horiz[i][j]) ++cnt;
				++tot;
			}
		}
		for(int i = 1; i < X; ++i) {
			for(int j = 0; j < Y; ++j) {
				if (vert[i][j]) ++cnt;
				++tot;
			}
		}
		if (cnt * 4 >= tot * 3) {
			printf("YES\n");
			disp();
		} else {
			printf("NO\n");
		}
	} else {

		if (X <= Y) {
			for(int i = 0; i < X; ++i) {
				ans[i][0] = 1;
				for(int j = 1; j < Y; ++j) {
					if (horiz[i][j]) {
						ans[i][j] = ans[i][j - 1];
					} else {
						ans[i][j] = 3 - ans[i][j - 1];
					}
				}
				if (i) {
					int good = 0;
					int bad = 0;
					for(int j = 0; j < Y; ++j) {
						if (vert[i][j]) {
							if (ans[i][j] == ans[i - 1][j]) ++good;
							else ++bad;
						} else {
							if (ans[i][j] != ans[i - 1][j]) ++good;
							else ++bad;
						}
					}
					if (bad > good) {
						for(int j = 0; j < Y; ++j) {
							ans[i][j] = 3 - ans[i][j];
						}
					}
				}
			}
		} else {
			for(int j = 0; j < Y; ++j) {
				ans[0][j] = 1;
				for(int i = 1; i < X; ++i) {
					if (vert[i][j]) ans[i][j] = ans[i - 1][j];
					else ans[i][j] = 3 - ans[i - 1][j];
				}
				if (j) {
					int good = 0;
					int bad = 0;
					for(int i = 0; i < X; ++i) {
						if (horiz[i][j]) {
							if (ans[i][j] == ans[i][j - 1]) ++good;
							else ++bad;
						} else {
							if (ans[i][j] != ans[i][j - 1]) ++good;
							else ++bad;
						}
					}
					if (bad > good) {
						for(int i = 0; i < X; ++i) {
							ans[i][j] = 3 - ans[i][j];
						}
					}
				}
			}
		}

		printf("YES\n");
		disp();
	}
	return 0;
}