#include <cstdio>
#include <algorithm>
using namespace std;
const int N=105;
const int C=N*N;
int n,k;
int c[C];
int x[N],y[N];
int las[N];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n*k;i++)
		scanf("%d",&c[i]);
	for (int l=1,r;l<=n;l+=(k-1))
	{
		r=l+k-2;
		if (r>n)
			r=n;
		int lim=0;
		for (int j=1;j<=n*k;j++)
			if (l<=c[j]&&c[j]<=r)
				if (x[c[j]]==0&&y[c[j]]==0)
				{
					if (las[c[j]]<=lim)
						las[c[j]]=j;
					else
					{
						lim=j;
						x[c[j]]=las[c[j]];
						y[c[j]]=j;
					}
				}
	}
	for (int i=1;i<=n;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}