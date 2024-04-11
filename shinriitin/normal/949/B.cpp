#include <bits/stdc++.h>

using ll = long long;

ll n,x,pw[233];

ll f(ll n,ll x){
	if(n==1||x==1)return 1;
	int pos=std::lower_bound(pw+1,pw+61,n)-pw-1;
	ll m=pw[pos],k=n-m;
	if(x<=(k<<1)){
		if(x&1)return (x+1)>>1;
		return f(m,m-k+(x>>1))+k;
	}
	return f(m,x-(k<<1))+k;
}

int main(){
	pw[0]=1;
	for(int i=1;i<=60;++i)
		pw[i]=pw[i-1]<<1;
	int q;
	scanf("%lld%d",&n,&q);
	while(q--){
		scanf("%lld",&x);
		printf("%lld\n",f(n,x));
	}
	return 0;
}