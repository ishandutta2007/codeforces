#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll n , h;
	vector<ll> v;
	cin>>n;
	for(int i = 0 ; i <= 8e5 ; i++){
		v.push_back(0);
	}
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		v[400000 + h - i] += h;
	}
	sort(v.begin() , v.end());
	cout<<v[v.size() - 1]<<endl;
	return 0;
}