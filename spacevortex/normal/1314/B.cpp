#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=1e6+50;
ll num,K,las,ans,bvl=0;
ll tag[N],dp[N][2][2];
int main()
{
	ll i,j,x,a,b,ai,aj,bi,bj,ni,nj,der,pos;
	num=rd();K=rd();
	memset(dp,-0x3f,sizeof(dp));
	for(i=1;i<=K;i++)
	{
		x=rd();
		tag[x]=1;
		dp[x][1][0]=dp[x][0][1]=0;
	}
	for(i=1;i<=(1<<num);i+=2) if(tag[i]||tag[i+1]) bvl++;
	for(i=1;i<=(1<<num);i++) dp[i][0][0]=0;
	las=1<<num;
	for(i=num-1;i>=0;i--)
	{
		x=las;
		pos=las-(1<<(i+1));
		for(j=1;j<=(1<<i);j++)
		{
			x++;
			a=pos+1;b=pos+2;pos+=2;
			//printf("x %lld  %lld %lld\n",x,a,b);
			for(ai=0;ai<2;ai++)
			for(aj=0;aj<2;aj++)
			for(bi=0;bi<2;bi++)
			for(bj=0;bj<2;bj++)
			{
				ni=ai|bi;nj=aj|bj;
				der=0;
				if(i!=num-1)
				{
					if(ni) der++;
					if(nj) 
					{
						 der+=2;
					}
				}
				dp[x][ni][nj]=max(dp[x][ni][nj],dp[a][ai][aj]+dp[b][bi][bj]+der);
				//printf("S%lld %lld %lld  %lld\n",x,ni,nj,dp[x][ni][nj]);
			}
		}
		las=x;
	}
	for(ni=0;ni<2;ni++)
	for(nj=0;nj<2;nj++)
	{
		ans=max(ans,dp[x][ni][nj]);
	}
	if(K>0) ans++;
	ans+=bvl;
	printf("%lld\n",ans);
	return 0;
}