#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
	ll i,j,k,l,m,n,cnt=0,sum=0,ans=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&m);
		if(m==0) cnt++;
		else sum+=m;
	}
	//printf("%lld %lld\n",sum)
	if(sum+cnt==0){
		printf("%lld\n",cnt+1);
	}
	else printf("%lld\n",cnt);

	}
}