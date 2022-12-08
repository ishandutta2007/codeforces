#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 505;
int n, a[N][N], p[N];

int chk(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n && !a[x][y];
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) p[i] = get();
	for(int i = 1; i <= n; i++) {
		a[i][i] = p[i];
		int x = i, y = i;
		for(int j = 2; j <= p[i]; j++) {
			if(chk(x, y - 1)) y--, a[x][y] = p[i];
			else if(chk(x + 1, y)) x++, a[x][y] = p[i];
			else return printf("-1"), 0;
		}
	}
	for(int i = 1; i <= n; i++, printf("\n"))
		for(int j = 1; j <= i; j++)
			printf("%d ", a[i][j]);
	return 0;
}