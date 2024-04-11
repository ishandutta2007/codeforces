#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
using namespace std;
int rd()
{
	int rx=0,fx=1;char c=getchar();
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
const int N=1e5+50,inf=1e9+50;
int n,m,num,top,st,pos,now,ans=0;
int a[N],b[N],p[N],f[N],g[N],pre[N],stk[N],dp[N];
int main()
{
	int i,j,sl,sr,mid,top,pd,x;
	n=rd();
	for(i=1;i<=n;i++) a[i]=rd();
	m=rd();
	for(i=1;i<=m;i++) p[i]=b[i]=rd();
	sort(p+1,p+m+1);
	num=unique(p+1,p+m+1)-p-1;
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(i=1;i<=n;i++)
	{
		
		if(a[i]==-1)
		{
			top=i-1;
			for(j=num;j>=1;j--)
			{
				while(f[top]>=p[j]) top--;
				f[top+1]=p[j];g[top+1]=i;
				cmax(dp[i],top+1);
			}
			
		}
		else
		{
			sl=0;sr=n;
			while(sl<sr)
			{
				mid=(sl+sr+1)>>1;
				if(f[mid]<a[i]) sl=mid;
				else sr=mid-1;
			}
			f[sl+1]=a[i];g[sl+1]=i;pre[i]=g[sl];
			cmax(dp[i],sl+1);
		}
		/*
		for(j=0;j<=i;j++)
		{
			printf("#%d %d  %d %d\n",i,j,f[j],g[j]);
		}
		*/
	}
	sort(b+1,b+m+1);
	top=m;st=0;
	for(i=1;i<=n;i++)
	{
		//printf("#%d %d\n",i,dp[i]);
		if(dp[i]>ans) 
		{
			st=i;ans=dp[i];
		}
	}
	x=st;
	pos=m;
	now=inf;
	top=0;
	//if(dp[st]==25) puts("OK");
	while(x>0)
	{
		//printf("now%d %d\n",x,ans);
		if(a[x]==-1)
		{
			while(b[pos]>=now) 
			{
				stk[++top]=b[pos];
				pos--;
			}
			a[x]=b[pos];now=a[x];pos--;
			//printf("U%d %d %d %d\n",x,a[x],pos,b[pos]);
			//exit(0);
			pd=0;
			for(j=0;j<x;j++)
			{
				if(a[j]!=-1&&a[j]<a[x]&&dp[j]+1==ans)
				{
					pd=1;x=j;break;
				}
			}
			if(pd==0)
			{
				while(a[x]!=-1) x--;
			}
		}
		else 
		{
			now=a[x];x=pre[x];
		}
		ans--;
	}
	while(pos>0) stk[++top]=b[pos--];
	for(i=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			a[i]=stk[top--];
		}
	}
	for(i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}