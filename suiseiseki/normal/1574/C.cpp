#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
ll a[Maxn+5];
ll sum;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	std::sort(a+1,a+1+n);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		int pos=std::lower_bound(a+1,a+1+n,x)-a;
		if(pos>n){
			ll ans=x-a[n]+std::max(0ll,y-(sum-a[n]));
			printf("%lld\n",ans);
		}
		else{
			ll ans=std::max(0ll,y-(sum-a[pos]));
			if(pos>1){
				ans=std::min(ans,x-a[pos-1]+std::max(0ll,y-(sum-a[pos-1])));
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}