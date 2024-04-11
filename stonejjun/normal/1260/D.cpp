#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define ff first 
#define ss second


struct trap{
	ll li,ri,di;
};
trap arr[1010101];

ll biggesttrap[1010101];
ll cango[1010101];
ll abil[1010101];
vector<pii> mut[1010101];


int main(){
	ll i,j,k,l,m,n,t;
	scanf("%lld %lld %lld %lld",&n,&m,&k,&t);
	for(i=1;i<=n;i++)
		scanf("%lld",&abil[i]);
	for(i=1;i<=k;i++){
		scanf("%lld %lld %lld",&arr[i].li,&arr[i].ri,&arr[i].di);
		mut[arr[i].li].emplace_back(arr[i].ri,arr[i].di);
	}

	ll hi=202020;
	ll lo=0;
	while(lo<hi){
		ll mid=(lo+hi)/2;
		ll fgun=0,fna=0,tim=0;
		while(fgun<=m){
			for(auto x : mut[fgun+1]){
				if(x.ff<=fna||x.ss<=mid) continue;
				ll todo=2*(x.ff-fna);
				fna=x.ff;
				tim+=todo;
			}
			tim++;
			fgun++;
			fna=max(fna,fgun);
		}
		if(tim<=t) hi=mid;
		else lo=mid+1;
		//printf("%lld %lld %lld %lld %lld %lld\n",hi,lo,mid,tim,fgun,t);
	}

	ll cnt=0;
	for(i=1;i<=n;i++){
		if(abil[i]>=lo) cnt++;
	}
	printf("%lld\n",cnt);

}