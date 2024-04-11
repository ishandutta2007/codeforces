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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 5e5 + 15 , md = 1e9 + 7 , inf = 1e15;

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

bitset<MAXN> gh , sq;
vector<ll> sf , pr[MAXN] , d[MAXN];

void prime(){
	gh.set(); sq.set();
	for(ll i = 2 ; i < MAXN ; i++){
		if(gh[i]){
			pr[i].push_back(i);
			for(ll j = 2 * i ; j < MAXN ; j += i){
				pr[j].push_back(i);
				gh[j] = false;
			}
			ll h = i * i;
			for(ll j = h ; j < MAXN ; j += h){
				sq[j] = false;
			}
		}
		if(sq[i]){
			sf.push_back(i);
		}
	}
	for(auto i : sf){
		ll ps = pr[i].size() , lm = 1 << ps;
		for(ll j = 1 ; j < lm ; j++){
			ll h = 1 , o = 1;
			for(ll q = 0 ; q < ps ; q++){
				if(o & j){
					h *= pr[i][q];
				}
				o <<= 1;
			}
			d[i].push_back(h);
		}
	}
	return;
}

ll a[MAXN] , z[MAXN] , n;
bitset<MAXN> mark;

ll np(ll x){
	ll res = 0;
	for(auto i : d[x]){
		res += z[i] * (pr[i].size() % 2 ? 1 : -1);
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(z , 0 , sizeof(z));
	prime();
	ll q , cnt = 0 , ans = 0;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		for(auto p : pr[a[i]]){
			ll h = p * p;
			while(a[i] % h == 0) a[i] /= p;
		}
	}
	while(q--){
		ll v;
		cin>>v; v--;
		ll h = cnt - np(a[v]);
		if(mark[v]){
			h -= (a[v] == 1);
			ans -= h;
			mark[v] = false;
			cnt--;
			for(auto i : d[a[v]]){
				z[i]--;
			}
		} else {
			ans += h;
			mark[v] = true;
			cnt++;
			for(auto i : d[a[v]]){
				z[i]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

/*

*/