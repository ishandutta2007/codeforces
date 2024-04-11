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

vector<string> v;

void solve(){
	ll n , a = 0 , b = 0 , c = 0 , k;
	v.clear();
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		v.push_back(s);
		for(int j = 0 ; j < n ; j++){
			if(s[j] == 'X'){
				if((i + j) % 3 == 0){
					a++;
				} else if((i + j) % 3 == 1){
					b++;
				} else {
					c++;
				}
			}
		}
	}
	if(a <= min(b , c)){
		k = 0;
	} else if(b <= min(a , c)){
		k = 1;
	} else {
		k = 2;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(v[i][j] == 'X' && (i + j) % 3 == k){
				v[i][j] = 'O';
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout<<v[i]<<'\n';
	}
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