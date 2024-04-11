#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

set< pair<ll , ll> > ans;
vector< pair<ll , ll> > v;

void solve(ll l , ll r){
	ll m = (r + l) / 2;
	if(r - l == 1){
		ans.insert( {v[l].first , v[l].second} );
		return;
	}
	if(r - l < 1){
		return;
	}
	solve(l , m); solve(m + 1 , r);
	for(int i = l ; i < r ; i++){
		ans.insert( {v[m].first , v[i].second} );
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll x , y;
		cin>>x>>y;
		v.push_back( {x , y} );
	}
	sort(v.begin() , v.end());
	solve(0 , n);
	cout<<ans.size()<<"\n";
	set< pair<ll , ll> >::iterator it = ans.begin();
	while(it != ans.end()){
		pair<ll , ll> p = *it;
		cout<<p.first<<" "<<p.second<<"\n";
		it++;
	}
	return 0;
}