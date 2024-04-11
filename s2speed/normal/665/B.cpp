#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 100 + 20;
 
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

vector<ll> v;

ll p[MAX_N];
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , k , m , ans = 0;
	cin>>n>>m>>k;
	for(int i = 0 ; i < k ; i++){
		ll h;
		cin>>h;
		p[h] = i + 1;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			ll h;
			cin>>h;
			ans += p[h];
			for(int q = 1 ; q <= k ; q++){
				p[q] += (p[q] < p[h]);
			}
			p[h] = 1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}