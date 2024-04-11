#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 2e5+10;

ll n,p,v[N],c[N],ans = 1;

inline ll abss(ll x){
	return x > 0 ? x : -x;
}

int main()
{
	scanf("%lld%lld",&n,&p);
	for(int i=1;i <= n;i++)
		scanf("%lld",&c[i]) , v[c[i]%p]++;
	for(int i=0;i < p;i++){
		if(v[i] > 1){
			puts("0");
			return 0;
		}
	}
	for(int i=1;i <= n;i++)
		for(int j=i+1;j <= n;j++)
			ans = ans*abss(c[i]-c[j])%p;
	printf("%lld\n",ans);
	return 0;
}