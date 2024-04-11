#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, a[4][N], f[N][5];

void qmax(int &x, int y) { x = x > y? x : y; }

signed main() {
	n = get();
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = get();
	memset(f, -0x3f, sizeof(f));
	f[1][0] = a[1][1];
	f[1][1] = a[1][1] + a[2][1];
	f[1][2] = a[1][1] + a[2][1] + a[3][1];
	f[1][3] = a[1][1] + a[2][1] + a[3][1];
	for(int i = 2; i <= n; i++) {
		qmax(f[i][0], f[i - 1][0] + a[1][i]);
		qmax(f[i][0], f[i - 1][1] + a[2][i] + a[1][i]);
		qmax(f[i][0], f[i - 1][2] + a[3][i] + a[2][i] + a[1][i]);
		qmax(f[i][0], f[i - 1][4] + a[3][i] + a[2][i] + a[1][i]);
		qmax(f[i][1], f[i - 1][0] + a[2][i] + a[1][i]);
		qmax(f[i][1], f[i - 1][1] + a[2][i]);
		qmax(f[i][1], f[i - 1][2] + a[3][i] + a[2][i]);
		qmax(f[i][2], f[i - 1][0] + a[1][i] + a[2][i] + a[3][i]);
		qmax(f[i][2], f[i - 1][1] + a[2][i] + a[3][i]);
		qmax(f[i][2], f[i - 1][2] + a[3][i]);
		qmax(f[i][2], f[i - 1][3] + a[1][i] + a[2][i] + a[3][i]);
		qmax(f[i][3], f[i - 1][0] + a[1][i] + a[2][i] + a[3][i]);
		qmax(f[i][3], f[i - 1][4] + a[1][i] + a[2][i] + a[3][i]);
		qmax(f[i][4], f[i - 1][2] + a[1][i] + a[2][i] + a[3][i]);
		qmax(f[i][4], f[i - 1][3] + a[1][i] + a[2][i] + a[3][i]);
	}
	cout << f[n][2];
	return 0;
}