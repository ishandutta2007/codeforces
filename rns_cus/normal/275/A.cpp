#include <bits/stdc++.h>
using namespace std;

int a[4][4], b[4][4];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
//	freopen("a.in", "r", stdin);
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) b[i][j] = 1;
	}
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) if (a[i][j] % 2) {
            b[i][j] = 1 - b[i][j];
            for (int k = 0; k < 4; k ++) {
				int I = i + dx[k], J = j + dy[k];
				if (I < 1 || I > 3 || J < 1 || J > 3) continue;
				b[I][J] = 1 - b[I][J];
            }
		}
	}
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) printf("%d", b[i][j]);
		puts("");
	}
	return 0;
}