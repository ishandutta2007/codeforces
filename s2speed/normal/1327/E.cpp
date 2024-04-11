#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll md = 998244353;

ll tav(ll a , ll b){
	if(b <= 0) return 1;
	ll x = tav(a , b / 2);
	x *= x;
	x %= md;
	if(b % 2 == 0){
		return x % md;
	} else {
		return x * a % md;
	}
}

ll t(ll a , ll n){
	ll ans = 0;
	ans += 2 * 9 * tav(10 , n - a - 1);
	ans %= md;
	if(n > a){
		ans += (n - a - 1) * (81 * tav(10 , n - a - 2));
		ans %= md;
	}
	return ans * 10 % md;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;
	for(int i = 1 ; i < n ; i++){
		cout<<t(i , n)<<" ";
	}
	cout<<10<<endl;
	return 0;
}