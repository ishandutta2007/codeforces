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
	ll n , counter = 0;
	cin>>n;
	char a , b , c , d;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		if(i == 0){
			a = s[1];
		} else if(i == 1){
			b = s[0];
		}
		if(i == n - 2){
			c = s[n - 1];
		} else if(i == n - 1){
			d = s[n - 2];
		}
	}
	if(a == '1'){
		counter++;
	}
	if(b == '1'){
		counter++;
	}
	if(c == '0'){
		counter++;
	}
	if(d == '0'){
		counter++;
	}
	if(counter <= 2){
		cout<<counter<<"\n";
		if(a == '1'){
			cout<<"1 2\n";
		}
		if(b == '1'){
			cout<<"2 1\n";
		}
		if(c == '0'){
			cout<<n - 1<<" "<<n<<"\n";
		}
		if(d == '0'){
			cout<<n<<" "<<n - 1<<"\n";
		}
	} else {
		cout<<4 - counter<<"\n";
		if(a == '0'){
			cout<<"1 2\n";
		}
		if(b == '0'){
			cout<<"2 1\n";
		}
		if(c == '1'){
			cout<<n - 1<<" "<<n<<"\n";
		}
		if(d == '1'){
			cout<<n<<" "<<n - 1<<"\n";
		}
	}
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