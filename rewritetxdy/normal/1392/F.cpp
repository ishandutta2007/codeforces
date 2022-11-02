#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6+10;

ll n,c[N];

int main()
{
	scanf("%lld",&n);
	ll sum = 0;
	for(int i=1;i <= n;i++) scanf("%lld",&c[i]) , sum += c[i];
	sum -= n*(n-1)/2;
	ll t = sum/n; sum %= n;
	for(int i=1;i <= n;i++) 
		printf("%lld ",t+i-1+(i <= sum));
	puts("");
	return 0;
}