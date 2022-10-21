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

const ll maxn = 1e5 + 16 , maxsq = 350 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , c[maxn] , nx[maxn] , pr[maxn] , p[maxn] , mx[maxn] , ls[maxn] , sz[maxsq];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(mx , -1 , sizeof(mx));
	ll n , sq;
	cin>>n; n += 2; sq = min(340ll , n);
	for(ll i = 2 ; i < n ; i++){
		cin>>a[i]>>c[i];
		p[a[i]] = i - 1;
	}
	nx[n] = 0;
	pr[0] = n;
	pr[n] = nx[0] = -1;
	mx[0] = n;
	for(ll i = 2 ; i < sq ; i++){
		ll h = 0 , cnt = c[i] + 1;
		while(cnt){
			if(h > a[i]) break;
			cnt--;
			h = pr[h];
		}
		ll v = nx[h];
		pr[v] = nx[h] = a[i];
		pr[a[i]] = h; nx[a[i]] = v;
	}
	ls[0] = 0; mx[0] = n;
	sz[0] = sq;
	for(ll i = sq ; i < n ; i++){
		ll cnt = c[i] + 1;
		for(ll j = i / sq - 1 ; ~j ; j--){
			if(cnt < sz[j]){
				ll h = ls[j];
				while(cnt){
					if(h > a[i]) break;
					cnt--;
					h = pr[h];
				}
				ll v = nx[h];
				pr[v] = nx[h] = a[i];
				pr[a[i]] = h; nx[a[i]] = v;
				sz[j]++;
				mx[j] = max(mx[j] , a[i]);
				if(h == ls[j]) ls[j] = a[i];
				break;
			}
			if(mx[j] > a[i]){
				ll h = ls[j];
				while(cnt){
					if(h > a[i]) break;
					cnt--;
					h = pr[h];
				}
				ll v = nx[h];
				pr[v] = nx[h] = a[i];
				pr[a[i]] = h; nx[a[i]] = v;
				sz[j]++;
				mx[j] = max(mx[j] , a[i]);
				if(h == ls[j]) ls[j] = a[i];
				break;
			}
			cnt -= sz[j];
		}
		if(i % sq == sq - 1){
			ll h = n , k = 0;
			for(ll j = 0 ; j <= i ; j++){
				mx[k] = max(mx[k] , h);
				if(j % sq == sq - 1){
					ls[k] = h;
					sz[k++] = sq;
				}
				h = nx[h];
			}
		}
	}
	ll h = n;
	for(ll i = 2 ; i < n ; i++){
		h = nx[h];
		cout<<p[h]<<' ';
	}
	cout<<'\n';
	return 0;
}