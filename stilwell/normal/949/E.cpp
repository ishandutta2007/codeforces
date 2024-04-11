#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,ans;
int a[20][100005],b[105],c[105];

void suit(int *a,int &n)
{
	int i,k;
	//for(i=1;i<=n;++i)printf("%d ",a[i]);printf("\n");
	for(k=1,i=2;i<=n;++i)if(a[i]!=a[k])++k,a[k]=a[i];
	//for(i=1;i<=k;++i)printf("%d ",a[i]);printf("\n");
	n=k;
}

void dfs(int x,int y,int z)
{
	//printf("______ %d %d %d %d\n",x,y,z,a[z][1]);
	if(y==1)
	{
		if(a[z][1]==0)
		{
			if(z<ans)
			{
				ans=z;
				for(int i=1;i<=z;++i)c[i]=b[i];
			}
			return;
		}
	}
	if(x>17)return;
	int i,w;
	for(i=1;i<=y;++i)
	{
		w=abs(a[z][i]);
		w=w&-w;
		if(w==(1<<x))break;
	}
	if(i<=y)
	{
		int k;
		b[z+1]=(1<<x);
		for(i=1;i<=y;++i)
		{
			w=abs(a[z][i]);
			w=w&-w;
			if(w==(1<<x))a[z+1][i]=a[z][i]-(1<<x);
			else a[z+1][i]=a[z][i];
		}
		k=y;
		suit(a[z+1],k);
		dfs(x+1,k,z+1);
		
		b[z+1]=-(1<<x);
		for(i=1;i<=y;++i)
		{
			w=abs(a[z][i]);
			w=w&-w;
			if(w==(1<<x))a[z+1][i]=a[z][i]+(1<<x);
			else a[z+1][i]=a[z][i];
		}
		k=y;
		suit(a[z+1],k);
		dfs(x+1,k,z+1);
	}
	else dfs(x+1,y,z);
}

int main()
{
	scanf("%d",&n);ans=100;
	for(i=1;i<=n;++i)scanf("%d",&a[0][i]);
	sort(a[0]+1,a[0]+n+1);
	suit(a[0],n);
	dfs(0,n,0);
	printf("%d\n",ans);
	for(i=1;i<=ans;++i)printf("%d ",c[i]);
	printf("\n");
}