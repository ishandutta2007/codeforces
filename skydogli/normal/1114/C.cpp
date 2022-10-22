#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,b;
int cnt,d[100005],ned[100005];
signed main(){
	scanf("%lld%lld",&n,&b);
	for(int i=2;i*i<=b;++i)
		if(b%i==0){
			d[++cnt]=i;
			while(b%i==0){ned[cnt]++;b/=i;}
		}
	if(b!=1){
		d[++cnt]=b;
		ned[cnt]=1;
	}
	int Min=1e18;
	for(int i=1;i<=cnt;++i){
		int v=d[i],w=v,res=0;
		while(v<=n){
			res+=n/v;
			if(n/w<v)break;
			v*=w;
		}
		Min=min(Min,res/ned[i]);
	}
	printf("%lld\n",Min);
	return 0;
}