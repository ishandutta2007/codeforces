#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

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

const ll z = 0;
ll a[100000];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		v.push_back(a[0]);
		for(int i = 1 ; i < n - 1 ; i++){
			if((a[i] > a[i - 1] && a[i] < a[i + 1]) || (a[i] < a[i - 1] && a[i] > a[i + 1])){
				continue;
			} else {
				v.push_back(a[i]);
			}
		}
		v.push_back(a[n - 1]);
		cout<<v.size()<<"\n";
		for(int i = 0 ; i < v.size() ; i++){
			cout<<v[i]<<" ";
		}
		cout<<"\n";
		v.clear();
	}
	return 0;
}