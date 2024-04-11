#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=100005,INF=100000000;
int n,m,sum[N],c[2][N],C[N],f[N],g[N],stk[N],top,ans,id;
char s[N];

bool cmp(int x,int y)
{
	if(f[x]<f[y]) return 1;
	if(f[x]==f[y] && g[x]>g[y]) return 1;
	return 0;
}

int main()
{
	scanf("%d%s%d",&n,s+1,&m);
	if(n<m) return puts("0"),0;
	rep(i,1,n) sum[i]=sum[i-1]+(s[i]=='?');
	if(m==1) return printf("%d\n",sum[n]),0;
	repd(i,n,1)
	{
		if(s[i]=='?') c[0][i]=c[1][i+1]+1,c[1][i]=c[0][i+1]+1;
		else if(s[i]=='a') c[0][i]=c[1][i+1]+1;
		else c[1][i]=c[0][i+1]+1;
	}
	rep(i,1,n-m+1)
	{
		if(c[0][i]<m) C[i]=INF;
		else C[i]=sum[i+m-1]-sum[i-1];
	}
	top=1;
	rep(i,1,n-m+1)
	{
		if(i-m>0 && C[i-m]<INF)
		{
			while(top && cmp(stk[top],i-m)) --top;
			stk[++top]=i-m;
		}
		f[i]=f[stk[1]]+1;
		g[i]=g[stk[1]]+C[i];
		if(C[i]<INF)
		{
			if(f[i]>ans) ans=f[i],id=g[i];
			else if(f[i]==ans && g[i]<id) id=g[i];
		}
	}
	printf("%d\n",id);
	return 0;
}