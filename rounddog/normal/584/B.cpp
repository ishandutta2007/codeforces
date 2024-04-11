#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#define mod 1000000007

using namespace std;
typedef long long int ll;

int n;
ll a,b;

int main()
{
	scanf("%d",&n);
	a=b=1;
	for (int i=1;i<=n;i++)
	{
		a=a*27%mod;
		b=b*7%mod;
	}
	printf("%d\n",(a-b+mod)%mod);
	return 0;
}