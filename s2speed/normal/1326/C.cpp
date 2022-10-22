#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll md = 998244353;

ll ans(ll n , ll r){
	ll a = (n * (n + 1) / 2) - ((n - r) * (n - r + 1) / 2);
	return a;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , r , a = 1 , s = 1 , h;
	bool st = false;
	cin>>n>>r;
	cout<<ans(n , r)<<" ";
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		if(st == true){
			if(h <= n - r){
				s++;
			} else {
				a *= s;
				a %= md;
				s = 1;
			}
		} else if(h > n - r){
			st = true;
		}
	}
	cout<<a<<endl;
	return 0;
}