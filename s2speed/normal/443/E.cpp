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

vector<ll> v;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		if(v.size() < 2){
			v.push_back(h);
		} else {
			while(v.size() >= 2){
				if(v.back() <= h && v[v.size() - 2] >= v.back()){
					v.pop_back();
					ans += min(h , v.back());
				} else {
					break;
				}
			}
			v.push_back(h);
		}
	}
	sort(v.begin() , v.end() , greater<ll>());
	while(v.size() > 2){
		ans += v.back();
		v.pop_back();
	}
	cout<<ans<<'\n';
	return 0;
}