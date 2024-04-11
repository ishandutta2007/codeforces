#include<bits/stdc++.h>
#define cmin(a,b) a=min(a,b)
using namespace std;
const int N=1e5+50,P=17,V=(1<<17)+10;
int n,p,sx;
int a[N],h[P][P],tag[V],len[P],dp[V],f[P][P][V];
char s[N];
void ins(int a,int b,int w)
{
	if(a>b) swap(a,b);
	f[a][b][w]=1;
	//printf("ins%d %d %d\n",a,b,w);
}
int main()
{
	int i,j,k,u,pos,w,ns,vs,val,mid;
	scanf("%d%d",&n,&p);
	sx=(1<<p);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) a[i]=s[i]-'a';
	for(i=0;i<p;i++)
	{
		for(j=0;j<p;j++)
		{
			scanf("%d",&h[i][j]);
		}
	}
	for(i=0;i<p;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[j]!=i) continue;
			len[i]++;
			w=sx-1;
			for(pos=j-1;pos>=1;pos--)
			{
				//printf("now%d %d\n",j,pos);
				if(h[a[pos]][i]==0) ins(a[pos],i,w);
				if(a[pos]==i) break;
				if(w&(1<<a[pos])) w^=(1<<a[pos]);
			}
			w=sx-1;
			for(pos=j+1;pos<=n;pos++)
			{
				//printf("now%d %d\n",j,pos);
				if(h[a[pos]][i]==0) ins(a[pos],i,w);
				if(a[pos]==i) break;
				if(w&(1<<a[pos])) w^=(1<<a[pos]);
			}
		}
	}
	for(i=0;i<p;i++)
	{
		for(j=i;j<p;j++)
		{
			for(int len=2;len<=sx;len<<=1)
			{
				mid=(len>>1);
				for(u=0;u<sx;u+=len)
				{
					for(k=0;k<mid;k++) f[i][j][u+k]|=f[i][j][u+k+mid];
				}
			}
			for(ns=0;ns<sx;ns++)
			{
				if(f[i][j][ns]==0) continue;
				vs=ns;vs|=(1<<i);vs|=(1<<j);
				tag[vs]=1;
				//printf("vs%d\n",vs);
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(ns=0;ns<sx;ns++)
	{
		if(tag[ns]) continue;
		val=0;
		for(i=0;i<p;i++) 
		{
			if(ns&(1<<i)) 
			{
				cmin(dp[ns],dp[ns^(1<<i)]);
				val+=len[i];
			}
		}
		cmin(dp[ns],val);
	}
	printf("%d",dp[sx-1]);
	return 0;
}