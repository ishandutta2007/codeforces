#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main()
{
   	ll t;
   	scanf("%lld",&t);
   	while(t--){
   		ll n,m;
   		scanf("%lld %lld",&n,&m);
   		if(m*m<=n&&(n+m)%2==0){
   			printf("YES\n");
   		}
   		else printf("NO\n");
   	}
}