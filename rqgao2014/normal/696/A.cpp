#include<bits/stdc++.h>
#define ll long long
using namespace std;

int q;
map<ll,ll> w;
inline int dep(ll x){
	int ans=0;
	while(x!=1) ans++,x>>=1;
	return ans;
}

int main(){
	scanf("%d",&q);
	while(q--){
		int typ;ll u,v,x;
		scanf("%d%lld%lld",&typ,&u,&v);
		if(typ==2){
			if(dep(u)>dep(v)) swap(u,v);
			ll ans=0;
			while(dep(u)<dep(v)) ans+=w[v],v=v>>1;
			while(u!=v) ans+=w[u],ans+=w[v],v>>=1,u>>=1;
			printf("%lld\n",ans);
		}
		else{
			scanf("%lld",&x);
			if(dep(u)>dep(v)) swap(u,v);
			while(dep(u)<dep(v)) w[v]+=x,v=v>>1;
			while(u!=v) w[u]+=x,w[v]+=x,v>>=1,u>>=1;
		}
	}
	return 0;
}
/*
7
1 3 4 30
1 4 1 2
1 3 6 8
2 4 3
1 6 1 40
2 3 7
2 2 4
*/