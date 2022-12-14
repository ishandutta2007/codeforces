#include<cstdio>
const int N=505;
int x[N],y[N],n,m;
int main()
{
	scanf("%d",&n); int m=n;
	n=4*n+1;
	for(int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<=50;++i)
		for(int j=0;j<=50;++j)
			for(int k=0;k<=50&&i+k<=50&&j+k<=50;++k)
			{
				int tot=0,ans;
				for(int l=1;l<=n;++l)
				{
					if(x[l]==i&&j<=y[l]&&y[l]<=j+k) ++tot;
					else if(x[l]==i+k&&j<=y[l]&&y[l]<=j+k) ++tot;
					else if(y[l]==j&&i<=x[l]&&x[l]<=i+k) ++tot;
					else if(y[l]==j+k&&i<=x[l]&&x[l]<=i+k) ++tot;
					else ans=l;
				}
				if(tot==n-1)
				{
					printf("%d %d",x[ans],y[ans]);
					return 0;
				}
			}
}