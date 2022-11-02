#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int now,n,k,s,ans,a[151],f[2][152][150*149/2+1];

int main()
{
	scanf("%d%d%d",&n,&k,&s);
	s=min(s,n*(n-1)/2);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));
	f[now][0][0]=0;
	for(int i=1;i<=n;i++,now^=1)
		for(int j=0;j<=k;j++)
			for(int l=0;l<=s;l++)
				if(f[now][j][l]!=0x3f3f3f3f)
				{
					f[now^1][j][l]=min(f[now^1][j][l],f[now][j][l]);
					if(j+1<=k&&l+i-(j+1)<=s)f[now^1][j+1][l+i-(j+1)]=min(f[now^1][j+1][l+i-(j+1)],f[now][j][l]+a[i]);
				}
	ans=0x3f3f3f3f;
	for(int l=0;l<=s;l++)
		ans=min(ans,f[now][k][l]);
	printf("%d",ans);
}