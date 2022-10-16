//MatrixCascade AFO.
//LGM when?
 
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
// #define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int a[100005];
signed t[20000005];
bool isprime[20000005];
int prime[2000005];
long long dp[20000005];
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
signed main()
{
	isprime[1]=1;int cnt=0;
	up(i,2,20000000)
	{
		if(isprime[i]==0)
		{
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&prime[j]*i<=20000000;j++)
		{
			isprime[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
	// up(i,1,10)opls(prime[i]);
	int T=1;//return 0;
	while(T--)
	{
		// n=read();int ans=0,g=0;
		// up(i,1,n)a[i]=read(),g=max(g,a[i]);
		n=read();long long ans=0;int g=0;
		up(i,1,n)a[i]=read(),g=max(g,a[i]);
		up(i,1,n)
		{
			for(int j=1;j*j<=a[i];j++)
			{
				if(a[i]%j==0)t[j]++;//cout<<j<<' '<<i<<endl;
				if(a[i]%j==0&&j*j!=a[i])t[a[i]/j]++;
			}
		}
		// up(i,1,g)opls(t[i]);puts("");
		// return 0;
		for(int i=g;i>=1;i--)
		{
			dp[i]=1ll*i*t[i];
			for(int j=i+i,k=1;j<=g&&k<=cnt;k++,j=i*prime[k])
				dp[i]=max(dp[i],dp[j]+1ll*i*(t[i]-t[j]));
			ans=max(ans,dp[i]);
			// opls(dp[i]);
		}
		cout<<ans<<endl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/