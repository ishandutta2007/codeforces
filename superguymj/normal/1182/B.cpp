#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=505;
int n,m,tot;
char s[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='*') ++tot;
	rep(i,2,n-1) rep(j,2,m-1) if(s[i][j]=='*' && s[i-1][j]==s[i][j] && s[i+1][j]==s[i][j] && s[i][j-1]==s[i][j] && s[i][j+1]==s[i][j])
	{
		int x,y,cnt=1;
		x=i,y=j;
		while(x-1>0 && s[x-1][y]=='*') --x,++cnt;
		x=i,y=j;
		while(x+1<=n && s[x+1][y]=='*') ++x,++cnt;
		x=i,y=j;
		while(y-1>0 && s[x][y-1]=='*') --y,++cnt;
		x=i,y=j;
		while(y+1<=m && s[x][y+1]=='*') ++y,++cnt;
		if(cnt==tot) return puts("YES"),0;
	}
	puts("NO");
	return 0;
}