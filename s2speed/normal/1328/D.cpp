#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll ch(ll n){
	if(n == 1) return 2;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll T , n , m = 0 , t[200000];
	cin>>T;
	while(T > 0){
		m = 0;
		bool y = false;
		vector<ll> v;
		cin>>n>>t[0];
		v.push_back(t[0]);
		for(int i = 1 ; i < n ; i++){
			cin>>t[i];
			if(t[i] == t[i - 1]){
				y = true;
			} else {
				m++;
			}
			v.push_back(t[i]);
		}
		if(v[0] != v[n - 1]){
			m++;
		} else {
			y = true;
		}
		sort(v.begin() , v.end());
		if(v[0] == v[n - 1]){
			cout<<1<<endl;
			for(int i = 0 ; i < n ; i++){
				cout<<"1 ";
			}
			cout<<endl;
			T--;
			v.clear();
			continue;
		}
		if(y == false && n % 2 == 1){
			cout<<3<<endl;
			for(int i = 0 ; i < n - 1 ; i += 2){
				cout<<"1 2 ";
			}
			cout<<3<<endl;
		} else if(y == false && m % 2 == 0){
			cout<<2<<endl;
			for(int i = 0 ; i < n ; i += 2){
				cout<<"1 2 ";
			}
			cout<<endl;
		} else if(y == true && m % 2 == 1){
			cout<<2<<endl;
			ll h = 1;
			cout<<"1 ";
			for(int i = 1 ; i < n ; i++){
				if(t[i] == t[i - 1] && y == true){
					cout<<ch(h)<<" ";
					h = ch(h);
					y = false;
				} else if(t[i] != t[i - 1]){
					cout<<ch(h)<<" ";
					h = ch(h);
				} else {
					cout<<h<<" ";
				}
			}
			cout<<endl;
		} else {
			cout<<2<<endl;
			ll h = 1;
			cout<<"1 ";
			for(int i = 1 ; i < n ; i++){
				if(t[i] != t[i - 1]){
					cout<<ch(h)<<" ";
					h = ch(h);
				} else {
					cout<<h<<" ";
				}
			}
			cout<<endl;
		}
		v.clear();
		T--;
	}
	return 0;
}