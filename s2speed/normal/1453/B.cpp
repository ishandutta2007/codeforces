#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2e5 + 20;
 
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

ll a[MAX_N];

void solve(){
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll m = 0 , sum = 0;
	for(int i = 1 ; i < n - 1 ; i++){
		sum += max(a[i] - a[i - 1] , a[i - 1] - a[i]);
		if(a[i] > a[i - 1] && a[i] > a[i + 1]){
			m = max(m , 2 * (a[i] - max(a[i - 1] , a[i + 1])));
		}
		if(a[i] < a[i - 1] && a[i] < a[i + 1]){
			m = max(m , 2 * (min(a[i - 1] , a[i + 1]) - a[i]));
		}
	}
	m = max(m , max(a[1] - a[0] , a[0] - a[1]));
	m = max(m , max(a[n - 1] - a[n - 2] , a[n - 2] - a[n - 1]));
	sum += max(a[n - 1] - a[n - 2] , a[n - 2] - a[n - 1]);
	cout<<sum - m<<'\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}