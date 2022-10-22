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
	
	string s;
	cin>>s;
	ll n = s.size(); s += '?';
	for(int i = 1 ; i < n ; i++){
		if(s[i] == s[i - 1]){
			if('a' != s[i - 1] && 'a' != s[i + 1]){
				s[i] = 'a';
			} else if('b' != s[i - 1] && 'b' != s[i + 1]){
				s[i] = 'b';
			} else {
				s[i] = 'z';
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout<<s[i];
	}
	cout<<'\n';
	return 0;
}