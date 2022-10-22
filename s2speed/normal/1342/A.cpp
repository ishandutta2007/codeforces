#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t--){
		ll a , b , x , y , ans;
		cin>>x>>y>>a>>b;
		ans = min(x , y) * min(2 * a , b);
		ans += (max(x , y) - min(x , y)) * a;
		cout<<ans<<endl;
	}
	return 0;
}