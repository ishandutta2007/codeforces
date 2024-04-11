#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t > 0){
		ll k;
		cin>>n>>k;
		if(n >= k * k && n % 2 == k % 2){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		t--;
	}
	return 0;
}