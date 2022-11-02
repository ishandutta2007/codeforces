#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int Y, X, s[505][505], t[505][505], Q;
char g[505][505];

bool c(int y, int x) {
	return g[y][x] == '.';
}

int main()
{
	scanf("%d%d", &Y, &X);
	for (int y = 1; y <= Y; y++) scanf(" %s", g[y]+1);
	for (int y = 1; y <= Y; y++) for (int x = 1; x <= X; x++) {
		if (y+1 <= Y && c(y, x) && c(y+1, x)) s[y][x]++;
		if (x+1 <= X && c(y, x) && c(y, x+1)) t[y][x]++;
		s[y][x] = s[y][x] + s[y-1][x] + s[y][x-1] - s[y-1][x-1];
		t[y][x] = t[y][x] + t[y-1][x] + t[y][x-1] - t[y-1][x-1];
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int y1, x1, y2, x2; scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		printf("%d\n", s[y2-1][x2] - s[y2-1][x1-1] - s[y1-1][x2] + s[y1-1][x1-1] +
					   t[y2][x2-1] - t[y2][x1-1] - t[y1-1][x2-1] + t[y1-1][x1-1]);
	}
}