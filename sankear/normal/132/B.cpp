#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

const int steps = 25;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[4][2] = {
	{0, 0},
	{-1, 1},
	{0, 0},
	{1, -1}
};
int ddy[4][2] = {
	{-1, 1},
	{0, 0},
	{1, -1},
	{0, 0}
};
int p[steps + 1];
int gox[steps + 1][50][50][4][2], goy[steps + 1][50][50][4][2], god[steps + 1][50][50][4][2];
int goc[steps + 1][50][50][4][2];
char s[50][51];

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
	}
	m = strlen(s[0]);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int z = 0; z < 4; z++){
				for(int t = 0; t < 2; t++){
					int x = i;
					int y = j;
					while(good(x + dx[z], y + dy[z]) && s[x + dx[z]][y + dy[z]] == s[x][y]){
						x += dx[z];
						y += dy[z];
					}
					while(good(x + ddx[z][t], y + ddy[z][t]) && s[x + ddx[z][t]][y + ddy[z][t]] == s[x][y]){
						x += ddx[z][t];
						y += ddy[z][t];
					}
					if(good(x + dx[z], y + dy[z]) && s[x + dx[z]][y + dy[z]] > '0'){
						gox[0][i][j][z][t] = x + dx[z];
						goy[0][i][j][z][t] = y + dy[z];
						god[0][i][j][z][t] = z;
						goc[0][i][j][z][t] = t;
					}
					else{
						gox[0][i][j][z][t] = x;
						goy[0][i][j][z][t] = y;
						if(t == 0){
							goc[0][i][j][z][t] = 1;
							god[0][i][j][z][t] = z;
						}
						else{
							goc[0][i][j][z][t] = 0;
							god[0][i][j][z][t] = (z + 1) % 4;
						}
					}
				}
			}
		}
	}
	p[0] = 1;
	for(int i = 1; i <= steps; i++){
		p[i] = p[i - 1] * 2;
		for(int j = 0; j < n; j++){
			for(int z = 0; z < m; z++){
				for(int h = 0; h < 4; h++){
					for(int t = 0; t < 2; t++){
						gox[i][j][z][h][t] = gox[i - 1][gox[i - 1][j][z][h][t]][goy[i - 1][j][z][h][t]][god[i - 1][j][z][h][t]][goc[i - 1][j][z][h][t]];
						goy[i][j][z][h][t] = goy[i - 1][gox[i - 1][j][z][h][t]][goy[i - 1][j][z][h][t]][god[i - 1][j][z][h][t]][goc[i - 1][j][z][h][t]];
						god[i][j][z][h][t] = god[i - 1][gox[i - 1][j][z][h][t]][goy[i - 1][j][z][h][t]][god[i - 1][j][z][h][t]][goc[i - 1][j][z][h][t]];
						goc[i][j][z][h][t] = goc[i - 1][gox[i - 1][j][z][h][t]][goy[i - 1][j][z][h][t]][god[i - 1][j][z][h][t]][goc[i - 1][j][z][h][t]];
					}
				}
			}
		}
	}
	int x = 0;
	int y = 0;
	int d = 1;
	int c = 0;
	for(int i = steps; i >= 0; i--){
		if(k >= p[i]){
			int nx = gox[i][x][y][d][c];
			int ny = goy[i][x][y][d][c];
			int nd = god[i][x][y][d][c];
			int nc = goc[i][x][y][d][c];
			x = nx;
			y = ny;
			d = nd;
			c = nc;
			k -= p[i];
		}
	}
	printf("%c\n", s[x][y]);
	return 0;
}