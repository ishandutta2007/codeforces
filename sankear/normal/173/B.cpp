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
#include <queue>

using namespace std;

const int inf = (int)1e9;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
char a[1000][1000];
int d[1000][1000][4];
queue <int> q;

inline bool good(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int z = 0; z < 4; z++){
				d[i][j][z] = inf;
			}
		}
	}
	d[0][0][0] = 0;
	q.push(0);
	q.push(0);
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int z = q.front();
		q.pop();
		int xx = x + dx[z], yy = y + dy[z];
		if(good(xx, yy) && d[xx][yy][z] > d[x][y][z]){
			d[xx][yy][z] = d[x][y][z];
			q.push(xx);
			q.push(yy);
			q.push(z);
		}
		if(a[x][y] == '#'){
			for(int i = 0; i < 4; i++){
				if(true){
					if(d[x][y][i] > d[x][y][z] + 1){
						d[x][y][i] = d[x][y][z] + 1;
						q.push(x);
						q.push(y);
						q.push(i);
					}
				}
			}
		}
	}
	if(d[n - 1][m - 1][0] == inf){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", d[n - 1][m - 1][0]);
	return 0;
}