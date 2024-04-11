#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e6 + 15 , MAXS = 450 , md = 1e9 + 7 , inf = 1e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

ll a[MAXN] , cnt[MAXN] , cur = 0 , ans[MAXN];
vector<plll> q[MAXS];

void upd(ll i , ll k){
	i = a[i];
	ll o = 1ll * cnt[i] * cnt[i] * i , h;
	cur -= o;
	cnt[i] += k;
	h = 1ll * cnt[i] * cnt[i] * i;
	cur += h;
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	memset(cnt , 0 , sizeof(cnt));
	ll n , m , sq , qs;
	cin>>n>>m; sq = sqrt(n); qs = (n + sq - 1) / sq;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < m ; i++){
		ll l , r , t;
		cin>>l>>r; l--;
		t = l / sq;
		q[t].push_back({{r , l} , i});
	}
	ll l = 0 , r = 0;
	for(ll j = 0 ; j < qs ; j++){
		sort(all(q[j]));
		for(auto y : q[j]){
			pll p = y.first;
			ll i = y.second , lx = p.second , rx = p.first;
			while(l < lx){
				upd(l++ , -1);
			}
			while(l > lx){
				upd(--l , 1);
			}
			while(r < rx){
				upd(r++ , 1);
			}
			while(r > rx){
				upd(--r , -1);
			}
			ans[i] = cur;
		}
	}
	for(ll i = 0 ; i < m ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

/*

*/