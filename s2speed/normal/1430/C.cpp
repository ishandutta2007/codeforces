#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

void solve(){
	ll n;
	cin>>n;
	if(n == 2){
		cout<<"2\n1 2\n";
		return;
	} else {
		cout<<"2\n";
		cout<<n<<" "<<n - 2<<"\n"<<n - 1<<" "<<n - 1<<"\n";
		for(int i = n - 1 ; i >= 3 ; i--){
			cout<<i<<" "<<i - 2<<"\n";
		}
	}
	return;
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