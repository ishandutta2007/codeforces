#include <cstdio>
using namespace std;
int n,m;
int i,j,u,v;
int link[20];
long long f[20][524288];
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		link[u]|=1<<v-1;
		link[v]|=1<<u-1;
	}
	link[0]=(1<<n)-1;
	f[0][0]=1;
	for (i=0;i<1<<n;i++)
		for (j=0;j<=n;j++)
			if (f[j][i])
			{
				u=link[j];
				while (u)
				{
					v=__builtin_ctz(u);
					if (__builtin_popcount(i)>2&&i!=0&&v==__builtin_ctz(i))
						ans+=f[j][i];
					else
						if ((i==0||v>__builtin_ctz(i))&&(((1<<v)&i)==0))
							f[v+1][i|(1<<v)]+=f[j][i];
					u^=1<<v;
				}
			}
	printf("%lld\n",ans>>1);
	return 0;
}