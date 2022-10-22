#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;
typedef double db;

const ll MAX_N = 2e5 + 20;

ll tav(ll n , ll k){
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
	
	db ans , hn , hc;
	string a , b;
	ll x = 0 , n , l = 0 , r = 0;
	cin>>a>>b;
	n = a.size();
	for(int i = 0 ; i < n ; i++){
		x += (a[i] == '+');
	}
	for(int i = 0 ; i < n ; i++){
		if(b[i] == '+'){
			l++;
			r++;
		} else if(b[i] == '?'){
			r++;
		}
	}
	if(x > r || x < l){
		cout<<"0\n";
		return 0;
	}
	x -= l;
	r -= l;
	hn = tav(2 , r);
	hc = 1;
	for(db i = 2 ; i <= r ; i++){
		hc *= i;
	}
	for(db i = 2 ; i <= x ; i++){
		hc /= i;
	}
	for(db i = 2 ; i <= r - x ; i++){
		hc /= i;
	}
	ans = hc / hn;
	printf("%.10lf\n" , ans);
	return 0;
}