#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
ll h;
inline bool check(ll k){
	ll ret=0;
	for(ri i=1;i<=n;++i){
		if(i==n||a[i]+k-1<a[i+1])ret+=k;
		else ret+=a[i+1]-a[i];
	}
	return ret>=h;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%lld",&n,&h);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ll ans=0,l=0,r=1e18;
		while(l<=r){
			ll mid=l+r>>1;
			if(check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}