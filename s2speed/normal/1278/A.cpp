#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

bool ch(ll a[] , ll b[] , ll n){
	for(int i = 0 ; i < n ; i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}

int main(){
	ll t;
	cin>>t;
	while(t > 0){
		bool y = false;
		ll a[26] , b[26];
		for(int i = 0 ; i < 26 ; i++){
			a[i] = 0;
			b[i] = 0;
		}
		string s , v;
		cin>>s>>v;
		for(int i = 0 ; i < s.size() ; i++){
			b[s[i] - 97]++;
		}
		if(s.size() > v.size()){
			cout<<"NO"<<endl;
			t--;
			continue;
		}
		for(int i = 0 ; i < s.size() ; i++){
			a[v[i] - 97]++;
		}
		if(ch(a , b , 26) == true){
			cout<<"YES"<<endl;
			t--;
			continue;
		}
		for(int i = s.size() ; i < v.size() ; i++){
			a[v[i - s.size()] - 97]--;
			a[v[i] - 97]++;
			if(ch(a , b , 26) == true){
				cout<<"YES"<<endl;
				y = true;
				break;
			}
		}
		if(y == false){
			cout<<"NO"<<endl;
		}
		t--;
	}
	return 0;
}