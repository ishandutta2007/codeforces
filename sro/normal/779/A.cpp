#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int cn1[12],cn2[12],cnt[12],sum;
int n,a;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		cn1[a]++;
		cnt[a]++;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		cn2[a]++;
		cnt[a]++;
	}
	for(int i=1;i<=5;i++)if(cnt[i]%2==1)return puts("-1"),0;
	for(int i=1;i<=5;i++)
		sum+=abs(cn1[i]-(cnt[i]/2));
	sum/=2;
	return printf("%d",sum),0;
}