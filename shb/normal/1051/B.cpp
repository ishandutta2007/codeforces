#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL L,R;
	scanf("%lld%lld",&L,&R);
	puts("YES");
	for (LL i=L;i<=R;i+=2)printf("%lld %lld\n",i,i+1);
}