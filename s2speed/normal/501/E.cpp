#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

bitset<maxn> p;
ll cnt[maxn] , tnc[maxn] , a[maxn] , st = -1 , mt = -1 , h = -1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		cnt[a[i]]++;
	}
	ll c = 0;
	for(ll i = 0 ; i < n ; i++){
		p[i] = (a[i] == a[n - i - 1]);
		c += cnt[i] & 1;
	}
	if(n & 1){
		ll i = n >> 1;
		p[i] = cnt[a[i]] & 1;
	}
	if(c > 1){
		cout<<"0\n";
		return 0;
	}
	if(p.count() == n){
		cout<<1ll * n * (n + 1) / 2<<'\n';
		return 0;
	}
	memset(tnc , 0 , sizeof(tnc));
	ll lm = n >> 1;
	for(ll i = 0 ; i < lm ; i++){
		tnc[a[i]]++;
		if(tnc[a[i]] > (cnt[a[i]] >> 1)){
			h = i;
			break;
		}
		if(!p[i] && st == -1){
			st = i;
		}
	}
	if(st == -1) st = lm;
	if(h == -1) h = lm;
	lm = (n - 1) >> 1;
	memset(tnc , 0 , sizeof(tnc));
	ll ans = h + 1;
	for(ll i = n - 1 ; i > lm ; i--){
		tnc[a[i]]++;
		if(tnc[a[i]] > (cnt[a[i]] >> 1)) break;
		if(n - i <= st){
			ans += h + 1;
		} else {
			ans += st + 1;
		}
	}
	for(ll i = lm ; i >= 0 ; i--){
		if(!p[i]){
			mt = lm - i;
			break;
		}
	}
	lm = n >> 1;
	ans += 2ll * (st + 1) * mt * (h == lm);
	cout<<ans<<'\n';
	return 0;
}