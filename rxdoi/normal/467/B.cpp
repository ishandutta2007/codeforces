#include<cstdio>
using namespace std;

const int Maxn=1000+19;
int cnt,n,m,k,A[Maxn];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m+1;i++) scanf("%d",&A[i]);
	for (int i=1;i<=m;i++)
	{
		int x=A[i],y=A[m+1],tmp=0;
		for (int j=1;j<=n;j++) tmp+=((x&1)!=(y&1)),x>>=1,y>>=1;
		cnt+=(tmp<=k);
	}
	printf("%d\n",cnt);
}