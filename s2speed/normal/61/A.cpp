#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 2e5 + 20;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string a , b , ans;
	cin>>a>>b;
	ll n = a.size();
	for(int i = 0 ; i < n ; i++){
		if(a[i] == b[i]){
			ans += '0';
		} else {
			ans += '1';
		}
	}
	cout<<ans<<'\n';
	return 0;
}