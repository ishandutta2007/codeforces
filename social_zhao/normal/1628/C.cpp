#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int n, a[N][N], vis[N][N], imp[N][N], nd, nx, ny;

int ill(int x, int y) {
	if(x < 1 || x > n || y < 1 || y > n) return 1;
	if(vis[x][y]) return 1;
	return 0;
}

int der(int x, int y) {
	if(x < 1 || x > n || y < 1 || y > n) return 1;
	return 0;
}

void jump() {
	int px = nx + dx[nd], py = ny + dy[nd];
	if(ill(px, py)) nd = (nd + 1) % 4, px = nx + dx[nd], py = ny + dy[nd];
	nx = px, ny = py;
}

void pushtag(int x, int y) {
	imp[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			int px = x + dx[i], py = y + dy[j];
			if(!der(px, py)) vis[px][py]++;
		}
	}
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) 
			a[i][j] = get(), vis[i][j] = 0;
	if(n == 2) {
		cout << (a[1][1] ^ a[1][2]) << endl;
		return;
	}
	nd = 0, nx = 1, ny = 1;
	int ans = 0;
	while(!ill(nx, ny)) {
		ans ^= a[nx][ny];
		int A = nx, B = ny;
		jump();
		ans ^= a[nx][ny];
		int C = nx, D = ny;
		jump(), jump(), jump();
		pushtag(A, B), pushtag(C, D);
	}
	cout << ans << endl;
//	for(int i = 1; i <= n; i++, cout << endl)
//		for(int j = 1; j <= n; j++)
//			cout << imp[i][j] << " ";
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/