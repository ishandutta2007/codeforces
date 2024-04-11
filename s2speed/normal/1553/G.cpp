#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> gh;
vector<ll> pr[maxn];

void prime(){
	gh.set();
	for(ll i = 2 ; i < maxn ; i++){
		if(gh[i]){
			for(ll j = i ; j < maxn ; j += i){
				pr[j].push_back(i);
				gh[j] = false;
			}
		}
	}
	return;
}

ll ds[maxn];

ll dsu(ll v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(ll v , ll u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return;
}

ll a[maxn];
set<pll> s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	iota(ds , ds + maxn - 1 , 0);
	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		ll h , ps , x;
		cin>>h; a[i] = h;
		ps = sze(pr[h]);
		for(ll j = 1 ; j < ps ; j++){
			merge(pr[h][j - 1] , pr[h][j]);
		}
	}
	for(ll i = 0 ; i < n ; i++){
		ll h = a[i] + 1 , ps , x = dsu(pr[a[i]][0]);
		ps = sze(pr[h]);
		for(ll j = 0 ; j < ps ; j++){
			s.insert({x , dsu(pr[h][j])});
			for(ll k = j + 1 ; k < ps ; k++){
				s.insert({dsu(pr[h][j]), dsu(pr[h][k])});
			}
		}
	}
	for(ll e = 0 ; e < q ; e++){
		ll i , j , x , y;
		cin>>i>>j; i--; j--;
		x = dsu(pr[a[i]][0]); y = dsu(pr[a[j]][0]);
		if(x == y){
			cout<<"0\n";
			continue;
		}
		if(s.count({x , y}) || s.count({y , x})){
			cout<<"1\n";
			continue;
		}
		cout<<"2\n";
	}
	return 0;
}