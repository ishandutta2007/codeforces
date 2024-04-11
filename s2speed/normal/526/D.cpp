#include<bits/stdc++.h>

using namespace std;

#define all(x) x.begin() , x.end()
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 16 , md = 2000000357 , p = 131;

bitset<maxn> ans , ch;
ll hs[maxn] , tv[maxn];

ll get_hash(ll l , ll r){
	ll res = hs[r - 1];
	if(l){
		res -= 1ll * hs[l - 1] * tv[r - l];
		res %= md; if(res < 0) res += md;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n , k;
	string s;
	cin>>n>>k>>s;
	tv[0] = 1;
	for(ll i = 1 ; i < n ; i++){
		tv[i] = 1ll * tv[i - 1] * p % md;
	}
	hs[0] = s[0];
	for(ll i = 1 ; i < n ; i++){
		hs[i] = 1ll * hs[i - 1] * p + s[i];
		hs[i] %= md;
	}
	for(ll i = 0 ; i < n ; i++){
		if(i % k != k - 1) continue;
		ll a , b , o = (i + 1) / k;
		a = get_hash(0 , o); b = get_hash(i - o + 1 , i + 1);
		if(a != b) continue;
		a = get_hash(0 , i - o + 1); b = get_hash(o , i + 1);
		if(a != b) continue;
		ch[i] = true;
	}
	ll j = -1;
	for(ll i = 0 ; i < n ; i++){
		if(ch[i]){
			ans[i] = true;
			j = i;
			continue;
		}
		if(j == -1) continue;
		ll a , b;
		a = get_hash(j + 1 , i + 1); b = get_hash(0 , i - j);
		if(a != b) continue;
		if(i - j > (j + 1) / k) continue;
		ans[i] = true;
	}
	for(ll i = 0 ; i < n ; i++) cout<<ans[i];
	cout<<'\n';
	return 0;
}