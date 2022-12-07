#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2050;
ll n,m,top,tot,ans;
ll stk[N];
ll w[N][N],val[N][N];
char rs[N][N];
int main()
{
//	freopen("t.in","r",stdin);
	ll i,j,len;
	scanf("%I64d%I64d",&n,&m);
	for(i=1;i<=n;i++) 
	{
		scanf("%s",rs[i]+1);
		for(j=1;j<=m;j++) w[i][j]=rs[i][j]-'a';
	}
	for(j=1;j<=m;j++)
	{
		top=0;
		for(i=1;i<=n;i++)
		{
			if(i==1||w[i][j]!=w[i-1][j]) stk[++top]=i;
		}
		stk[++top]=n+1;
		for(i=1;i<=top-3;i++)
		{
			len=stk[i+2]-stk[i+1];
			if(stk[i+1]-stk[i]>=len&&stk[i+3]-stk[i+2]>=len)
			{
				val[stk[i+1]-len][j]=((w[stk[i+1]-len][j]+(w[stk[i+1]][j]*100ll)+(w[stk[i+1]+len][j]*10000ll))<<15)^len;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		tot=0;
		for(j=1;j<=m+1;j++)
		{
			if(val[i][j]!=val[i][j-1])
			{
				ans+=tot*(tot+1)/2ll;
				tot=0;
			}
			if(val[i][j]>0) tot++;
		}
	}
	printf("%I64d",ans);
	return 0;
}