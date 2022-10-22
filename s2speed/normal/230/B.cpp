#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll t = 1e6 + 1;

bool gh[1000001];
set<ll> s;

void prime(){
	gh[0] = false;
	gh[1] = false;
	for(ll i = 2 ; i < t ; i++){
		gh[i] = true;
	}
	for(ll i = 2 ; i < t ; i++){
		if(gh[i] == true){
			s.insert(i * i);
			for(int j = 2 * i ; j < t ; j += i){
				gh[j] = false;
			}
		}
	}
	return ;
}

int main(){
	prime();
	ll n , h;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		if(s.find(h) == s.end()){
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
	}
	return 0;
}