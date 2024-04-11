#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e5+10;
map<ll,set<ll> >mp;
ll how=1;//how is 0
ll tree[maxn],n,ans;
ll ask(ll ind){
	ll ans=0;
	while(ind>0){
		ans+=tree[ind];
		ind-=(ind & -ind);
	}
	return ans;
}
void add(ll ind,ll val){
	while(ind<=n){
		tree[ind]+=val;
		ind+=(ind & -ind);
	}
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		add(i,1);
	}
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;
		mp[x].insert(i);
	}
	ll now=1;
	for(ll i=1;i<=n;i++){
		set<ll>&s=mp.begin()->S;
		set<ll>::iterator it=(s.lower_bound(now));
		ll next;
		if(it==s.end()){
			ans+=ask(n)-ask(now)+how;
			now=1;
			it=s.lower_bound(now);
		}
		next=*it;
		s.erase(it);
		if(s.empty())mp.erase(mp.begin());
//		cout<<now<<" "<<next<<endl;
		ans+=ask(next)-ask(now);
		now=next;
		add(now,-1);
		if(now==1)how=0;
//		cout<<ans<<endl;
	}
	cout<<ans+1;//because we didnt count the first action
}