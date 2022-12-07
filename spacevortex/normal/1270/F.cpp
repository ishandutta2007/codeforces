#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+50,S=260,B=N/S,D=N*S,V=N*(S+10);
int n,top;
ll ans=0;
char s[N];
int a[N],sum[N],stk[N];
int vis[V],val[V];
int main()
{
	int i,j,l,r,pl,pr,w;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='1') a[i]=1;
		sum[i]=sum[i-1]+a[i];
	}
	top=1;stk[1]=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==1) stk[++top]=i;
		for(j=top-1;j>=max(top-B-1,1);j--)
		{
			l=i-stk[j+1]+1;r=i-stk[j];
			//printf("U%d %d %d %d\n",i,j,l,r);
			pl=max((l-1)/(top-j)+1,S+1);pr=r/(top-j);
			if(pl<=pr) 
			{
				//printf("S%d %d %d %d\n",i,j,pl,pr);
				ans+=pr-pl+1;
			}
		}
		
	}
	for(i=1;i<=S;i++)
	{
		for(j=0;j<=n;j++)
		{
			w=j-sum[j]*i+D;
			if(vis[w]==i) ans+=val[w],val[w]++;
			else vis[w]=i,val[w]=1;
		}
	}
	cout<<ans;
	return 0;
}