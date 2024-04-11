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

#define maxn 100500

using namespace std;

int n, m, l, r, k, x, y;
int a[maxn], b[maxn], par[maxn][2];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for(int i = 1; i <= n; ++i)scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i)scanf("%d", &b[i]);
	
	k = 0;
	l = r = 1;
	while(l <= n && r <= m){
		if(-x <= b[r] - a[l] && b[r] - a[l] <= y){
			++k; par[k][1] = l; par[k][2] = r;
			++l; ++r;
		}
		else{
			if(b[r] - a[l] > y)++l;else ++r;
		}
	}
	
	printf("%d\n", k);
	for(int i = 1; i <= k; ++i)printf("%d %d\n", par[i][1], par[i][2]);
	
	return 0;
}