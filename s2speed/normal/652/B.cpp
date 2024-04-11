#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2e5 + 20;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

vector<ll> v , ans;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
	}
	sort(v.begin() , v.end());
	ll x = 0 , y = n - 1;
	for(int i = 0 ; i < n ; i++){
		if(i % 2 == 0){
			ans.push_back(v[x]);
			x++;
		} else {
			ans.push_back(v[y]);
			y--;
		}
	}
	for(auto i : ans){
		cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}