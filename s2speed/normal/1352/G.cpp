#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n <= 3){
			cout<<-1<<endl;
			continue;
		}
		if(n == 4){
			cout<<"3 1 4 2\n";
			continue;
		}
		for(int i = 1 ; i <= n ; i += 2){
			cout<<i<<" ";
		}
		if(n % 2 == 0){
			cout<<n - 4<<" "<<n<<" "<<n - 2<<" ";
			for(int i = n - 6 ; i > 0 ; i -= 2){
				cout<<i<<" ";
			}
		} else {
			cout<<n - 3<<" "<<n - 1<<" ";
			for(int i = n - 5 ; i > 0 ; i -= 2){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}