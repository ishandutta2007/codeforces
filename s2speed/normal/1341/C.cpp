#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		bool ans = true;
		ll n , a , h;
		cin>>n>>a;
		for(int i = 1 ; i < n ; i++){
			cin>>h;
			if(h >= a + 2){
				ans = false;
			}
			a = h;
		}
		if(ans == true){
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}
	return 0;
}