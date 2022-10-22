#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t , n , a[100000] , b[100000];
	cin>>t;
	while(t--){
		bool ans = true;
		ll f[2];
		f[0] = 1e6;
		f[1] = 1e6;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
			if(a[i] == 1 && f[0] == 1e6){
				f[0] = i;
			} else if(a[i] == -1 && f[1] == 1e6){
				f[1] = i;
			}
		}
		for(int i = 0 ; i < n ; i++){
			cin>>b[i];
			if(b[i] < a[i] && f[1] >= i){
				ans = false;
			} else if(b[i] > a[i] && f[0] >= i){
				ans = false;
			}
		}
		if(ans == false){
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
	}
	return 0;
}