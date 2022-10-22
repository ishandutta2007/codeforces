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
set<ll> s;
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , b = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		s.insert(a[i]);
		if(a[i] > i + 1){
			cout<<-1<<"\n";
			return 0;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		if(s.find(i) == s.end()){
			v.push_back(i);
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i] == b){
			cout<<v[0]<<" ";
			v.erase(v.begin());
		} else {
			cout<<b<<" ";
		}
		b = a[i];
	}
	return 0;
}