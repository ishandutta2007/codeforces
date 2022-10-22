#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e3 + 16 , md = 1e9 + 7 , inf = 2e18;

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

unordered_map<ll , ll> cnt;
string s[maxn];

ll n , k , t[30];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	t[0] = 1;
	for(ll i = 1 ; i < 30 ; i++){
		t[i] = 3ll * t[i - 1];
	}
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>s[i];
		for(ll j = 0 ; j < k ; j++){
			if(s[i][j] == 'S') s[i][j] = '0';
			if(s[i][j] == 'E') s[i][j] = '1';
			if(s[i][j] == 'T') s[i][j] = '2';
		}
		ll h = 0;
		for(ll j = 0 ; j < k ; j++){
			h += 1ll * (s[i][j] - '0') * t[j];
		}
		if(cnt.count(h)) cnt[h]++;
		else cnt[h] = 1;
	}
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i + 1 ; j < n ; j++){
			ll h = 0;
			for(ll q = 0 ; q < k ; q++){
				if(s[i][q] == s[j][q]){
					h += 1ll * (s[i][q] - '0') * t[q];
				} else if(s[i][q] == '0'){
					if(s[j][q] == '1') h += (t[q] << 1);
					else h += t[q];
				} else {
					if(s[i][q] == '1'){
						if(s[j][q] == '0') h += (t[q] << 1);
					} else {
						if(s[j][q] == '0') h += t[q];
					}
				}
			}
			ans += cnt[h];
		}
	}
	ans /= 3;
	cout<<ans<<'\n';
	return 0;
}