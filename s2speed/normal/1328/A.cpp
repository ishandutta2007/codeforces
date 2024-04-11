#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t > 0){
		ll a , b;
		cin>>a>>b;
		if(a % b == 0){
			cout<<0<<endl;
		} else {
			cout<<b - (a % b)<<endl;
		}
		t--;
	}
	return 0;
}