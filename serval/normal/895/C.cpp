#include <cstdio>
using namespace std;
const int maxn=100005;
const long long mod=1000000007;
int n,i,j,k;
int cnt[80],pow2[maxn];
int f[80][524288];
int p[25],pcnt;
bool np[80];
int bit[80];
int main()
{
	scanf("%d",&n);
	pow2[0]=1;
	for (i=1;i<maxn;i++)
		pow2[i]=(pow2[i-1]*2)%mod;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&j);
		cnt[j]++;
	}
	for (i=2;i<=70;i++)
	{
		if (!np[i])
		{
			pcnt++;
			p[pcnt]=i;
			bit[i]=1<<(pcnt-1);
		}
		for (j=1;j<=pcnt&&p[j]*i<=70;j++)
		{
			bit[i*p[j]]=bit[i]^bit[p[j]];
			np[i*p[j]]=1;
			if (i%p[j]==0)
				break;
		}
	}
	f[0][0]=1;
	for (i=1;i<=70;i++)
		for (j=0;j<524288;j++)
			if (f[i-1][j])
				if (cnt[i])
				{
					f[i][j^bit[i]]=((long long)f[i][j^bit[i]]
						+(long long)f[i-1][j]*(long long)pow2[cnt[i]-1])%mod;
					f[i][j]=((long long)f[i][j]
						+(long long)f[i-1][j]*(long long)pow2[cnt[i]-1])%mod;
				}
				else
					f[i][j]=(f[i][j]+f[i-1][j])%mod;
	printf("%d\n",f[70][0]-1);
	return 0;
}