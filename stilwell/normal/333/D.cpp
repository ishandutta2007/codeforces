#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,l,ans,Max,Max_,tmp;
int a[1005][1005],b[1005],tot;

char ch;
void read(int &x)
{
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for(x=0;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	read(a[i][j]);
	ans=-1;
	for(i=1;i<=n;++i)
	{
		tot=0;
		for(j=1;j<=m;++j)if(a[i][j]>ans)b[++tot]=j;
		for(j=i+1;j<=n;++j)
		{
			Max=Max_=-1;
			for(k=1;k<=tot;++k)
			{
				l=b[k];
				if(a[i][l]<a[j][l])tmp=a[i][l];
				else tmp=a[j][l];
				if(tmp>Max)Max_=Max,Max=tmp;
				else if(tmp>Max_)Max_=tmp;
			}
			if(Max_>ans)ans=Max_;
		}
	}
	printf("%d\n",ans);
}