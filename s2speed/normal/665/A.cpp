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
	
	ll a , ta , b , tb , t = 0 , l , r , ans = 0;
	cin>>a>>ta>>b>>tb;
	string s;
	cin>>s;
	t += (s[0] - '0') * 600;
	t += (s[1] - '0') * 60;
	t += (s[3] - '0') * 10;
	t += s[4] - '0';
	l = 300;
	r = tb + l;
	while(l < t + ta && l < 1440){
		if(r > t){
			ans++;
		}
		l += b;
		r += b;
	}
	cout<<ans<<'\n';
	return 0;
}