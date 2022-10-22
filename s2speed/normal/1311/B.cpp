#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , m , n , a[100] , h;
	set<ll> p;
	bool ch;
	cin>>t;
	while(t > 0){
		ch = true;
		cin>>n>>m;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		for(int i = 0 ; i < m ; i++){
			cin>>h;
			p.insert(h);
		}
		for(int i = 1 ; i < n ; i++){
			for(int j = i - 1 ; j >= 0 ; j--){
				if(a[j] > a[j + 1]){
					swap(a[j] , a[j + 1]);
					if(p.find(j + 1) == p.end()) ch = false;
				}
			}
		}
		if(ch == false){
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
		p.clear();
		t--;
	}
}