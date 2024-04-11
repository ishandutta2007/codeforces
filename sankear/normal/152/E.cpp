#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

const int inf = (int)1e9;
const int steps = 300;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
bool need[110][110];
char out[110][110];
int a[110][110], num[110][110];
int d[130][110][110], tp[130][110][110], gomask[130][110][110], gox[130][110][110], goy[130][110][110];

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void path(int mask, int x, int y){
	if(tp[mask][x][y] == 1){
		out[x][y] = 'X';
		return;
	}
	if(tp[mask][x][y] == 2){
		path(gomask[mask][x][y], x, y);
		path(mask ^ gomask[mask][x][y], gox[mask][x][y], goy[mask][x][y]);
		return;
	}
	path(mask, gox[mask][x][y], goy[mask][x][y]);
	out[x][y] = 'X';
}

int main(){
	//freopen("tea.in", "r", stdin);
	//freopen("tea.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < k; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		need[x][y] = true;
		num[x][y] = i;
	}
	int all = (1 << k);
	for(int i = 0; i < all; i++){
		for(int j = 0; j < n; j++){
			for(int z = 0; z < m; z++){
				d[i][j][z] = inf;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(need[i][j]){
				d[(1 << num[i][j])][i][j] = a[i][j];
				tp[(1 << num[i][j])][i][j] = 1;
			}
		}
	}
	for(int i = 0; i < all; i++){
		for(int j = 0; j < n; j++){
			for(int z = 0; z < m; z++){
				for(int h = 0; h < 4; h++){
					int x = j + dx[h], y = z + dy[h];
					if(!good(x, y)){
						continue;
					}
					for(int t = i; t > 0; t = (t - 1) & i){
						if(t == i){
							continue;
						}
						int res = d[t][j][z] + d[i ^ t][x][y];
						if(res < d[i][j][z]){
							d[i][j][z] = res;
							tp[i][j][z] = 2;
							gomask[i][j][z] = t;
							gox[i][j][z] = x;
							goy[i][j][z] = y;
						}
					}
				}
			}
		}
		for(int h = 0; h < steps; h++){
		for(int j = 0; j < n; j++){
			for(int z = 0; z < m; z++){
					for(int t = 0; t < 4; t++){
						int x = j + dx[t], y = z + dy[t];
						if(!good(x, y)){
							continue;
						}
						int res = d[i][x][y] + a[j][z];
						if(res < d[i][j][z]){
							d[i][j][z] = res;
							tp[i][j][z] = 3;
							gox[i][j][z] = x;
							goy[i][j][z] = y;
						}
					}
				}
			}
		}
	}
	int ans = inf, x, y;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(d[all - 1][i][j] < ans){
				ans = d[all - 1][i][j];
				x = i;
				y = j;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			out[i][j] = '.';
		}
	}
	path(all - 1, x, y);
	printf("%d\n", ans);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%c", out[i][j]);
		}
		printf("\n");
	}
	return 0;
}