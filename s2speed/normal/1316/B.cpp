#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

string shift(string s , ll t){
	string h;
	for(int i = t - 1 ; i < s.size() ; i++){
		h += s[i];
	}
	for(int i = 0 ; i < t - 1 ; i++){
		h += s[i];
	}
	if(s.size() % 2 == t % 2){
		reverse(h.begin() + s.size() - t + 1 , h.end());
	}
	return h;
}

int main(){
	ll t;
	cin>>t;
	while(t > 0){
		ll n , mi;
		vector<ll> v;
		string s , m;
		cin>>n>>s;
		m = s;
		mi = 1;
		for(int i = 2 ; i <= n ; i++){
			if(shift(s , i) < m){
				m = shift(s , i);
				mi = i;
			}
		}
		cout<<m<<endl<<mi<<endl;
		t--;
	}
	return 0;
}