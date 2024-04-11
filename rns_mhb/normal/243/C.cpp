#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;

vector <LL> X, Y;

#define inf 10000000001LL
#define M 1010
int n, l[M]; char d[M];
int flag[3*M][3*M];

void doit(LL xx, LL yy, LL x, LL y){
	int x0 = lower_bound(X.begin(), X.end(), xx) - X.begin();
	int y0 = lower_bound(Y.begin(), Y.end(), yy) - Y.begin();
	int x1 = lower_bound(X.begin(), X.end(), x) - X.begin();
	int y1 = lower_bound(Y.begin(), Y.end(), y) - Y.begin();
	if(x0 > x1) swap(x0, x1);
	if(y0 > y1) swap(y0, y1);
	for(int i = x0; i <= x1; i++) for(int j = y0; j <= y1; j++) flag[i][j] = 1;
	return;
}

void dfs(int x, int y){
	if(x < 0 || x >= X.size() || y < 0 || y >= Y.size() || flag[x][y]) return;
	flag[x][y] = 2;
    dfs(x + 1, y); dfs(x - 1, y); dfs(x, y + 1); dfs(x, y - 1);
    return;
}

int main(){

	int i, j;

	scanf("%d", &n);
	LL x = inf / 2, y = inf / 2;
	X.push_back(0);  Y.push_back(0);
	X.push_back(inf); Y.push_back(inf);
	for(i = 0; i <= n; i++){
		X.push_back(x); X.push_back(x + 1);
		Y.push_back(y); Y.push_back(y + 1);
		if(i == n) break;
		scanf(" %c %d", &d[i], &l[i]);
		if(d[i] == 'R') x += l[i]; if(d[i] == 'L') x -= l[i];
		if(d[i] == 'U') y -= l[i]; if(d[i] == 'D') y += l[i];
	}
	sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
	X.resize(unique(X.begin(), X.end()) - X.begin());
	Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
    x = inf / 2; y = inf / 2;

    LL xx, yy;
    for(i = 0; i < n; i++){
    	xx = x; yy = y;
    	if(d[i] == 'R') x += l[i]; if(d[i] == 'L') x -= l[i];
		if(d[i] == 'U') y -= l[i]; if(d[i] == 'D') y += l[i];
    	doit(xx, yy, x, y);
    }

    dfs(0, 0);

    LL ans = 0;
    for(i = 0; i < X.size() - 1; i++) for(j = 0; j < Y.size() - 1; j++) if(flag[i][j] != 2){
		ans += (X[i+1] - X[i]) * (Y[j+1] - Y[j]);
    }
    printf("%I64d\n", ans);
    return 0;
}