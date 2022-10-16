#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int t,n,x,pos,l,r,cnt_s,cnt_b,c[1001][1001];
int calc(int x,int y)
{
	int ans=1;
	for(int i=0;i<y;i++)
		ans=ans*(x-i)%mod;
	return ans;
}
void init()
{
	c[0][0]=1;
	for(int i=1;i<=1000;i++)
		c[i][i]=c[i][0]=1;
	for(int i=1;i<=1000;i++)
		for(int l=1;l<=1000;l++)
			c[i][l]=(c[i-1][l]+c[i-1][l-1])%mod;
}
void solve()
{
	scanf("%lld %lld %lld",&n,&x,&pos);
	l=0;
	r=n;
	cnt_s=cnt_b=0;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(pos+1<=mid)
		{
			if(pos!=mid)
				cnt_b++;
			r=mid;
		}
		else
		{
			if(pos!=mid)	
				cnt_s++;
			l=mid+1;
		}
	}
	int ans=1;
	ans=ans*calc(n-x,cnt_b)%mod*calc(x-1,cnt_s)%mod;
	ans=ans*calc(n-x-cnt_b,n-x-cnt_b)%mod*calc(x-1-cnt_s,x-1-cnt_s)%mod;
	ans=ans*c[n-cnt_b-cnt_s-1][n-x-cnt_b]%mod;
	cout<<ans%mod; 
}
signed main()
{
	init();
	solve();
	return 0;
}