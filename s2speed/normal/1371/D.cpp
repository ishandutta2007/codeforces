#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll ans[300][300];

void solve(ll n , ll k){
	ll x = 0 , y = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			ans[i][j] = 0;
		}
	}
	for(int i = 0 ; i < n && k > 0 ; i++){
		x = i;
		y = 0;
		for(int j = 0 ; j < n && k > 0 ; j++){
			ans[y][x] = 1;
			x++;
			y++;
			y %= n;
			x %= n;
			k--;	
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , k;
		cin>>n>>k;
		if(k % n == 0){
			cout<<"0\n";
		} else {
			cout<<"2\n";
		}
		solve(n , k);
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cout<<ans[i][j];
			}
			cout<<"\n";
		}
	}
	return 0;
}