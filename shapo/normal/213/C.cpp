#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

#define maxn 650
#define INF 1e8

using namespace std;

int a[maxn][maxn], apr[maxn][maxn];
int n;
int w[maxn][maxn];

int input_data(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &w[i][j]);
	return 0;
}

int get(int dg, int pos){
	int x (dg), y (1);
	if(dg > n){
		x = n;
		y = dg - n + 1;
	}
	x -= pos - 1;
	y += pos - 1;
	return w[x][y];
}

int num(int dg){
	if(dg > n)
		return (2 * n - dg);
	return dg;
}

int proc(int x){
	int wid = num(x), wp = num(x - 1);
	for(int i = 1; i <= wp; ++i)
		for(int j = 1; j <= wp; ++j){
			apr[i][j] = a[i][j];
			a[i][j] = -INF;
		}
	for(int i = 1; i <= wid; ++i)
		for(int j = 1; 	j <= wid; ++j){
			if(x <= n){
				if(i != wid){
					if(j != wid)a[i][j] = max(a[i][j], apr[i][j]);
					if(j != 1)a[i][j] = max(a[i][j], apr[i][j - 1]);
				}
				if(i != 1){
					if(j != wid)a[i][j] = max(a[i][j], apr[i - 1][j]);
					if(j != 1)a[i][j] = max(a[i][j], apr[i - 1][j - 1]);
				}
			}
			else{
				a[i][j] = max(a[i][j], 
						max(max(apr[i][j], apr[i][j + 1]), 
							max(apr[i + 1][j], apr[i + 1][j + 1])));
			}
			a[i][j] += get(x, i);
			if(i != j)a[i][j] += get(x, j);
			//printf("x = %d, a[%d][%d] = %d\n", x, i, j, a[i][j]);
		}
	return 0;
}

int main(){
	input_data();
	for(int i = 0; i < maxn; ++i)
		for(int j = 0; j < maxn; ++j)
			a[i][j] = -INF;
	a[1][1] = w[1][1];
	for(int i = 2; i <= 2 * n - 1; ++i)
		proc(i);
	printf("%d\n", a[1][1]);
	return 0;
}