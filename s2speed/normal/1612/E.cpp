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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll cnt[maxn][22] , sf[maxn][22] , ps[maxn][22];
vector<pll> v[22];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll m , k;
		cin>>m>>k;
		cnt[m][k]++;
	}
	for(ll i = 0 ; i < maxn ; i++){
		ps[i][0] = cnt[i][0];
		for(ll j = 1 ; j < 22 ; j++){
			ps[i][j] = ps[i][j - 1] + j * cnt[i][j];
		}
		sf[i][21] = cnt[i][21];
		for(ll j = 20 ; j > -1 ; j--){
			sf[i][j] = sf[i][j + 1] + cnt[i][j];
		}
	}
	db ans = 0;
	ll ind = -1;
	for(ll j = 1 ; j <= 20 ; j++){
		for(ll i = 0 ; i < maxn ; i++){
			ll h = ps[i][j - 1] + 1ll * j * sf[i][j];
			v[j].push_back({h , i});
		}
		sort(all(v[j]) , greater<pll>());
		ll h = 0;
		for(ll i = 0 ; i < j ; i++){
			h += v[j][i].first;
		}
		db res = (db)h / j;
		if(res > ans){
			ans = res;
			ind = j;
		}
	}
	cout<<ind<<'\n';
	for(ll i = 0 ; i < ind ; i++){
		cout<<v[ind][i].second<<' ';
	}
	cout<<'\n';
	return 0;
}