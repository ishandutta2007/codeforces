#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(){
	double n , ans = 0 , h;
	cin>>n;
	h = floor(sqrt(n));
	ans = h + ceil(n / h) - 2;
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}