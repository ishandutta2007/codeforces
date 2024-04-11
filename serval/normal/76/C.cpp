#include <cstdio>
using namespace std;
int n,k,t;
int i,j,o;
char gene[200005];
int risk[4200005],rp[30][30];
int st[30],used;
bool vis[30];
int ans;
int main()
{
	scanf("%d%d%d",&n,&k,&t);
	scanf("%s",gene+1);
	for (i=1;i<=k;i++)
		scanf("%d",&risk[1<<i-1]);
	for (i=1;i<=k;i++)
		for (j=1;j<=k;j++)
			scanf("%d",&rp[i][j]);
	for (i=1;i<=n;i++)
	{
		o=gene[i]-'A'+1;
		for (j=1;j<=k;j++)
			if (vis[j])
			{
				if ((st[j]&(1<<o-1))==0)
				{
					risk[st[j]]+=rp[j][o];
					risk[st[j]|(1<<o-1)]-=rp[j][o];
					risk[st[j]|(1<<j-1)]-=rp[j][o];
					risk[st[j]|(1<<o-1)|(1<<j-1)]+=rp[j][o];
				}
				st[j]|=1<<o-1;
			}
		vis[o]=1;
		st[o]=0;
		used|=1<<o-1;
	}
	for (i=1;i<=k;i++)
		for (j=0;j<(1<<k);j+=1<<i)
			for (o=0;o<(1<<i-1);o++)
				risk[j+o+(1<<i-1)]+=risk[j+o];
	for (i=0;i<(1<<k);i++)
		if (risk[i]<=t&&(used&i)!=used&&(used&i)==i)
			ans++;
	printf("%d\n",ans);
	return 0;
}