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
const int N=1e4+10,M=1010,U=N*M*4,inf=(int)2e9+1e7,B=1e7;
int W,n,m,G,R,ans,r,l;
int i;
int dp[N],h[N],tag[N],f[M][N],p[U];
int qry(int t,int x){return t*(n+1)+x;}
int main()
{
	int i,t,x,w,d;
	W=rd();n=rd();
	for(i=1;i<=n;i++) h[i]=rd();
	
	sort(h+1,h+n+1);
	G=rd();R=rd();
	l=N*M*2+1;r=N*M*2;
	
	memset(f,0x3f,sizeof(f));
	f[0][1]=0;
	p[++r]=1;
	while(l<=r)
	{
		w=p[l];l++;
		
		t=w/(n+1);x=w-t*(n+1);
		//printf("U%d %d\n",t,x);
		if(x>1&&t+h[x]-h[x-1]<=G)
		{
			d=t+h[x]-h[x-1];
			if(f[d][x-1]>f[t][x])
			{
				f[d][x-1]=f[t][x];
				p[--l]=qry(d,x-1);
			}
		}
		if(x<n&&t+h[x+1]-h[x]<=G)
		{
			d=t+h[x+1]-h[x];
			if(f[d][x+1]>f[t][x])
			{
				f[d][x+1]=f[t][x];
				p[--l]=qry(d,x+1);
			}
		}
		if(t==G)
		{
			if(f[t][x]+1<f[0][x])
			{
				f[0][x]=f[t][x]+1;
				p[++r]=qry(0,x);
			}
		}
	}
	ans=inf;
	for(i=n;i>=1;i--)
	{
		//printf("#%d %d\n",i,f[0][i]);
		if(h[n]-h[i]<=G&&f[0][i]<=B) ans=min(ans,f[0][i]*(G+R)+h[n]-h[i]);
	}
	if(ans==inf) puts("-1");
	else printf("%d\n",ans);
	return 0;
}