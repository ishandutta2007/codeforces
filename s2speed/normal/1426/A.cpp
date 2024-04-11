#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(){
	ll n , x;
	cin>>n>>x;
	if(n <= 2){
		cout<<1<<"\n";
		return;
	}
	n -= 2;
	cout<<(n + x - 1) / x + 1<<"\n";
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