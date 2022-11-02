#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long ll;
const int N = 200020;

ll n,k,ans=1,sum,c[N];
const ll p = 998244353;

int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i <= n;i++)
		scanf("%lld",&c[i]);
	for(int i=0;i < k;i++)
		sum += n-i;
	ll las = 0;
	for(int i=1;i <= n;i++)
		if(c[i] >= n-k+1){
			if(las) ans = ans*(i-las)%p;
			las = i;
		}
	printf("%lld %lld\n",sum,ans);
}