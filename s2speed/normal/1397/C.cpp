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

ll a[100000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin>>n;
	if(n == 1){
		ll k;
		cin>>k;
		cout<<"1 1\n"<<0 - k<<"\n1 1\n0\n1 1\n0\n";
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	cout<<"1 "<<n - 1<<"\n";
	for(int i = 0 ; i < n - 1 ; i++){
		cout<<(a[i] % n) * (n - 1)<<" ";
		a[i] += (a[i] % n) * (n - 1);
	}
	cout<<"\n"<<n<<" "<<n<<"\n"<<0 - a[n - 1]<<"\n1 "<<n<<"\n";
	a[n - 1] = 0;
	for(int i = 0 ; i < n ; i++){
		cout<<0 - a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}