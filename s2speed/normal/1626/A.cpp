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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll cnt[27];
string s , ans;
vector<ll> v , u;

void solve(){
	v.clear(); u.clear(); ans.clear();
	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>s; n = sze(s);
	for(ll i = 0 ; i < n ; i++){
		cnt[s[i] - 'a']++;
	}
	for(ll i = 0 ; i < 26 ; i++){
		if(cnt[i] == 1){
			u.push_back(i);
		}
		if(cnt[i] == 2){
			v.push_back(i);
		}
	}
	for(auto i : v){
		ans += 'a' + i;
	}
	for(auto i : u){
		ans += 'a' + i;
	}
	for(auto i : v){
		ans += 'a' + i;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}