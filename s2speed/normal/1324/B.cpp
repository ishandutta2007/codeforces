#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t > 0){
		ll h;
		vector<ll> v;
		bool ans = false;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			v.push_back(h);
		}
		for(int i = 0 ; i < n - 2 && ans == false ; i++){
			for(int j = i + 2 ; j < n && ans == false ; j++){
				if(v[i] == v[j]){
					ans = true;
				}
			}
		}
		if(ans == true){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		v.clear();
		t--;
	}
	return 0;
}