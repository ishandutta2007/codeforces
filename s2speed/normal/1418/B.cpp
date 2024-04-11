#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 100;

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

ll a[MAX_N] , b[MAX_N] , ans[MAX_N];
vector<ll> v;

void solve(){
	ll n , x = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>>b[i];
		if(b[i] == 0){
			v.push_back(a[i]);
		}
	}
	sort(v.begin() , v.end() , greater<ll>());
	for(int i = 0 ; i < n ; i++){
		if(b[i] == 0){
			ans[i] = v[x];
			x++;
		} else {
			ans[i] = a[i];
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	v.clear();
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , x = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		for(int i = 0 ; i < n ; i++){
			cin>>b[i];
			if(b[i] == 0){
				v.push_back(a[i]);
			}
		}
		sort(v.begin() , v.end() , greater<ll>());
		for(int i = 0 ; i < n ; i++){
			if(b[i] == 0){
				ans[i] = v[x];
				x++;
			} else {
				ans[i] = a[i];
			}
		}
		for(int i = 0 ; i < n ; i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		v.clear();
	}
	return 0;
}