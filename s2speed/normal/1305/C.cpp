#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll n , m , h , s = 1;
	vector<ll> v;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		v.push_back(h);
	}
	if(n > m){
		cout<<0<<endl;
		return 0;
	}
	sort(v.begin() , v.end());
	for(int i = n - 1 ; i > 0 ; i--){
		for(int j = i - 1 ; j >= 0 ; j--){
			s *= (v[i] - v[j]);
			s %= m;
		}
	}
	cout<<s<<endl;
	return 0;
}