#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1000+19;
int m,k,oil,time,Max,s[Maxn],d[Maxn];

int main()
{
	scanf("%d%d",&m,&k);
	for (int i=1;i<=m;i++) scanf("%d",&d[i]);
	for (int i=1;i<=m;i++) scanf("%d",&s[i]);
	for (int i=1;i<=m;i++)
	{
		oil+=s[i];
		Max=max(Max,s[i]);
		while (oil<d[i]) oil+=Max,time+=k;
		oil-=d[i];time+=d[i];
	}
	printf("%d\n",time);
}