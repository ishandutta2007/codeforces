#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		bool c = false;
		ll h , n , m;
		cin>>h>>n>>m;
		if(m == 1 && h > 10){
			cout<<"NO\n";
		} else {
			while(n--){
				if(h < 20){
					break;
				}
				if(h <= m * 10){
					cout<<"YES\n";
					c = true;
					break;
				}
				h /= 2;
				h += 10;
			}
			if(c == true){
				continue;
			}
			if(h <= m * 10){
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		}
	}
	return 0;
}