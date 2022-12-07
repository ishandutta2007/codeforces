#include<bits/stdc++.h>
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
const int N=1e6+50;
int n,m,top;
int a[N],f[N],vis[N],stk[N],ans[N];
int main()
{
	int T,i,x;
	T=rd();
	while(T--)
	{
		n=rd();m=0;top=0;
		memset(vis,0,sizeof(int)*(n+3));
		for(i=1;i<=n;i++)
		{
			a[i]=rd();f[i]=i-a[i];
		}
		for(x=1;;x=f[x])
		{
			vis[x]=1;
			stk[++top]=x;
			if(vis[f[x]])
			{
				while(stk[top]!=f[x]) 
				{
					ans[++m]=stk[top--];
				}
				ans[++m]=f[x];
				break;
			}
		}
		printf("%d\n",m);
		for(i=1;i<=m;i++) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}