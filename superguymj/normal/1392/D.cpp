#include<algorithm>
#include<string>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
int T,n,p[N],f[N],ans;
char s[N];

int solve()
{
	rep(i,1,n)
	{
		f[i]=n;
		if(i>=2) f[i]=min(f[i],f[i-2]+(p[i-1]^1)+(p[i]^0));
		if(i>=3)
		{
			f[i]=min(f[i],f[i-3]+(p[i-2]^1)+(p[i-1]^1)+(p[i]^0));
			f[i]=min(f[i],f[i-3]+(p[i-2]^1)+(p[i-1]^0)+(p[i]^0));
		}
		if(i>=4) f[i]=min(f[i],f[i-4]+(p[i-3]^1)+(p[i-2]^1)+(p[i-1]^0)+(p[i]^0));
	}
	return f[n];
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		rep(i,1,n) p[i]=s[i]=='R';
		ans=n;
		rep(i,0,4)
		{
			int x=p[1];
			rep(i,1,n-1) p[i]=p[i+1];
			p[n]=x;
			ans=min(ans,solve());
		}
		printf("%d\n",ans);
	}
	return 0;
}