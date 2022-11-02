#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e6+10;
const int p = 998244353;

ll n,c[N],sum;

int main()
{
	scanf("%lld",&n);
	for(int i=1;i <= n;i++) for(int j=i;j <= n;j += i) c[j]++;
	for(int i=1;i <= n;i++) c[i] = (c[i]+sum)%p , sum = (sum+c[i])%p;
	printf("%lld\n",c[n]);
}