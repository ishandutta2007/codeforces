#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t--){
		bool ans = true;
		cin>>n;
		ll a , b , aa , bb;
		cin>>aa>>bb;
		if(aa < bb){
			ans = false;
		}
		for(int i = 1 ; i < n ; i++){
			cin>>a>>b;
			if(a < aa || b < bb){
				ans = false;
			} else if(a - b < aa - bb){
				ans = false;
			}
			aa = a;
			bb = b;
		}
		if(ans == true){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}