#include <cstdio>
#include <cstring>
using namespace std;
int n,i,j;
int v[1005];
int p[10][1005];
int cnt[10];
int id[1005];
int l,r,mid,ans;
int f[1005][256];
bool check(int u)
{
	int ret=0;
	memset(f,0xC0,sizeof(f));
	f[0][0]=0;
	for (i=1;i<=n;i++)
		for (j=0;j<256;j++)
		{
			if (j&(1<<v[i]-1))
			{
				if (p[v[i]][id[i]-u+1]>0)
					if (f[p[v[i]][id[i]-u+1]-1][j^(1<<v[i]-1)]+u>f[i][j])
						f[i][j]=f[p[v[i]][id[i]-u+1]-1][j^(1<<v[i]-1)]+u;
				if (p[v[i]][id[i]-u]>0)
					if (f[p[v[i]][id[i]-u]-1][j^(1<<v[i]-1)]+u+1>f[i][j])
						f[i][j]=f[p[v[i]][id[i]-u]-1][j^(1<<v[i]-1)]+u+1;
				if (u!=0)
					if (j==255&&f[i][j]>ret)
						ret=f[i][j];
				if (u==0)
					if (f[i][j]>ret)
						ret=f[i][j];
			}
			if (f[i-1][j]>f[i][j])
				f[i][j]=f[i-1][j];
		}
	if (ret>ans)
		ans=ret;
	return ret>0;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		cnt[v[i]]++;
		id[i]=cnt[v[i]];
		p[v[i]][id[i]]=i;
	}
	l=0;
	r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}