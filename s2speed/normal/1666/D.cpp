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

const ll maxn = 30 + 17 , md = 1e9 + 7 , inf = 2e16;

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
ll cnt[27];

void solve(){
	memset(cnt , 0 , sizeof(cnt));
	cin>>s>>t; h.clear();
	ll n = sze(s) , m = sze(t);
	for(ll i = 0 ; i < n ; i++){
		cnt[s[i] - 'A']++;
	}
	for(ll j = 0 ; j < m ; j++){
		cnt[t[j] - 'A']--;
		if(cnt[t[j] - 'A'] == -1){
			cout<<"NO\n";
			return;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		ll c = s[i] - 'A';
		if(cnt[c]){
			cnt[c]--;
			continue;
		}
		h += s[i];
	}
	cout<<(t == h ? "YES\n" : "NO\n");
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}