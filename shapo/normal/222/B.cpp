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

#define maxn 1005

using namespace std;

int cur_c[maxn], cur_r[maxn];
int pp[maxn][maxn];
int n, m, k;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &pp[i][j]);
	for(int i = 1; i <= n; ++i)
		cur_c[i] = i;
	for(int i = 1; i <= m; ++i)
		cur_r[i] = i;
	for(int i = 1; i <= k; ++i){
		char c;
		int a, b;
		scanf(" %c%d%d", &c, &a, &b);
		if(c == 'c')swap(cur_r[a], cur_r[b]);
		if(c == 'r')swap(cur_c[a], cur_c[b]);
		if(c == 'g')printf("%d\n", pp[cur_c[a]][cur_r[b]]);
	}

	return 0;
}