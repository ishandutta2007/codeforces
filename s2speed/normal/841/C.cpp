#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

vector<ll> a;
vector< pair<ll , ll> > b;
ll ans[MAX_N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		a.push_back(inp);
	}
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		b.push_back( make_pair(inp , i) );
	}
	sort(a.begin() , a.end() , greater<ll>());
	sort(b.begin() , b.end());
	for(int i = 0 ; i < n ; i++){
		ans[b[i].second] = a[i];
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}