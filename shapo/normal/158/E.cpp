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

#define maxn 5000

using namespace std;

int n, k;
int res;
int p[maxn][maxn];
int d[maxn], t[maxn];
int min_f[100000];
const int maxt = 1000000000;

int min(const int &a, const int &b){if(a < b)return a; return b;}

int max(const int &a, const int &b){if(a > b)return a; return b;}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)scanf("%d%d", &d[i], &t[i]);
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			p[i][j] = maxt;
	for(int i = 0; i < 100000; ++i)min_f[i] = maxt;
	p[0][0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= i; ++j)
			if(j == 0)p[i][j] = max(p[i - 1][0] + 1, d[i]) + t[i] - 1;
			else p[i][j] = min(p[i - 1][j - 1], max(p[i - 1][j] + 1, d[i]) + t[i] - 1);
	int m = 1, j = 0; res = 0;
	d[n + 1] = 86401;
	for(int i = 1; i <= 86400; ++i){
		if(m <= n && d[m] == i){
			++m;
			j = 0;
			while(j <= k && p[m - 1][j] >= i)++j;
		}
		else while(j > 0 && p[m - 1][j - 1] < i)--j;
		if(j <= k){
			int rt = d[min(n + 1, m + (k - j))];
			res = max(res, rt - i);
		}
	}
	printf("%d\n", res);
	
	return 0;
}