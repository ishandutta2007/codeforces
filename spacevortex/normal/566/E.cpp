#include<bits/stdc++.h>
#define bt bitset<N>
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
const int N=1024;
int n,K,m=0;
bt h[N],t[N];
int ex[N],ey[N],col[N],bel[N],pl[N],dy[N],vmi[N];
int main()
{
	int i,j,k,x,u,v,id,fct,cnt;
	bt f;
	n=rd();
	if(n==2)
	{
		puts("1 2");return 0;
	}
	for(i=1;i<=n;i++)
	{
		K=rd();
		for(j=1;j<=K;j++)
		{
			x=rd();h[i][x]=1;
		}
	}
	for(i=1;i<=n;i++) t[i][i]=1;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			f=h[i]&h[j];
			fct=f.count();
			if(fct==2)
			{
				u=v=-1;
				for(k=1;k<=n;k++)
				{
					if(f[k]==0) continue;
					if(u==-1) u=k;
					else v=k;
				}
				if(t[u][v]) continue;
				m++;ex[m]=u;ey[m]=v;
				//printf("E%d %d\n",u,v);
				t[u][v]=t[v][u]=1;
				col[u]=col[v]=1;
			}
		}
	}
	if(m==0)
	{
		for(i=2;i<=n;i++) printf("1 %d\n",i);
		return 0;
	}
	if(m==1)
	{
		for(i=1;i<=n;i++)
		{
			if((int)h[i].count()<n)
			{
				id=i;break;
			} 
		}
		for(i=1;i<=n;i++)
		{
			if(col[i]) continue;
			if(h[id][i]==1) m++,ex[m]=i,ey[m]=ex[1];
			else m++,ex[m]=i,ey[m]=ey[1];
		}
		for(i=1;i<n;i++) printf("%d %d\n",ex[i],ey[i]);
		return 0;
	}
	memset(vmi,0x3f,sizeof(vmi));
	for(i=1;i<=n;i++)
	{
		cnt=h[i].count();
		for(j=1;j<=n;j++)
		{
			if(h[i][j]&&cnt<vmi[j]&&col[j]==0) vmi[j]=cnt,dy[j]=i;
		}
	}
	for(i=1;i<=n;i++) 
	{
		if(dy[i])
		{		
			id=dy[i];
			for(j=1;j<=n;j++)
			{
				if(col[j]==0) h[id][j]=0;
			}
			for(j=1;j<=n;j++)
			{
				if(h[id]==t[j])
				{
					m++;ex[m]=i;ey[m]=j;break;
				}
			}
		}
	}
	for(i=1;i<n;i++) printf("%d %d\n",ex[i],ey[i]);
	return 0;
}