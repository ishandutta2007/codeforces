#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
 
using namespace std;
int n,mp[100][100],p[100];
char s[100];
 
void solve()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int cnt=0;
	rep(i,1,n) if(s[i]=='2') p[++cnt]=i;
	if(cnt==1 || cnt==2) puts("NO");
	else
	{
		puts("YES");
		rep(i,1,n) rep(j,1,n) mp[i][j]=0;
		rep(i,1,cnt-1) mp[p[i]][p[i+1]]=1,mp[p[i+1]][p[i]]=-1;
		mp[p[cnt]][p[1]]=1,mp[p[1]][p[cnt]]=-1;
		rep(i,1,n)
		{
			rep(j,1,n)
			{
				if(i==j) putchar('X');
				else if(mp[i][j]==0) putchar('=');
				else putchar(mp[i][j]==1?'+':'-');
			}
			puts("");
		}
	}
}
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}