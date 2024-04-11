#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t , n;
	cin>>t;
	while(t > 0){
		vector<ll> a , b;
		ll h;
		cin>>n;
		if(n == 1){
			cin>>h;
			if(h % 2 == 1){
				cout<<-1<<endl;
			} else {
				cout<<1<<endl;
				cout<<1<<endl;
			}
		}
		else {
			for(int i = 1 ; i <= n ; i++){
				cin>>h;
				if(h % 2 == 0){
					a.push_back(i);
				} else {
					b.push_back(i);
				}
			}
			if(a.size() > 0){
				cout<<1<<endl;
				cout<<a[0]<<endl;
			} else {
				cout<<2<<endl;
				cout<<b[0]<<" "<<b[1]<<endl;
			}
		}
		a.clear();
		b.clear();
		t--;
	}
	return 0;
}