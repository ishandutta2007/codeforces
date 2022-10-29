#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 70
#define maxm 70
#define maxk 2014
#define INF 500000000

using namespace std;

const int max_num = 1000;
int n, m, r;
int mtr[maxm][maxn][maxn];
int res[maxn][maxn][maxk];
int minl[maxn][maxn];

int precalc_fld(){
	for(int ii = 1; ii <= m; ++ii)
		for(int k = 1; k <= n; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
					mtr[ii][i][j] = min(mtr[ii][i][j], mtr[ii][i][k] + mtr[ii][k][j]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			minl[i][j] = INF;
			for(int ii = 1; ii <= m; ++ii)
				minl[i][j] = min(minl[i][j], mtr[ii][i][j]);
		}
	return 0;
}

int make_dijkstra(const int &x){
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= max_num; ++j)
			res[x][i][j] = INF;
	res[x][x][0] = 0;
	for(int i = 1; i <= n; ++i)res[x][i][0] = min(res[x][i][0], minl[x][i]);
	for(int ii = 1; ii <= n; ++ii)
		for(int i = 1; i <= n; ++i){
			res[x][i][ii] = res[x][i][ii - 1];
			for(int j = 1; j <= n; ++j)
				res[x][i][ii] = min(res[x][i][ii], res[x][j][ii - 1] + minl[j][i]);
		}
	return 0;
}

int precalc(){
	precalc_fld();
	for(int i = 1; i <= n; ++i)make_dijkstra(i);
	return 0;
}

int main(){
	//freopen("input.txt", "r", stdin);

	scanf("%d%d%d", &n, &m, &r);
	for(int ii = 1; ii <= m; ++ii)
		for(int ij = 1; ij <= n; ++ij)
			for(int ik = 1; ik <= n; ++ik)
				scanf("%d", &mtr[ii][ij][ik]);

	precalc();
	for(int i = 1; i <= r; ++i){
		int s, t, k;
		scanf("%d%d%d", &s, &t, &k);
		printf("%d\n", res[s][t][min(k, n)]);
	}

	return 0;
}