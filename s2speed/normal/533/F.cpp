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

const ll maxn = 2e5 + 17 , md = 2000000357 , inf = 2e16;

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

string s , t;
ll a[maxn] , b[maxn];
bitset<maxn> x[26] , y[26];
ll mt[26] , hs[26];
vector<pll> v , u;
vector<ll> ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , tv = 1;
	cin>>n>>m>>s>>t;
	for(ll i = 1 ; i < m ; i++){
		tv <<= 1; tv -= (tv > md) * md;
	}
	for(ll i = 0 ; i < n ; i++){
		a[i] = s[i] - 'a';
		x[a[i]][i] = true;
	}
	for(ll i = 0 ; i < m ; i++){
		b[i] = t[i] - 'a';
		y[b[i]][i] = true;
	}
	for(ll j = 0 ; j < 26 ; j++){
		ll h = 0;
		for(ll i = 0 ; i < m ; i++){
			h <<= 1; h += y[j][i]; h %= md;
		}
		u.push_back({h , j});
	}
	sort(all(u) , greater<pll>());
	for(ll j = 0 ; j < 26 ; j++){
		for(ll i = 0 ; i < m ; i++){
			hs[j] <<= 1; hs[j] += x[j][i]; hs[j] %= md;
		}
	}
	for(ll i = m ; true ; i++){
		v.clear();
		memset(mt , -1 , sizeof(mt));
		for(ll j = 0 ; j < 26 ; j++){
			v.push_back({hs[j] , j});
		}
		sort(all(v) , greater<pll>());
		bool f = true;
		for(ll j = 0 ; j < 26 ; j++){
			if(v[j].first != u[j].first){
				f = false;
				break;
			}
			if(!v[j].first) break;
			ll c = v[j].second , d = u[j].second;
			if(mt[c] == -1 && mt[d] == -1){
				mt[c] = d; mt[d] = c;
				continue;
			}
			if(mt[c] != d || mt[d] != c){
				f = false;
				break;
			}
		}
		if(f){
			ans.push_back(i - m);
		}
		if(i == n) break;
		for(ll j = 0 ; j < 26 ; j++){
			hs[j] -= tv * x[j][i - m];
			hs[j] *= 2; hs[j] += x[j][i];
			hs[j] %= md; hs[j] += (hs[j] < 0) * md;
		}
	}
	cout<<sze(ans)<<'\n';
	for(auto i : ans){
		cout<<i + 1<<' ';
	}
	cout<<'\n';
	return 0;
}