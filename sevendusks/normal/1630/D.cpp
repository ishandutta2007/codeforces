/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=1e6+100;
int T,n,m,a[N],b[N],dp[N][2],sa,sb;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void solve(vector <int> &p)
{
	dp[0][0]=p[0];dp[0][1]=-p[0];
	for (int i=1;i<len(p);i++)
	{
		dp[i][0]=max(dp[i-1][0]+p[i],dp[i-1][1]-p[i]);
		dp[i][1]=max(dp[i-1][0]-p[i],dp[i-1][1]+p[i]);
	}
	sa+=dp[len(p)-1][0];sb+=dp[len(p)-1][1];
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int g=0;sa=sb=0;
		for (int i=1;i<=m;i++) b[i]=read(),g=__gcd(g,b[i]);
		for (int i=1;i<=g;i++)
		{
			vector <int> tmp;
			for (int j=i;j<=n;j+=g) tmp.push_back(a[j]);
			solve(tmp);
		}
		printf("%lld\n",max(sa,sb));
	}
}