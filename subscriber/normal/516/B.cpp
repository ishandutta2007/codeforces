#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
char a[2222][2222];
int h[2222][2222];

int q[8000888];
int q1, q2;

void match(int x, int y, int xx, int yy) {
	if (x < xx) {
		a[x][y] = '^';
		a[xx][yy] = 'v';
	}
	if (x > xx) {
		a[xx][yy] = '^';
		a[x][y] = 'v';
	}
	if (y < yy) {
		a[x][y] = '<';
		a[xx][yy] = '>';
	}
	if (y > yy) {
		a[xx][yy] = '<';
		a[x][y] = '>';
	}
}

void er(){
	puts("Not unique");
	exit(0);
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++) gets(a[i]);

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == '.') {
		h[i][j] = 0;
		for (int d = 0; d < 4; d++) {
			int x = i + dx[d];
			int y = j + dy[d];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (a[x][y] == '.') h[i][j]++;
		}
		if (h[i][j] == 1) {
			q[q1++] = i;
			q[q1++] = j;
		}			
	}
	while (q1 != q2) {
		int x = q[q2++];
		int y = q[q2++];
		if (a[x][y] != '.') continue;

		int X = -1, Y;
		for (int d = 0; d < 4; d++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (a[xx][yy] == '.') {
				X = xx;
				Y = yy;
				break;
			}
		}
		if (X == -1) er();
		match(x, y, X, Y);
		for (int d = 0; d < 4; d++) {
			int xx = X + dx[d];
			int yy = Y + dy[d];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (a[xx][yy] == '.') {
				h[xx][yy]--;
				if (h[xx][yy] == 1) {
					q[q1++] = xx;
					q[q1++] = yy;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == '.') er();
	for (int i = 0; i < n; i++) puts(a[i]);
	return 0;
}