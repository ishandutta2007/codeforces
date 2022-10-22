#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	ll ans = 1 , n , t[] = {1 , 3 , 9 , 27 , 81 , 243 , 729};
	cin>>s; n = s.size();
	for(int i = 0 ; i < n ; i++){
		ll o;
		if(s[i] - '0' < 10 && s[i] >= '0'){
			o = s[i] - '0';
		}
		if(s[i] - 'A' < 26 && s[i] >= 'A'){
			o = s[i] - 'A' + 10;
		}
		if(s[i] - 'a' < 26 && s[i] >= 'a'){
			o = s[i] - 'a' + 36;
		}
		if(s[i] == '-'){
			o = 62;
		}
		if(s[i] == '_'){
			o = 63;
		}
		ll k = __builtin_popcount(o);
		k = 6 - k;
		ans *= t[k];
		ans %= md;
	}
	cout<<ans<<'\n';
	return 0;
}