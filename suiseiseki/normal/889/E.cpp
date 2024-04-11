#include <map>
#include <cstdio>
const int Maxn=200000;
const int Maxm=1000000;
typedef long long ll;
int n;
ll a[Maxn+5];
ll val[Maxm+5];
std::map<ll,ll> mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	mp[a[1]-1]=0;
	for(int i=1;i<n;i++){
		int point=0;
		std::map<ll,ll>::reverse_iterator it=mp.rbegin();
		while(it!=mp.rend()){
			if((it->first)<a[i+1]){
				break;
			}
			mp[a[i+1]-1]=std::max(mp[a[i+1]-1],(it->second)+1ll*i*(a[i+1]*(((it->first)+1)/a[i+1])-a[i+1]));
			mp[(it->first)%a[i+1]]=std::max(mp[(it->first)%a[i+1]],(it->second)+1ll*i*((it->first)-(it->first)%a[i+1]));
			val[point]=(it->first);
			point++;
			it++;
		}
		while(point){
			point--;
			mp.erase(val[point]);
		}
	}
	ll ans=0;
	std::map<ll,ll>::reverse_iterator it=mp.rbegin();
	while(it!=mp.rend()){
		ans=std::max(ans,n*(it->first)+(it->second));
		it++;
	}
	printf("%lld\n",ans);
	return 0;
}