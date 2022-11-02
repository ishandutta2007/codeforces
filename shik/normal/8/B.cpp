// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 400
using namespace std;
int vis[N][N];
int main()
{
	int x=200,y=200,flg=0,cnt=0;
	char op;
	while ( ~scanf(" %c",&op) ) {
		vis[x][y]=++cnt;
		if ( op=='L' ) x--;
		else if ( op=='R' ) x++;
		else if ( op=='U' ) y--;
		else if ( op=='D' ) y++;
		else puts("QQ");
		if ( vis[x][y] && vis[x][y]!=cnt ) flg=1;
		if ( vis[x-1][y] && vis[x-1][y]!=cnt ) flg=1;
		if ( vis[x+1][y] && vis[x+1][y]!=cnt ) flg=1;
		if ( vis[x][y-1] && vis[x][y-1]!=cnt ) flg=1;
		if ( vis[x][y+1] && vis[x][y+1]!=cnt ) flg=1;
	}
	if ( flg ) puts("BUG");
	else puts("OK");
	return 0;
}