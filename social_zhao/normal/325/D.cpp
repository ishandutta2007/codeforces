#include<bits/stdc++.h>
using namespace std;

inline int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e7 + 5;
int r, c, n, f[N], ans = 0;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
bool delt[3005][6005];

inline int id(int x, int y) {
	return (x - 1) * c * 2 + y;
}

inline bool ok(int &x, int &y) {
	if(y == 0) y = c * 2;
	else if(y == c * 2 + 1) y = 1;
	return (x > 0 && x <= r && delt[x][y]);
}

inline int find(int x) {
	return x == f[x]? x : f[x] = find(f[x]);
}

inline bool chk(int x, int y) {
	int x1 = x, y1 = y + c;
	for(register int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(!ok(nx, ny)) continue;
		for(register int j = 0; j < 8; j++) {
			int nx1 = x1 + dx[j], ny1 = y1 + dy[j];
			if(!ok(nx1, ny1)) continue;
			if(find(id(nx, ny)) == find(id(nx1, ny1))) { return 0; }
		}
	}
	return 1;
}

inline void merge(int a, int b) {
	int x = find(a), y = find(b);
	f[x] = y;
}

inline void del(int x, int y) {
	int x1 = x, y1 = y + c;
	for(register int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(ok(nx, ny)) merge(id(x, y), id(nx, ny));
		int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
		if(ok(nx1, ny1)) merge(id(x1, y1), id(nx1, ny1));
	}
	delt[x][y] = 1;
	delt[x1][y1] = 1;
}

int main() {
	r = get(), c = get(), n = get();
	if(c == 1) {
		printf("0");
		return 0;
	}
	for(register int i = 1; i <= r; i++)
		for(register int j = 1; j <= c * 2; j++)
			f[id(i, j)] = id(i, j);
	while(n--) {
		int x = get(), y = get();
		if(chk(x, y)) del(x, y), ans++;
	}
	printf("%d\n", ans);
	return 0;
}