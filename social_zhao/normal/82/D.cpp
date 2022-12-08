#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005;
int n, a[N], f[N][N], pre[N][N];

void dfs(int x, int y) {
	if(!x) return;
	int lst = pre[x][y];
	dfs(x - 1, lst);
	int a = 0, b = 0;
	if(x == 1) {
		if(y == 1) a = 2, b = 3;
		if(y == 2) a = 1, b = 3;
		if(y == 3) a = 1, b = 2;
	} 
	else {
		if(y == x * 2) a = lst, b = x * 2 + 1;
		else if(y == x * 2 + 1) a = lst, b = x * 2;
		else if(y == lst) a = x * 2, b = x * 2 + 1;
	}
	if(a <= n) printf("%d ", a);
	if(b <= n) printf("%d ", b);
	printf("\n");
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	memset(f, 0x3f, sizeof(f));
	f[1][1] = max(a[2], a[3]), f[1][2] = max(a[1], a[3]), f[1][3] = max(a[1], a[2]);
	pre[1][1] = 2, pre[1][2] = 1, pre[1][3] = 1;
	for(int i = 2; i <= (n + 1) / 2; i++)
		for(int j = 1; j < 2 * i; j++) {
			int x = j, y = 2 * i, z = 2 * i + 1;
			if(f[i - 1][j] + max(a[y], a[z]) < f[i][x]) f[i][x] = f[i - 1][j] + max(a[y], a[z]), pre[i][x] = j;
			if(f[i - 1][j] + max(a[x], a[z]) < f[i][y]) f[i][y] = f[i - 1][j] + max(a[x], a[z]), pre[i][y] = j;
			if(f[i - 1][j] + max(a[x], a[y]) < f[i][z]) f[i][z] = f[i - 1][j] + max(a[x], a[y]), pre[i][z] = j;
		}
	printf("%d\n", f[(n + 1) / 2][n + 1]);
	dfs((n + 1) / 2, n + 1);
	return 0;
}