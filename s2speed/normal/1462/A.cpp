#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

int a[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0 ; i < n ; i += 2){
			cin>>a[i];
		}
		for(int i = n - n % 2 - 1 ; i > 0 ; i -= 2){
			cin>>a[i];
		}
		for(int i = 0 ; i < n ; i++){
			cout<<a[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}