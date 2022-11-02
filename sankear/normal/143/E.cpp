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

const double tl = 2.9;
const int iters = 100;

const int dx[4][5] = {
	{0, 0, 0, 1, 2},
	{0, 1, 1, 1, 2},
	{0, 1, 2, 2, 2},
	{0, 1, 1, 1, 2}
};
const int dy[4][5] = {
	{0, 1, 2, 1, 1},
	{2, 0, 1, 2, 2},
	{1, 1, 0, 1, 2},
	{0, 0, 1, 2, 0}
};

double start;
int n, m, ans, it;
bool used[20][20];
char best[20][20];
int xx[100], yy[100], zz[100];

inline void write(){
	printf("%d\n", ans);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%c", best[i][j]);
		}
		printf("\n");
	}
	exit(0);
}

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void gen(int x, int y, int z){
	it++;
	if(it >= iters){
		if((clock() - start) / CLOCKS_PER_SEC > tl){
			write();
		}
		it = 0;
	}
	if(x >= n){
		if(z <= ans){
			return;
		}
		ans = z;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				best[i][j] = '.';
			}
		}
		for(int i = 0; i < z; i++){
			for(int j = 0; j < 5; j++){
				best[xx[i] + dx[zz[i]][j]][yy[i] + dy[zz[i]][j]] = 'A' + i;
			}
		}
		return;
	}
	if(z + (n - x) * m / 5 <= ans){
		return;
	}
	/*if(used[x][y]){
		if(y + 1 >= m){
			gen(x + 1, 0, z);
		}
		else{
			gen(x, y + 1, z);
		}
		return;
	}*/
	if(x + 2 < n && y + 2 < m){
		for(int i = 0; i < 4; i++){
			bool can = true;
			for(int j = 0; j < 5; j++){
				if(!good(x + dx[i][j], y + dy[i][j]) || used[x + dx[i][j]][y + dy[i][j]]){
					can = false;
					break;
				}
			}
			if(!can){
				continue;
			}
			for(int j = 0; j < 5; j++){
				used[x + dx[i][j]][y + dy[i][j]] = true;
			}
			xx[z] = x;
			yy[z] = y;
			zz[z] = i;
			gen(x, y + 1, z + 1);
			for(int j = 0; j < 5; j++){
				used[x + dx[i][j]][y + dy[i][j]] = false;
			}
		}
	}
	if(y + 1 >= m){
		gen(x + 1, 0, z);
	}
	else{
		gen(x, y + 1, z);
	}
}

int main(){
	start = clock();
	//freopen("infinity.in", "r", stdin);
	//freopen("infinity.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			best[i][j] = '.';
		}
	}
	it = 0;
	gen(0, 0, 0);
	write();
	return 0;
}