#include <bits/stdc++.h>
using namespace std;
#define M 110
int c[M][M], n, a, b, N;

int main() {
//freopen("A.in", "r", stdin);
	scanf("%d %d %d", &n, &a, &b);
	if (a * b < n) return puts("-1"), 0;
	if (!(a & 1) && !(b & 1)) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				c[i][j] = ++N; if (N == n) break;
			}
			if (N == n) break;
		}
		for (int i = 0; i < a; i += 2) {
			for (int j = 0; j < b / 2; j++) swap(c[i][2*j], c[i][2*j+1]);
		}
	}
	else if (a & 1) {
		for (int i = 0; i < b; i++) for (int j = 0; j < a; j++) {
			c[j][i] = ++N; if (N == n) goto LA;
		}
	}
	else if (b & 1) {
		for (int i = 0; i < a; i++) for (int j = 0; j < b; j++) {
			c[i][j] = ++N; if (N == n) goto LA;
		}
	}
	LA:;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) printf("%d ", c[i][j]); puts("");
	}
}