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

const ll maxn = 5e3 + 17 , md = 2000000357 , P = 131 , inf = 2e16;

string s , t;
ll hs[maxn] , ht[maxn] , tv[maxn] , st[maxn];

ll get_hash(ll l , ll r){
	ll res = hs[r - 1];
	if(l){
		res -= hs[l - 1] * tv[r - l] % md;
		res += (res < 0) * md;
	}
	return res;
}

ll get_hath(ll l , ll r){
	ll res = ht[r - 1];
	if(l){
		res -= ht[l - 1] * tv[r - l] % md;
		res += (res < 0) * md;
	}
	return res;
}

void solve(){
	ll n , m;
	cin>>m>>n>>t>>s;
	ll pt = 0;
	st[0] = 0;
	for(ll i = 0 ; i < m && pt < n ; i++){
		if(t[i] == s[pt]){
			st[++pt] = i + 1;
		}
	}
	if(pt < n){
		cout<<"-1\n";
		return;
	}
	hs[0] = s[0];
	for(ll i = 1 ; i < n ; i++){
		hs[i] = (hs[i - 1] * P + s[i]) % md;
	}
	ht[0] = t[0];
	for(ll i = 1 ; i < m ; i++){
		ht[i] = (ht[i - 1] * P + t[i]) % md;
	}
	ll res = m;
	for(ll i = 0 ; i < n ; i++){
		ll x = st[i];
		for(ll j = 1 ; i + j <= n ; j++){
			while(x + j <= m){
				if(get_hash(i , i + j) == get_hath(x , x + j)){
					break;
				}
				x++;
			}
			if(x + j > m) break;
			ll h = m - j + x - i + (x > 0);
			res = min(res , h);
		}
	}
	cout<<res<<'\n';
	return;
}

/*
1
9 4
aaaaaaaaa
aaaa
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = tv[i - 1] * P % md;
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}