#include <cstdio>
using namespace std;
const int N=2e6;
int n;
int k,cur;
int u[N],v[N],cnt;
int p[N],pt;
bool np[N];
void ae(int a,int b)
{
	u[++cnt]=a;
	v[cnt]=b;
}
int main()
{
	scanf("%d",&n);
	np[1]=1;
	for (int i=2;i<N;i++)
	{
		if (!np[i])
			p[++pt]=i;
		for (int j=1;j<=pt&&p[j]*i<N;j++)
		{
			np[i*p[j]]=1;
			if (i%p[j]==0)
				break;
		}
	}
	for (int i=n;i<=n+(n-2)/2;i++)
		if (!np[i])
		{
			for (int j=1;j<=n;j++)
				ae(j,j%n+1);
			for (int j=1;j<=i-n;j++)
				ae(j,j+n/2);
			break;
		}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
		printf("%d %d\n",u[i],v[i]);
	return 0;
}