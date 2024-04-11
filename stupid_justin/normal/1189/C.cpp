#include <bits/stdc++.h>
#define N 100005
#define inf 0x3f3f3f3f
#define MOD 1e9+7
using namespace std;
int n,q,l,r;
int a[200005],dp[18][200005],a1[18][200005];
void init()
{
	for (int i=1;i<=17;i++)
	{
		if (i==1)
			for (int j=1;j<=n-1;j++)
			{
				if (a[j]+a[j+1]>=10)dp[i][j]=1;
				a1[i][j]=(a[j+1]+a[j])%10;
			}
		else
		{
			for (int j=1;j<=n+1-(1<<i);j++)//l2^i l+2^n-1<=n
			{
				dp[i][j]=dp[i-1][j]+dp[i-1][j+(1<<(i-1))];
				if (a1[i-1][j]+a1[i-1][j+(1<<(i-1))]>=10) dp[i][j]+=1;
				a1[i][j]=(a1[i-1][j]+a1[i-1][j+(1<<(i-1))])%10;
			}
		}	
	}
}
int main() {
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	init();
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		int k=r-l+1;
		int s=0;
		while(k!=1)
		{
			k/=2;
			s++;
		}
//		cout<<s<<endl;
		cout<<dp[s][l]<<endl;
	}
}