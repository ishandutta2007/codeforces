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

#define maxn 200100
#define maxc 26

char a[maxn], b[maxn];
int minid[maxn];
int na, nb, cmin = 0;
int prev[maxn][maxc];

int main(){
	scanf("%s %s", a, b);
	na = strlen(a);
	nb = strlen(b);
	for(int j = 0; j < maxc; ++j)
		if(int(b[0] - 'a') == j)
			prev[0][j] = 0;
		else
			prev[0][j] = -1;
	for(int i = 1; i < nb; ++i)
		for(int j = 0; j < maxc; ++j)
			if(int(b[i] - 'a') == j)
				prev[i][j] = i;
			else
				prev[i][j] = prev[i - 1][j];
	for(int i = 0; i < maxc; ++i)
		prev[nb][i] = prev[nb - 1][i];
	for(int i = 0; i < na; ++i){
		minid[i] = prev[cmin][int(a[i] - 'a')];
		cmin = max(cmin, minid[i] + 1);
		if(minid[i] == -1){
			printf("No\n");
			return 0;
		}
		//printf("minid[%d] = %d, cmin = %d\n", i, minid[i], cmin);
	}
	for(int i = 0; i < maxc; ++i)
		if(int(b[nb - 1] - 'a') == i)
			prev[nb][i] = nb - 1;
		else
			prev[nb][i] = -1;
	for(int i = nb - 2; i >= 0; --i)
		for(int j = 0; j < maxc; ++j)
			if(int(b[i] - 'a') == j)
				prev[i + 1][j] = i;
			else
				prev[i + 1][j] = prev[i + 2][j];
	for(int i = 0; i < maxc; ++i)
		prev[0][i] = prev[1][i];
	cmin = 0;
	for(int i = na - 1; i >= 0; --i){
		int kk = prev[nb - cmin][int(a[i] - 'a')];
		if(kk == -1){
			printf("No\n");
			return 0;
		}
		if(minid[i] + cmin < nb - 1){
			printf("No\n");
			return 0;
		}
		cmin = max(cmin, nb - kk);
		//printf("minid + cmin = %d, cmin = %d\n", minid[i] + cmin, cmin);
	}
	printf("Yes\n");
	return 0;
}