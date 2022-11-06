//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

int ans;
char mp[10][10];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
bool chkX(int x) {
	rep(i, 1, 8) if(mp[x][i] == 'W') return 0;
	return 1;
}
bool chkY(int y) {
	rep(i, 1, 8) if(mp[i][y] == 'W') return 0;
	return 1;
}

int main() {
	rep(i, 1, 8) scanf("%s", mp[i]+1);
	rep(i, 1, 8) ans += chkX(i);
	rep(i, 1, 8) ans += chkY(i);
	if(ans == 16) ans = 8;
	printf("%d\n", ans);
	return 0;
}