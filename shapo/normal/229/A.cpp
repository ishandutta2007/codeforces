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

#define maxn 105
#define maxm 10500

using namespace std;

char a[maxn][maxm];
int dist[maxn][maxm];
int n, m;
int ans;
bool ok = true;

bool ok_row(int x){
	for(int i = 1; i <= m; ++i)
		if(a[x][i] != '0')return true;
	return false;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf(" %c", &a[i][j]);
			dist[i][j] = 2 * maxn * maxm;
		}
		if(!ok_row(i)){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 1; i <= n; ++i){
		int ll (0), rr(m + 1);
		for(int j = m; j > 0; --j)
		    if(a[i][j] == '1'){
		        ll = j - m;
		        break;
		    }
        for(int j = 1; j <= m; ++j)
            if(a[i][j] == '1'){
                rr = j + m;
                break;
            }
		for(int j = 1; j <= m; ++j){
			if(a[i][j] != '0')ll = j;
            dist[i][j] = min(dist[i][j], j - ll);
		}
		for(int j = m; j >= 1; --j){
			if(a[i][j] != '0')rr = j;
            dist[i][j] = min(dist[i][j], rr - j);
		}
	}
	int ans = 2 * maxn * maxm;
	for(int jj = 1; jj <= m; ++jj){
		int cur = 0;
		for(int i = 1; i <= n; ++i){
			cur += dist[i][jj];
			//printf("cur = %d\n", cur);
		}
		ans = min(cur, ans);
	}
	printf("%d\n", ans);
	return 0;
}