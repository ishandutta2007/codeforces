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

#define y1 yy1

const int inf = (int)1e9;

int n, x1, y1, x2, y2, sz;
bool used[2020][2020];
int aa[2020][2020];

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < n && aa[x][y] == 1;
}

void dfs(int x, int y){
	used[x][y] = true;
	sz++;
	x1 = min(x1, x);
	y1 = min(y1, y);
	x2 = max(x2, x);
	y2 = max(y2, y);
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			int xx = x + i, yy = y + j;
			if(good(xx, yy) && !used[xx][yy]){
				dfs(xx, yy);
			}
		}
	}
}

int main(){
	//freopen("robotnavigation.in", "r", stdin);
	//freopen("robotnavigation.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &aa[i][j]);
		}
	}
	int a = 0, b = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(aa[i][j] == 1 && !used[i][j]){
				x1 = inf, y1 = inf, x2 = -inf, y2 = -inf;
				sz = 0;
				dfs(i, j);
				if(x2 - x1 == y2 - y1 && sz == (x2 - x1 + 1) * (y2 - y1 + 1)){
					b++;
				}
				else{
					a++;
				}
			}
		}
	}
	printf("%d %d\n", a, b);
	return 0;
}