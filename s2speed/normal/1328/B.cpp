#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll c(ll n){
	return n * (n - 1) / 2;
}

string ans(ll n , ll k){
	string s;
	if(k > c(n - 1)){
		s += "b";
		for(int i = n - 1 ; i > 0 ; i--){
			if(i != k - c(n - 1)){
				s += "a";
			} else {
				s += "b";
			}
		}
	} else {
		s += "a";
		s += ans(n - 1 , k);
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n , k;
	cin>>t;
	while(t > 0){
		cin>>n>>k;
		cout<<ans(n , k)<<endl;
		t--;
	}
	return 0;
}