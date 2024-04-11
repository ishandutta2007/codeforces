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
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll d , h , a , b , ans;
	cin>>d>>h>>a>>b;
	d = h - d;
	for(int i = 0 ; i < 1e6 ; i++){
		if(d <= 0){
			cout<<i<<'\n';
			return 0;
		}
		d -= 8 * a;
		if(d <= 0){
			cout<<i<<'\n';
			return 0;
		}
		d += 12 * b;
		d -= 4 * a;
	}
	cout<<"-1\n";
	return 0;
}