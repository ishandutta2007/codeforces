#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

int ds[260] , dm[260] , a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n , k;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	iota(ds , ds + 256 , 0);
	iota(dm , dm + 256 , 0);
	for(int i = 0 ; i < n ; i++){
		int h = a[i] , m = dm[ds[h]];
		while(h > -1){
			int o = ds[h];
			if(m - o >= k) break;
			h = o - 1;
		}
		h++;
		for(int j = m ; j >= h ; j--){
			ds[j] = h;
		}
		dm[h] = m;
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ds[a[i]]<<' ';
	}
	cout<<'\n';
	return 0;
}