#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod=1e9+7,md=1e9+6;
int n,even,t=1;

int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ll x;scanf("%lld",&x);
		t=(ll)t*(x%md)%md;even|=!(x&1);
	}
	t=(t+md-1)%md;
	int a,b=exp(2,t);
//	printf("%d %d\n",t,even);
	if(even) a=(ll)(exp(2,t)+1)*exp(3,mod-2)%mod; else a=(ll)(exp(2,t)+mod-1)*exp(3,mod-2)%mod;
	printf("%d/%d",a,b);return 0;
}
/*
1
2
*/