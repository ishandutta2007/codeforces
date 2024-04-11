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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e12;

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
ll cnt[maxn];

void prime(){
	memset(cnt , 0 , sizeof(cnt));
	gh.set();
	sqfr.set();
	for(ll i = 2 ; i < maxn ; i++){
		if(!gh[i]) continue;
		for(ll j = i ; j < maxn ; j += i){
			cnt[j]++;
			gh[j] = false;
		}
		for(ll j = 1ll * i * i ; j < maxn ; j += i * i){
			sqfr[j] = false;
		}
	}
	return;
}

ll a[maxn] , b[maxn] , c[maxn] , ans[maxn];
vector<pll> u;
vector<ll> v[2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	prime();
	ll n , cur = 0;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i]; c[i] = a[i];
	}
	for(ll i = 1 ; i <= n ; i++){
		cin>>b[i];
	} b[1] = 0;
	for(ll i = 1 ; i <= n ; i++){
		ll h = b[i] - c[i];
		cur += abs(h);
		for(ll j = i ; j <= n ; j += i) c[j] += h;
		if(sqfr[i]) v[cnt[i] & 1].push_back(h);
	}
	ll pr = 0 , q;
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		ll x;
		cin>>x;
		u.push_back({x , i});
	}
	v[0].push_back(-inf); v[1].push_back(inf);
	sort(all(u)); sort(all(v[0])); sort(all(v[1]));
	ll v0 = sze(v[0]) , v1 = sze(v[1]) , x[] = {v0 - 1 , 0};
	while(v[0][x[0]] >= 0) x[0]--;
	while(v[1][x[1]] <= 0) x[1]++;
	wall;
	for(ll e = 0 ; e < q ; e++){
		ll k = u[e].first;
		cur += 1ll * (x[1] + v0 - x[0] - 1) * (k - pr);
//		cout<<cur<<'\n';
		while(v[0][x[0]] >= -k){
			ll h = k + v[0][x[0]] + (pr + v[0][x[0]]);
			cur += h;
			x[0]--;
		}
//		cout<<cur<<'\n';
		while(v[1][x[1]] <= k){
			ll h = k - v[1][x[1]] + (pr - v[1][x[1]]);
			cur += h;
			x[1]++;
		}
//		cout<<cur<<'\n';
		cur -= 1ll * (v1 - x[1] - 1 + x[0]) * (k - pr);
//		cout<<cur<<'\n';
		ans[u[e].second] = cur;
		pr = k;
	} 
	for(ll i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}

/*
2
3 7
-1 5
1
3
*/