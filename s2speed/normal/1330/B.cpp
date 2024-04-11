#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n , h , p1[200000] , p2[200000] , a[200000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t > 0){
		vector<ll> v;
		bool ch = true , p[2];
		for(int i = 1 ; i < n ; i++){
			p1[i] = 0;
			p2[i] = 0;
		}
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
			p2[a[i]]++;
			v.push_back(a[i]);
		}
		sort(v.begin() , v.end());
		reverse(v.begin() , v.end());
		if(v[0] < (n + 1) / 2){
			cout<<0<<endl;
		} else {
			for(int i = 0 ; i < n - v[0] ; i++){
				p1[a[i]]++;
				p2[a[i]]--;
			}
			for(int i = 1 ; i <= n - v[0] && ch == true ; i++){
				if(p1[i] != 1){
					ch = false;
				}
			}
			for(int i = 1 ; i <= v[0] && ch == true ; i++){
				if(p2[i] != 1){
					ch = false;
				}
			}
			p[0] = ch;
			ch = true;
			for(int i = n - v[0] ; i < v[0] ; i++){
				p1[a[i]]++;
				p2[a[i]]--;
			}
			for(int i = 1 ; i <= n - v[0] && ch == true ; i++){
				if(p2[i] != 1){
					ch = false;
				}
			}
			for(int i = 1 ; i <= v[0] && ch == true ; i++){
				if(p1[i] != 1){
					ch = false;
				}
			}
			p[1] = ch;
			if(p[0] == true && p[1] == true){
				if(n % 2 == 0 && v[0] == n / 2){
					cout<<1<<endl;
					cout<<n / 2<<" "<<n / 2<<endl;
				} else {
					cout<<2<<endl;
					cout<<n - v[0]<<" "<<v[0]<<endl;
					cout<<v[0]<<" "<<n - v[0]<<endl;
				}
			} else if(p[0] == false && p[1] == false){
				cout<<0<<endl;
			} else {
				cout<<1<<endl;
				if(p[0] == true){
					cout<<n - v[0]<<" "<<v[0]<<endl;	
				} else {
					cout<<v[0]<<" "<<n - v[0]<<endl;
				}
			}
		}
		v.clear();
		t--;
	}
	return 0;
}