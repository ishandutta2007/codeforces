#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t , n;
	cin>>t;
	while(t--){
		ll m = 0 , a , aa;
		cin>>n;
		cin>>a;
		for(int i = 1 ; i < n ; i++){
			cin>>aa;
			if(aa < a){
				ll y = 1;
				for(ll j = 0 ; ; j++ , y *= 2){
					if(aa == a - 1){
						m = max(m , j + 1);
						break;
					} else if(aa >= a){
						m = max(m , j);
						break;
					}
					aa += y;
				}
			} else{
				a = aa;
			}
		}
		cout<<m<<endl;
	}
	return 0;
}