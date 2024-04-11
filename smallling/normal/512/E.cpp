#include<cstdio>
#include<cstring>

using namespace std;

int f[1010][1010],ansx[2020],ansy[2020];
int n,tot,last,x,y;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-3;i++)
	{
		scanf("%d%d",&x,&y);
                if(n==4)return puts("1"),printf("%d %d\n",x,y),0;
		if(x<y)f[x][y]=1;
		else f[y][x]=1;
	}
	for(int i=2;i<=n;i++)
		for(int j=n;j>i;j--)
			if(f[i][j])
			{
				ansx[++tot]=i;
				ansy[tot]=j;
			}
	last=tot;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n-3;i++)
	{
		scanf("%d%d",&x,&y);
		if(x<y)f[x][y]=1;
		else f[y][x]=1;
	}
	for(int i=2;i<=n;i++)
		for(int j=n;j>i;j--)
			if(f[i][j])
			{
				for(int k=j-1;k>i;k--)
				{
					if(k!=i+1&&!f[i][k])continue;
					ansx[++tot]=1;
					ansy[tot]=k;
					break;
				}
			}
	printf("%d\n",tot);
	for(int i=1;i<=last;i++)printf("%d %d\n",ansx[i],ansy[i]);
	for(int i=tot;i>last;i--)printf("%d %d\n",ansx[i],ansy[i]);
}