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

#define maxn 3000

using namespace std;

int sm[maxn][maxn];
int used[maxn], res[maxn];
int q[maxn];
int m, n, beg = 1, en = 0;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			char cur_c;
			scanf(" %c", &cur_c);
			if(cur_c == '#')sm[i][j + n] = 1;
		}
	
	en = 1;
	q[en] = n;
	used[n] = 1; res[n] = 0;
	while(beg <= en){
		int tmp = q[beg];
		for(int i = 1; i <= m + n; ++i)
			if((sm[tmp][i] || sm[i][tmp]) && !used[i]){
				++en;
				q[en] = i;
				used[i] = 1;
				res[i] = res[tmp] + 1;
			}
		++beg;
	}
	
	if(!used[1])printf("-1\n");else printf("%d\n", res[1]);

	return 0;
}