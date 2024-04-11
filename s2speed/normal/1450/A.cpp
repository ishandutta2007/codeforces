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

vector<char> v;

void solve(){
	v.clear();
	ll n;
	string s;
	cin>>n>>s;
	for(int i = 0 ; i < n ; i++){
		v.push_back(s[i]);
	}
	sort(v.begin() , v.end());
	for(int i = 0 ; i < n ; i++){
		cout<<v[i];
	}
	cout<<'\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}