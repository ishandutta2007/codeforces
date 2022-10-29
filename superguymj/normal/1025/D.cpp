#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=705;
int n,a[N],f[N][N][2];
bool vis[N][N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

bool dfs(int l,int r,int tp)
{
	if(l>r) return 1;
	if(f[l][r][tp]>-1) return f[l][r][tp];
	int x=tp?r+1:l-1;
	rep(i,l,r)
		if(vis[i][x] && dfs(l,i-1,1) && dfs(i+1,r,0))
			return f[l][r][tp]=1;
	return f[l][r][tp]=0;
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) rep(j,1,n) vis[i][j]=gcd(a[i],a[j])>1;
	memset(f,-1,sizeof(f));
	rep(i,1,n) if(dfs(1,i-1,1) && dfs(i+1,n,0)) return puts("Yes"),0;
	return puts("No"),0;
}