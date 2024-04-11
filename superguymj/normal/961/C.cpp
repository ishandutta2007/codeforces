#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
bool vis[5];
char s[5][300][300];
int t[300][300],a[5];
int n,ans;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int query0()
{
	int rt=0;
	rep(i,1,n) rep(j,1,n) t[i][j]=s[a[1]][i][j]-'0';
	rep(i,1,n) rep(j,1,n) t[i][j+n]=s[a[2]][i][j]-'0';
	rep(i,1,n) rep(j,1,n) t[i+n][j]=s[a[3]][i][j]-'0';
	rep(i,1,n) rep(j,1,n) t[i+n][j+n]=s[a[4]][i][j]-'0';
	rep(i,1,2*n) rep(j,1,2*n) rt+=(t[i][j]==((i&1)^(j&1)));
	return rt;
}

int query1()
{
	int rt=0;
	rep(i,1,n) rep(j,1,n) t[i][j]=s[a[1]][i][j]-'0';
	rep(i,1,n) rep(j,1,n) t[i][j+n]=s[a[2]][i][j]-'0';
	rep(i,1,n) rep(j,1,n) t[i+n][j]=s[a[3]][i][j]-'0';
	rep(i,1,n) rep(j,1,n) t[i+n][j+n]=s[a[4]][i][j]-'0';
	rep(i,1,2*n) rep(j,1,2*n) rt+=(t[i][j]!=((i&1)^(j&1)));
	return rt;
}

void dfs(int x)
{
	if(x>4)
	{
		ans=min(ans,min(query0(),query1()));
		return;
	}
	rep(i,1,4)
		if(!vis[i])
			a[x]=i,vis[i]=1,dfs(x+1),vis[i]=0;
} 

int main()
{
	n=getint();
	rep(i,1,4)
		rep(j,1,n)
			scanf("%s",s[i][j]+1);
	ans=4*n*n;
	dfs(1);
	printf("%d\n",ans);
}