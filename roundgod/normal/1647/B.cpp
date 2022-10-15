#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];
P goright(int x,int y)
{
	while(y+1<=m&&str[x][y+1]=='1') y++;
	return P(x,y);
}
P godown(int x,int y)
{
	while(x+1<=n&&str[x+1][y]=='1') x++;
	return P(x,y);
}
P goleft(int x,int y)
{
	while(y-1>=1&&str[x][y-1]=='1') y--;
	return P(x,y);
}
P goup(int x,int y)
{
	while(x-1>=1&&str[x-1][y]=='1') x--;
	return P(x,y);
}
bool check(int x,int y)
{
	P r=goright(x,y);
	P d=godown(x,y);
	P l=goleft(x,y);
	P u=goup(x,y);
	return (goright(d.F,d.S)==godown(r.F,r.S))&&(goleft(u.F,u.S)==goup(l.F,l.S));
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
		bool f=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(str[i][j]=='1'&&!check(i,j)) {f=false; break;}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}