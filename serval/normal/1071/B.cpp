#include <cstdio>
using namespace std;
const int N=2005;
char s[N][N];
int n,k;
int i,j,cur;
int f[N][N];
int c;
int hx,hy,nxx[N][N],nxy[N][N];
char ans[N<<1];
bool vis[N][N];
int cx[255],cy[255];
int main()
{
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			f[i][j]=n*n;
			if (i==1&&j==1)
				f[i][j]=0;
			if (i>1)
				if (f[i-1][j]<f[i][j])
					f[i][j]=f[i-1][j];
			if (j>1)
				if (f[i][j-1]<f[i][j])
					f[i][j]=f[i][j-1];
			f[i][j]+=(s[i][j]!='a');
		}
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (f[i][j]<=k)
			{
				if (i+j>cur)
				{
					cur=i+j;
					hx=hy=0;
				}
				if (i+j<cur)
					continue;
				nxx[i][j]=hx;
				nxy[i][j]=hy;
				hx=i;
				hy=j;
			}
	if (cur)
	{
		cur--;
		for (i=1;i<=cur;i++)
			ans[i]='a';
	}
	else
	{
		if (hx==0)
			hx=hy=1;
		ans[1]=s[1][1];
		cur=1;
	}
	for (c=cur+1;c<=2*n-1;c++)
	{
		for (i='a';i<='z';i++)
			cx[i]=cy[i]=0;
		i=hx;
		j=hy;
		while (i!=0)
		{
			if (j<n)
				if (!vis[i][j+1])
				{
					vis[i][j+1]=1;
					nxx[i][j+1]=cx[s[i][j+1]];
					nxy[i][j+1]=cy[s[i][j+1]];
					cx[s[i][j+1]]=i;
					cy[s[i][j+1]]=j+1;
				}
			if (i<n)
				if (!vis[i+1][j])
				{
					vis[i+1][j]=1;
					nxx[i+1][j]=cx[s[i+1][j]];
					nxy[i+1][j]=cy[s[i+1][j]];
					cx[s[i+1][j]]=i+1;
					cy[s[i+1][j]]=j;
				}
			hx=nxx[i][j];
			hy=nxy[i][j];
			i=hx;
			j=hy;
		}
		hx=hy=0;
		for (i='a';i<='z';i++)
			if (cx[i]!=0)
				break;
		ans[c]=i;
		hx=cx[i];
		hy=cy[i];
	}
	printf("%s\n",ans+1);
	return 0;
}