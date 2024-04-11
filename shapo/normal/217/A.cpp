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

using namespace std;

struct point{int x, y;};

int go[maxn][maxn];
int n, num;
bool used[maxn];
point sm[maxn];

int ok(const point& p1, const point& p2){
	return(p1.x == p2.x || p1.y == p2.y);
}

int DFS(const int &x){
	used[x] = true;
	for(int i = 1; i <= n; ++i){
		if(go[i][x] && !used[i])
			DFS(i);
	}
	return 0;
}

int main(){
	num = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &sm[i].x, &sm[i].y);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			go[i][j] = ok(sm[i], sm[j]);
	for(int i = 1; i <= n; ++i)
		if(!used[i]){
			++num;
			DFS(i);
		}
	printf("%d\n", num - 1);
	return 0;
}