#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t > 0){
		ll n , h;
		vector<ll> v;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			v.push_back(h);
		}
		sort(v.begin() , v.end());
		reverse(v.begin() , v.end());
		for(int i = 0 ; i < n ; i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		v.clear();
		t--;
	}
	return 0;
}