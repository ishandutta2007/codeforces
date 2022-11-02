#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k==1)return printf("%lld",n),0;
	for(k=1;k<=n;k<<=1);
	printf("%lld",k-1);
}