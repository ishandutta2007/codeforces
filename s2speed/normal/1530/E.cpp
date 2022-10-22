#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
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

vector<ll> v;
ll cnt[27];

void solve(){
	memset(cnt , 0 , sizeof(cnt));
	v.clear();
	string s;
	ll n;
	cin>>s; n = sze(s);
	for(ll i = 0 ; i < n ; i++){
		v.push_back(s[i] - 'a');
		cnt[s[i] - 'a']++;
	}
	sort(all(v));
	ll r = -1;
	for(ll i = 0 ; i < 26 ; i++){
		if(cnt[i] == 1){
			r = i;
			break;
		}
	}
	if(r != -1){
		string h;
		h += r + 'a';
		for(ll i = 0 ; i < 26 ; i++){
			if(i == r) continue;
			for(ll j = 0 ; j < cnt[i] ; j++){
				h += i + 'a';
			}
		}
		cout<<h<<'\n';
		return;
	}
	for(ll i = 0 ; i < 26 ; i++){
		if(cnt[i]){
			r = i;
			break;
		}
	}
	if(cnt[r] <= n / 2 + 1){
		string h;
		h += r + 'a'; h += r + 'a';
		cnt[r] -= 2;
		for(ll j = cnt[r] + 2 ; j < n ; j++){
			h += v[j] + 'a';
			if(cnt[r]){
				cnt[r]--;
				h += r + 'a';
			}
		}
		cout<<h<<'\n';
		return;
	}
	if(cnt[r] == n){
		cout<<s<<'\n';
		return;
	}
	ll t;
	for(ll i = r + 1 ; i < 26 ; i++){
		if(cnt[i]){
			t = i;
			break;
		}
	}
	if(cnt[r] + cnt[t] == n){
		string h;
		h += r + 'a';
		cnt[r]--;
		for(ll j = 0 ; j < cnt[t] ; j++){
			h += t + 'a';
		}
		for(ll j = 0 ; j < cnt[r] ; j++){
			h += r + 'a';
		}
		cout<<h<<'\n';
		return;
	}
	ll c;
	for(ll i = t + 1 ; i < 26 ; i++){
		if(cnt[i]){
			c = i;
			break;
		}
	}
	string h;
	h += r + 'a';
	cnt[r]--;
	h += t + 'a';
	cnt[t]--;
	for(ll j = 0 ; j < cnt[r] ; j++){
		h += r + 'a';
	}
	h += c + 'a';
	cnt[c]--;
	for(ll i = r + 1 ; i < 26 ; i++){
		for(ll j = 0 ; j < cnt[i] ; j++){
			h += i + 'a';
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