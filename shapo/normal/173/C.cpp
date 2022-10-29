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

#define maxn 700

using namespace std;

int sum[maxn][maxn];
int res = -2000000000;
int n, m, cl, cr, ct, cb, cur_sum;

inline int sum_sub(const int &l, const int &b, const int &r, const int &t){
	return(sum[r][t] - sum[l - 1][t] - sum[r][b - 1] + sum[l - 1][b - 1]);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			scanf("%d", &sum[i][j]);
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
		
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			cl = i - 1; cr = i + 1; cb = j - 1; ct = j + 1;
			if(cl > 0 && cb > 0 && cr <= n && ct <= m)cur_sum = sum_sub(i, j, i, j);
			while(cl > 0 && cr <= n && cb > 0 && ct <= m){
				cur_sum = sum_sub(cl, cb, cr, ct) - sum_sub(cl + 1, cb, cl + 1, cb) - cur_sum;
				res = max(res, cur_sum);
				--cl; ++cr; --cb; ++ct;
			}
		}
		
	printf("%d\n", res);

	return 0;
}