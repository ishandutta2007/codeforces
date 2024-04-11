#include<cstdio>
#include<algorithm>

using namespace std;

int n,x,y,flag;
char s[155];
int a[155],f[155][155][155],ans[155][155];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1)a[i]=-0x3f3f3f3f;
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<=n;k++)
				f[i][j][k]=-0x3f3f3f3f;
	for(int k=1;k<=n;k++)
		for(int x=1;x<=n-k+1;x++)
		{
			y=x+k-1;
			flag=1;
			for(int i=x;i<y;i++)
				f[x][y][0]=max(f[x][y][0],f[x][i][0]+f[i+1][y][0]);
			for(int l=x,r=y;l<r;l++,r--)flag&=(s[l]==s[r]);
			if(flag)f[x][y][0]=max(f[x][y][0],a[k]),f[x][y][k]=max(f[x][y][k],0);
			for(int i=x;i<=y;i++)
				f[x][y][1]=max(f[x][y][1],(i-1>=x)*f[x][i-1][0]+(i+1<=y)*f[i+1][y][0]);
			for(int nowk=2;nowk<=k;nowk++)
			{
				for(int i=x;i<y;i++)
					f[x][y][nowk]=max(f[x][y][nowk],f[x][i][0]+f[i+1][y][nowk]),
					f[x][y][nowk]=max(f[x][y][nowk],f[x][i][nowk]+f[i+1][y][0]);
				if(s[x]==s[y])f[x][y][nowk]=max(f[x][y][nowk],f[x+1][y-1][nowk-2]);	
			}
			for(int nowk=1;nowk<=k;nowk++)
				f[x][y][0]=max(f[x][y][0],f[x][y][nowk]+a[nowk]);
			ans[x][y]=max(ans[x][y],f[x][y][0]);
			for(int i=x;i<y;i++)
				ans[x][y]=max(ans[x][y],ans[x][i]+ans[i+1][y]);
		}
	printf("%d",ans[1][n]);
}