#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int T,i,j,n,ans;
int a[1001];

inline int gcd(int a,int b)
{
	int tmp;
	while(b!=0)tmp=b,b=a%b,a=tmp;
	return a;
}

int main()
{
	//scanf("%d",&T);
	T=1;
	for(;T;--T)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		ans=a[1];
		for(i=2;i<=n;++i)ans=gcd(ans,a[i]);
		ans=a[n]/ans;
		if((ans-n)%2)printf("Alice\n");
		else printf("Bob\n");
	}
}