#include<cstdio>
using namespace std;

const int Maxn=1e6+19;
int n;
int p[Maxn];

int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
		if (!p[i])
			for (int j=i+i;j<=n;j+=i) p[j]=1;
	for (int i=4;i<=n/2;i++)
		if (p[i]&&p[n-i]) {printf("%d %d\n",i,n-i);return 0;}
}