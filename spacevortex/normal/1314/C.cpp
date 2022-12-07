#include<bits/stdc++.h>
#define cmin(a,b) a=min(a,b)
using namespace std;
typedef long long ll;
const ll N=1050,inf=(ll)1e18+100;
ll n,m,K,tot=0;
ll lcp[N][N],dp[N][N];
char s[N];
struct Node{ll l,r;}h[N*N];
bool cmp(const Node &a,const Node &b)
{
	ll alt,blt,len;
	alt=a.r-a.l+1;blt=b.r-b.l+1;
	len=min(lcp[a.l][b.l],min(alt,blt));
	if(len==min(alt,blt)) return alt>blt;
	else return s[a.l+len]>s[b.l+len];
}
ll solve(ll L,ll R)
{
	ll i,j,len;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			len=min(lcp[j+1][L],R-L+1);
			if(len==R-L+1) dp[i+1][j+len]+=dp[i][j],cmin(dp[i+1][j+len],inf);
			else 
			{
				if(s[j+1+len]>s[L+len]) dp[i+1][j+1+len]+=dp[i][j],cmin(dp[i+1][j+1+len],inf);
			}
		}
		for(j=1;j<=n;j++)
		{
			dp[i+1][j]+=dp[i+1][j-1];cmin(dp[i+1][j],inf);
		}
	}
	return dp[m][n];
}
int main()
{
	ll i,j,sl,sr,mid;
	scanf("%lld%lld%lld",&n,&m,&K);
	scanf("%s",s+1);
	for(i=n;i>=1;i--)
	{
		for(j=n;j>=1;j--)
		{
			if(s[i]!=s[j]) continue;
			lcp[i][j]=lcp[i+1][j+1]+1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			h[++tot]=(Node){i,j};
		}
	}
	sort(h+1,h+tot+1,cmp);
	//printf("U%lld %lld\n",h[1].l,h[1].r);
	
	sl=1;sr=tot;
	while(sl<sr)
	{
		mid=(sl+sr)>>1;
		if(solve(h[mid].l,h[mid].r)>=K) sr=mid;
		else sl=mid+1;
	}
	//printf("P%lld\n",solve(h[sl].l,h[sl].r));
	for(i=h[sl].l;i<=h[sl].r;i++) putchar(s[i]);
	return 0;
}