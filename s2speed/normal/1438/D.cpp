#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e5 + 20;

struct trio{
	ll a , b , c;
};

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

ll x[MAX_N];
vector<trio> ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , h = 0 , q;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>x[i];
		h ^= x[i];
	}
	if(h && !(n % 2)){
		cout<<"NO\n";
		return 0;
	}
	for(int i = 1 ; i <= n - 2 ; i += 2){
		ans.push_back( {i , i + 1 , i + 2} );
	}
	if(n % 2){
		q = n - 4;
	} else {
		q = n - 5;
	}
	for(int i = q ; i >= 1 ; i -= 2){
		ans.push_back( {i , i + 1 , i + 2} );
	}
	cout<<"YES\n"<<ans.size()<<"\n";
	for(auto o : ans){
		cout<<o.a<<" "<<o.b<<" "<<o.c<<"\n";
	}
	return 0;
}