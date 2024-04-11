#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , n , m , h;
	vector<ll> v;
	cin>>t;
	while(t > 0){
		m = 1e9;
		cin>>n;
		for(int i = 0 ; i < 2 * n ; i++){
			cin>>h;
			v.push_back(h);
		}
		sort(v.begin() , v.end());
		for(int i = 0 ; i < 2 * n ; i++){
			if(i < n){
				m = min(v[n] - v[i] , m);
			} else {
				m = min(v[i] - v[n - 1] , m);
			}
		}
		cout<<m<<endl;
		v.clear();
		t--;
	}
	return 0;
}