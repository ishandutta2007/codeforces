#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int main()
{
	long long n,a,b,n1;
	cin>>n>>a>>b;
	long long g=__gcd(a,b);
	a/=g;
	b/=g;
	for(n1=1;n1<=n;n1++)
	{
		scanf("%I64d",&g);
		long long k=g*a/b;
		if(k*b%a==0)
			k=k*b/a;
		else
			k=k*b/a+1;
		printf("%I64d ",g-k);
	}
}