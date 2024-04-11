#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , n;
	cin>>t;
	while(t > 0){
		ll h;
		vector<ll> a , b;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			a.push_back(h);
		}
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			b.push_back(h);
		}
		sort(a.begin() , a.end());
		sort(b.begin() , b.end());
		for(int i = 0 ; i < n ; i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		for(int i = 0 ; i < n ; i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
		a.clear();
		b.clear();
		t--;
	}
	return 0;
}