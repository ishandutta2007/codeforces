#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,K,i,j,k,ans;
int x[2005],y[2005],Ans[2005];
int f1[2005][2005],f2[2005][2005];
int st[2005],l[2005],top,Min;
int Maxl[2005],Maxr[2005],Max[2005];
char s[2005][2005];

int get(int *fa,int x){return fa[x]==x?x:fa[x]=get(fa,fa[x]);}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=K;++i)scanf("%d%d",&x[i],&y[i]),s[x[i]][y[i]]='X';
	for(i=1;i<=n;++i)
	{
		f1[i][0]=0;f1[i][m+1]=m+1;
		f2[i][0]=0;f2[i][m+1]=m+1;
		for(j=1;j<=m;++j)
		if(s[i][j]=='X')f1[i][j]=f2[i][j]=j;
		else f1[i][j]=j-1,f2[i][j]=j+1;
	}
	for(j=1;j<=m;++j)
	{
		top=0;
		for(i=1;i<=n;++i)
		{
			k=j-get(f1[i],j);Min=i;
			while(top&&st[top]>=k)
			{
				Min=l[top];
				ans=max(ans,min(st[top],i-l[top]));
				--top;
			}
			st[++top]=k;l[top]=Min;
		}
		while(top)
		{
			ans=max(ans,min(st[top],n-l[top]+1));
			--top;
		}
	}
	for(i=K;i;--i)
	{
		Ans[i]=ans;
		f1[x[i]][y[i]]=y[i]-1;
		f2[x[i]][y[i]]=y[i]+1;
		for(j=1;j<=n;++j)
		{
			Maxl[j]=get(f1[j],y[i]);
			Maxr[j]=get(f2[j],y[i]);
		}
		for(j=x[i];j;--j)
		{
			if(Maxl[j]>Maxl[j-1])Maxl[j-1]=Maxl[j];
			if(Maxr[j]<Maxr[j-1])Maxr[j-1]=Maxr[j];
		}
		for(j=x[i];j<=n;++j)
		{
			if(Maxl[j]>Maxl[j+1])Maxl[j+1]=Maxl[j];
			if(Maxr[j]<Maxr[j+1])Maxr[j+1]=Maxr[j];
		}
		for(j=1;j<=n;++j)Max[j]=Maxr[j]-Maxl[j]-1;
		for(;;)
		{
			for(j=x[i];j<=n;++j)
			if(Max[j]>=ans+1&&j>=ans+1)
			if(min(Maxr[j],Maxr[j-ans])-max(Maxl[j],Maxl[j-ans])-1>=ans+1)
			break;
			if(j<=n)++ans;else break;
		}
	}
	for(i=1;i<=K;++i)printf("%d\n",Ans[i]);
}