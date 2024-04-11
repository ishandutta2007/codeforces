#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 5e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll cnt[26] , fnt[maxn] , nt[maxn] , pr[maxn] , a[maxn];
vector<ll> v , u , p[26];

void solve(){
	memset(cnt , 0 , sizeof(cnt));
	memset(fnt , 0 , sizeof(fnt));
	v.clear(); u.clear();
	for(ll j = 0 ; j < 26 ; j++) p[j].clear();
	ll n;
	string s;
	cin>>s; n = sze(s);
	for(ll i = n - 1 ; i >= 0 ; i--){
		a[i] = s[i] - 'a';
		cnt[a[i]]++;
		if(cnt[a[i]] == 1){
			v.push_back(a[i]);
		}
	}
	ll vs = sze(v);
	for(ll i = 0 ; i < vs ; i++){
		ll d = vs - i , c = v[i];
		if(cnt[c] % d != 0){
			cout<<"-1\n";
			return;
		}
		fnt[c] = cnt[c] / d;
	}
	ll cn = 0;
	memset(cnt , 0 , sizeof(cnt));
	for(ll i = 0 ; i < n && cn < vs ; i++){
		if(cnt[a[i]] == fnt[a[i]]){
			cout<<"-1\n";
			return;
		}
		cnt[a[i]]++;
		if(cnt[a[i]] == fnt[a[i]]) cn++;
		u.push_back(a[i]);
		p[a[i]].push_back(i);
	}
	ll us = sze(u);
	for(ll i = 0 ; i < us ; i++){
		nt[i] = i + 1;
		pr[i] = i - 1;
	}
	reverse(all(v));
	pr[0] = us; nt[us] = 0;
	ll x = 0 , y = 0;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] != u[x]){
			cout<<"-1\n";
			return;
		}
		x = nt[x];
		if(x == us){
			ll ps = p[v[y]].size();
			for(ll j = ps - 1 ; j >= 0 ; j--){
				ll e = p[v[y]][j];
				nt[pr[e]] = nt[e];
				pr[nt[e]] = pr[e];
			}
			y++;
			x = nt[x];
		}
	}
	for(ll i = 0 ; i < us ; i++){
		cout<<(char)(u[i] + 'a');
	}
	cout<<' ';
	for(ll i = 0 ; i < vs ; i++){
		cout<<(char)(v[i] + 'a');
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}