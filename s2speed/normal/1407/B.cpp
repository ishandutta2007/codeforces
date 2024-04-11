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

ll b[1000];
vector<ll> a;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , g[2] , q;
		cin>>n;
		a.resize(n);
		g[0] = 0;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		sort(a.begin() , a.end() , greater<ll>());
		b[0] = a[0];
		q = b[0];
		a[0] = 0;
		for(int j = 1 ; j < n ; j++){
			for(int i = 0 ; i < n ; i++){
				if(a[i] == 0){
					continue;
				}
				ll p = __gcd(q , a[i]);
				if(g[0] < p){
					g[0] = p;
					g[1] = i;
				}
			}
			b[j] = a[g[1]];
			q = g[0];
			a[g[1]] = 0;
			g[0] = 0;
		}
		for(int i = 0 ; i < n ; i++){
			cout<<b[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}