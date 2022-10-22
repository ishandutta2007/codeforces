#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll d , n , q;
	cin>>n>>d>>q;
	while(q--){
		ll x , y;
		cin>>x>>y;
		if((x + y) < d || (x + y) > 2 * n - d){
			cout<<"NO\n";
			continue;
		}
		if((x - y) < 0 - d || (x - y) > d){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
	}
	return 0;
}