#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 3e5 + 20;
 
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
 
ll p[MAX_N] , f[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , ans = 1;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		p[h] = i;
		f[i] = -1;
	}
	for(int i = 0 ; i < m ; i++){
		ll a , b;
		cin>>a>>b; a--; b--;
		a = p[a];
		b = p[b];
		if(a < b){
			swap(a , b);
		}
		f[a] = max(f[a] , b);
	}
	for(int i = 1 ; i < n ; i++){
		f[i] = max(f[i] , f[i - 1]);
		ans += i - f[i];
	}
	cout<<ans<<'\n';
	return 0;
}