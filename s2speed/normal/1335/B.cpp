#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t--){
		string ans;
		ll a , b;
		cin>>n>>a>>b;
		for(ll i = 0 ; i < a ; i++){
			ans += min(i , b - 1) + 97;
			cout<<ans[i];
		}
		for(int i = a ; i < n ; i++){
			cout<<ans[i % a];
		}
		cout<<endl;
		ans.clear();
	}
	return 0;
}