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

int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool used[100][100];
int val[100][100];
int queue[20000];

inline bool good(int x, int y){
	return x >= 0 && x <= 2 * n && y >= 0 && y <= 2 * n && !used[x][y];
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  scanf("%d", &n);
	used[n][n] = true;
	val[n][n] = n;
	int l = 0;
	int r = 2;
	queue[0] = n;
	queue[1] = n;
	while(l < r){
		int x = queue[l++];
		int y = queue[l++];
		if(val[x][y] == 0){
			continue;
		}
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(!good(xx, yy)){
				continue;
			}
			used[xx][yy] = true;
			val[xx][yy] = val[x][y] - 1;
			queue[r++] = xx;
			queue[r++] = yy;
		}
	}
	for(int i = 0; i <= 2 * n; i++){
		int pos = 2 * n;
		while(!used[i][pos]){
			pos--;
		}
		for(int j = 0; j <= pos; j++){
			if(j > 0){
				printf(" ");
			}
			if(!used[i][j]){
				printf(" ");
				continue;
			}
			printf("%d", val[i][j]);
		}
		printf("\n");
	}
	return 0;
}