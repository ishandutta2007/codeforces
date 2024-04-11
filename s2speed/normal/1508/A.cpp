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

ll n;
string a , b , c , s , t , ans;
vector<ll> v , u;

void hum(char c){
	ll h = n , lm = h << 1;
	for(ll i = 0 ; i < lm && h ; i++){
		if(s[i] == c){
			v.push_back(i);
			h--;
		}
	}
	h = n;
	for(ll i = 0 ; i < lm && h ; i++){
		if(t[i] == c){
			u.push_back(i);
			h--;
		}
	}
	ll x = 0 , y = 0;
	for(ll i = 0 ; i < n ; i++){
		while(x < v[i]){
			ans += s[x++];
		}
		while(y < u[i]){
			ans += t[y++];
		}
		ans += s[x++];
		y++;
	}
	while(x < lm){
		ans += s[x++];
	}
	while(y < lm){
		ans += t[y++];
	}
	return;
}

void solve(){
	v.clear(); u.clear(); ans.clear();
	ll cnt[] = {0 , 0 , 0};
	cin>>n>>a>>b>>c;
	ll lm = 2 * n;
	for(ll i = 0 ; i < lm ; i++){
		cnt[0] += (a[i] ^ '0');
		cnt[1] += (b[i] ^ '0');
		cnt[2] += (c[i] ^ '0');
	}
	if(cnt[0] <= n && cnt[1] <= n){
		s = a; t = b;
		hum('0');
	} else if(cnt[0] <= n && cnt[2] <= n){
		s = a; t = c;
		hum('0');
	} else if(cnt[1] <= n && cnt[2] <= n){
		s = b; t = c;
		hum('0');
	} else if(cnt[0] > n && cnt[1] > n){
		s = a; t = b;
		hum('1');
	} else if(cnt[0] > n && cnt[2] > n){
		s = a; t = c;
		hum('1');
	} else if(cnt[1] > n && cnt[2] > n){
		s = b; t = c;
		hum('1');
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