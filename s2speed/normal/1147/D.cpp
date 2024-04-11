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

const ll maxn = 2e3 + 16 , md = 998244353 , inf = 2e16;

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

ll ds[maxn] , dsz[maxn];
vector<ll> dsu[maxn];
bitset<maxn> dc;

bool merge(ll v , ll u , bool w){
	ll dv = ds[v], du = ds[u];
	bool h = !dc[v] ^ dc[u] ^ w;
	if(dv == du){
		return h;
	}
	if(dsz[dv] < dsz[du]) swap(dv , du);
	for(auto i : dsu[du]){
		ds[i] = dv;
		dsu[dv].push_back(i);
		dc[i] = dc[i] ^ h;
	}
	dsz[dv] += dsz[du];
	dsz[du] = 0; dsu[du].clear();
	return false;
}

ll tv[maxn] , f[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = tv[i - 1] << 1;
		tv[i] -= (tv[i] >= md) * md;
	}
	ll n , ans = 0;
	string s;
	cin>>s; n = sze(s);
	reverse(all(s));
	for(ll j = 1 ; j < n ; j++){
		for(ll i = 0 ; i < n + j ; i++){
			ds[i] = i;
			dsz[i] = 1;
			dsu[i].clear(); dsu[i].push_back(i);
			dc[i] = 0;
		}
		bool dead = false;
		ll res = 0;
		memset(f , -1 , sizeof(f));
		for(ll i = 0 ; i < n ; i++){
			if(n - i <= i) break;
			if(merge(i , n - i - 1 , 1)){
				dead = true;
				break;
			}
		}
		for(ll i = 0 ; i < j ; i++){
			if(j - i <= i) break;
			if(merge(n + i , n + j - i - 1 , 1)){
				dead = true;
				break;
			}
		}
		for(ll i = 0 ; i < j ; i++){
			if(s[i] == '?') continue;
			bool h = s[i] ^ '1';
			if(merge(i , n + i , h)){
				dead = true;
				break;
			}
		}
		f[n + j - 1] = 1;
		for(ll i = j ; i < n ; i++){
			if(s[i] == '?') continue;
			f[i] = s[i] ^ '0';
		}
		for(ll i = 0 ; i < n + j ; i++){
			if(!dsz[i]) continue;
			ll h = -1;
			for(auto v : dsu[i]){
				if(f[v] != -1){
					ll c = f[v] ^ dc[v];
					if(h != -1 && h ^ c){
						dead = true;
						break;
					}
					h = c;
				}
			}
			if(h == -1) res++;
		}
		if(dead) continue;
		ans += tv[res];
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}