#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const int Maxv=1000000;
int n;
ll a[Maxn+5];
ll find_val(ll t){
	auto get_val=[&](ll a,ll b)->ll{
		return a*b+t*(a+b);
	};
	ll ans=get_val(a[1],a[n]);
	int pos_l=2,pos_r=n-1;
	while(pos_l<=pos_r){
		if(std::min(get_val(a[pos_l],a[n]),get_val(a[pos_r],a[n]))<std::min(get_val(a[pos_l],a[1]),get_val(a[pos_r],a[1]))){
			ans+=get_val(a[pos_l++],a[n]);
		}
		else{
			ans+=get_val(a[pos_r--],a[1]);
		}
	}
	return ans;
}
std::pair<ll,bool> work(){
	ll sum_1=0,sum_2=0;
	for(int i=2;i<=n;i++){
		sum_1+=a[i]+a[1];
	}
	for(int i=1;i<n;i++){
		sum_2+=a[i]+a[n];
	}
	if(sum_1>0||sum_2<0){
		return std::make_pair(0ll,1);
	}
	ll left=-1ll*Maxv,right=1ll*Maxv;
	while(left<right){
		ll mid_1=(left+right)>>1,mid_2=mid_1+1;
		ll val_1=find_val(mid_1),val_2=find_val(mid_2);
		if(val_1>val_2){
			right=mid_2-1;
		}
		else{
			left=mid_1+1;
		}
	}
	ll ans=find_val(left);
	return std::make_pair(ans,0);
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	std::sort(a+1,a+1+n);
	std::pair<ll,bool> ans=work();
	if(ans.second){
		puts("INF");
	}
	else{
		printf("%lld\n",ans.first);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}