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

const ll maxn = 1e2 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

char a[maxn][maxn];
string s[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , ans;
	cin>>n>>m; ans = m;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
		}
	}
	for(ll j = 0 ; j < m ; j++){
		bool f = true;
		for(ll i = 1 ; i < n ; i++){
			if(s[i] == s[i - 1]){
				f &= (a[i][j] >= a[i - 1][j]);
			}
		}
		if(f){
			ans--;
			for(ll i = 0 ; i < n ; i++){
				s[i] += a[i][j];
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}