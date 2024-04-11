#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e7 + 16 , maxN = 5e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> gh , sqfr;
ll pr[maxn];

void prime(){
	gh.set(); sqfr.set();
	memset(pr , -1 , sizeof(pr));
	for(ll i = 2 ; i < maxn ; i++){
		if(gh[i]){
			for(ll j = i ; j < maxn ; j += i){
				if(pr[j] == -1) pr[j] = i;
				gh[i] = false;
			}
			for(ll j = i * i ; j < maxn && i < 1e4 ; j += i * i){
				sqfr[j] = false;
			}
		}
	}
	return;
}

ll a[maxN] , g[maxn] , tv[maxN];
int cnt[maxn] , l[maxn];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(g , 0 , sizeof(g));
	memset(l , 0 , sizeof(l));
	ll ans = 0;
	prime();
	ll n;
	cin>>n;
	tv[0] = 1;
	for(ll i = 1 ; i <= n ; i++){
		tv[i] = tv[i - 1] << 1;
		if(tv[i] >= md) tv[i] -= md;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		ll res = 1 , h = pr[a[i]];
		while(a[i] != 1){
			a[i] /= h;
			if(a[i] % h != 0){
				res *= h;
				h = pr[a[i]];
			}
		}
		a[i] = res;
		cnt[a[i]]++;
	}
	for(ll i = 1 ; i < maxn ; i++){
		if(!sqfr[i]) continue;
		for(ll j = i << 1 ; j < maxn ; j += i){
			cnt[i] += cnt[j];
		}
	}
	for(ll i = maxn - 1 ; i ; i--){
		if(!sqfr[i]) continue;
		g[i] = tv[cnt[i]] - 1;
		for(ll j = i << 1 ; j < maxn ; j += i){
			g[i] -= g[j];
		}
		g[i] %= md; if(g[i] < 0) g[i] += md;
	}
	for(ll i = 2 ; i < maxn ; i++){
		if(!sqfr[i]) continue;
		ll h = i;
		v.clear();
		while(h > 1){
			v.push_back(pr[h]);
			h /= pr[h];
		}
		ll vs = sze(v) , lm = (1 << vs);
		for(ll mask = 0 ; mask < lm ; mask++){
			ll ch = 0 , h = 1;
			for(ll j = 0 ; j < vs ; j++){
				if(mask & (1 << j)){
					ch ^= 1;
					h *= v[j];
				}
			}
			l[i] += (1 - (ch << 1)) * cnt[h];
		}
	}
	for(ll i = 2 ; i < maxn ; i++){
		if(!sqfr[i]) continue;
		ll h = 1ll * g[i] * l[i] % md;
		ans += h;
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}