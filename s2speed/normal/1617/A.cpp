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

string s , t , h;
ll cnt[26];

void solve(){
	h.clear();
	cin>>s>>t;
	ll n = sze(s);
	bool a;
	memset(cnt , 0 , sizeof(cnt));
	for(ll i = 0 ; i < n ; i++){
		cnt[s[i] - 'a']++;
	}
	a = cnt[0];
	while(cnt[0]){
		h += 'a';
		cnt[0]--;
	}
	if(t == "abc" && a){
		while(cnt[2]){
			h += 'c';
			cnt[2]--;
		}
		while(cnt[1]){
			h += 'b';
			cnt[1]--;
		}
	} else {
		while(cnt[1]){
			h += 'b';
			cnt[1]--;
		}
		while(cnt[2]){
			h += 'c';
			cnt[2]--;
		}
	}
	for(ll i = 3 ; i < 26 ; i++){
		char c = i + 'a';
		while(cnt[i]){
			h += c;
			cnt[i]--;
		}
	}
	cout<<h<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}