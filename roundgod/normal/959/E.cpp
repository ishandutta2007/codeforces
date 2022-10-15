#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll find_res(ll x)
{
	if(x==1) return 1;
	return (x+1)/2+2*find_res(x/2);
}
int main()
{
	scanf("%I64d",&n);
	printf("%I64d\n",find_res(n-1));
	return 0;
}