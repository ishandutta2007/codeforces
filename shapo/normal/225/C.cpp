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

using namespace std;

#define maxn 1027
#define bold 2

//int sm[maxn][maxn];
int paint[maxn][bold];
int n, m, x, y;
int ans[maxn][maxn][bold];

int main(){
	scanf("%d%d%d%d", &n, &m, &x, &y);
	memset(paint, 0, sizeof(paint));
	char c;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			scanf(" %c", &c);
			if(c == '.')
				++paint[j][1];
			else
				++paint[j][0];
		}
	y = min(y, m);
	for(int i = 1; i <= m; ++i)
		ans[0][i][0] = ans[0][i][1] = maxn * maxn * bold * bold;
	ans[0][y][0] = ans[0][y][1] = 0;
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= y; ++j)
			for(int k = 0; k < 2; ++k){
				ans[i][j][k] = ans[i - 1][j - 1][k] + paint[i][k];
				//printf("ans[%d][%d][%d] = %d\n", i, j, k, ans[i][j][k]);
			}
		ans[i][1][0] = ans[i][1][1] = maxn * maxn * bold * bold;
		for(int j = x; j <= y; ++j)
			for(int k = 0; k < 2; ++k)
				ans[i][1][k] = min(ans[i][1][k], ans[i - 1][j][1 - k] + paint[i][k]);
		//printf("ans[%d][1] : %d %d\n", i, ans[i][1][0], ans[i][1][1]);
	}
	int res = maxn * maxn * bold * bold;
	for(int i = x; i <= y; ++i)
		res = min(res, min(ans[m][i][0], ans[m][i][1]));
	printf("%d\n", res);
	return 0;
}