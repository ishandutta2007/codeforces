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

#define maxn 50010
#define maxk 510
#define maxm 100500

using namespace std;

struct edge{int x, next;};

int num[maxn][maxk];
int n, k, edges = 0;
int beg[maxn], en[maxn];
int used[maxn];
edge sm[maxm];
long long res = 0;

long long mult(const int &a, const int &b){
	long long aa = a, bb = b, cc = aa * bb;
	return cc;
}

int add(const int &x, const int &y, int &n){
	++n; sm[n].x = y; sm[n].next = 0;
	if(beg[x] == 0)beg[x] = n;
	if(en[x] != 0)sm[en[x]].next = n;
	en[x] = n;
	return 0;
}

int DFS(const int &cur, const int &par){
	used[cur] = 1;
	int i = beg[cur];
	for(int j = 0; j <= k; ++j)num[cur][j] = 0;
	num[cur][0] = 1;
	long long ccr = 0;
	while(i != 0){
		if(!used[sm[i].x]){
			DFS(sm[i].x, cur);
			for(int j = 1; j <= k; ++j){
				num[cur][j] = num[cur][j] + num[sm[i].x][j - 1];
				if(j <= (k - 1) / 2)res = res - mult(num[sm[i].x][j - 1], num[sm[i].x][k - j - 1]);
			}
			if(k % 2 == 0)ccr = ccr - mult(num[sm[i].x][k / 2 - 1], num[sm[i].x][k / 2 - 1]);
		}
		i = sm[i].next;
	}
	//for(int ii = 0; ii <= k; ++ii)printf("num[%d][%d] = %d\n", cur, ii, num[cur][ii]);
	for(int ii = 0; ii <= (k - 1) / 2; ++ii)res = res + mult(num[cur][ii], num[cur][k - ii]);
	if(k % 2 == 0)ccr = ccr + mult(num[cur][k / 2], num[cur][k / 2]);
	res = res + ccr / 2;
	return 0;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n - 1; ++i){
		int a, b;
		a = n; b = i;
		scanf("%d%d", &a, &b);
		add(a, b, edges);
		add(b, a, edges);
	}
	
	DFS(1, 0);
	
	cout << res << endl;
	
	return 0;
}