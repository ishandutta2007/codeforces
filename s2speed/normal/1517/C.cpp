#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e2 + 16 , md = 1e9 + 7 , inf = 2e18;

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

ll a[maxn][maxn] , p[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(a , -1 , sizeof(a));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>p[i];
	}
	for(ll i = 0 ; i < n ; i++){
		ll x = i , y = i , cnt = 1;
		a[x][y] = p[i];
		while(cnt < p[i]){
			if(y > 0){
				if(a[x][y - 1] == -1){
					y--;
				} else {
					x++;
				}
			} else {
				x++;
			}
			a[x][y] = p[i];
			cnt++;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j <= i ; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}