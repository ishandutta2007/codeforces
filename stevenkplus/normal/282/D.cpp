#include <cstdio>

using namespace std;

const int MAXN = 310;

char first[] = "BitLGM";
char second[] = "BitAryo";

int N;
int ans[MAXN][MAXN][MAXN];
bool lose[MAXN][MAXN][MAXN];
bool losea[MAXN][MAXN];
bool loseb[MAXN][MAXN];
bool losec[MAXN][MAXN];

void lost(int a, int b, int c) {
	losea[b][c] = true;
	loseb[a][c] = true;
	losec[a][b] = true;
	int x = a;
	if (b < x) x = b;
	if (c < x) x = c;
	lose[a - x][b - x][c - x] = true;
}

bool win(int a, int b, int c) {
	if (losea[b][c]) return true;
	if (loseb[a][c]) return true;
	if (losec[a][b]) return true;
	int x = a;
	if (b < x) x = b;
	if (c < x) x = c;
	if (lose[a - x][b - x][c - x]) return true;
	return false;
}

int ans2[MAXN][MAXN];

int win2(int a, int b) {
	for(int i = 0; i < a; ++i) {
		if (ans2[i][b] == 0) return 1;
	}
	for(int i = 0; i < b; ++i) {
		if (ans2[a][i] == 0) return 1;
	}
	for(int i = 1; i <= a && i <= b; ++i) {
		if (ans2[a - i][b - i] == 0) return 1;
	}
	return 0;
}

int a, b, c;
int go() {
	scanf("%d", &N);
	if (N == 1) {

		scanf("%d", &a);
		if (a == 0) return 0;
		else return 1;
	} else if (N == 2) {

		scanf("%d %d", &a, &b);
		for(int i = 0; i < MAXN; ++i) {
			for(int j = 0; j < MAXN; ++j) {
				ans2[i][j] = win2(i, j);
			}
		}
		return ans2[a][b];
	} else {

		scanf("%d %d %d", &a, &b, &c);
		for(int i = 0; i < MAXN; ++i) {
			for(int j = 0; j < MAXN; ++j) {
				for(int k = 0; k < MAXN; ++k) {
					if (win(i, j, k)) {
						ans[i][j][k] = 1;
					} else {
						ans[i][j][k] = 0;
						lost(i, j, k);
					}
				}
			}
		}
		return ans[a][b][c];
	}
}

int main() {
	if (go() == 1) {
		printf("%s\n", first);
	} else {
		printf("%s\n", second);
	}
	return 0;
}