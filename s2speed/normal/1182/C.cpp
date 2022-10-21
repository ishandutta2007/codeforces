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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

string s[maxn];
ll a[maxn] , t[maxn] , cnt[maxn][5];
vector<ll> v[maxn][5] , u[maxn];
bitset<maxn> ch;
map<char , ll> mp;
pllll ans[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(a , 0 , sizeof(a));
	ll n;
	cin>>n;
	mp['a'] = 0;
	mp['e'] = 1;
	mp['o'] = 2;
	mp['i'] = 3;
	mp['u'] = 4;
	for(ll i = 0 ; i < n ; i++){
		cin>>s[i];
		ll k = sze(s[i]);
		for(ll j = 0 ; j < k ; j++){
			if(mp.count(s[i][j])){
				a[i]++;
				t[i] = mp[s[i][j]];
			}
		}
		cnt[a[i]][t[i]]++;
		v[a[i]][t[i]].push_back(i);
	}
	ll h = 0 , lm = 1e6 , w = 0;
	for(ll i = 1 ; i <= lm ; i++){
		for(ll j = 0 ; j < 5 ; j++){
			h += (cnt[i][j] >> 1);
		}
		ll o = 0;
		for(ll j = 0 ; j < 5 ; j++){
			o += cnt[i][j] & 1;
		}
		w += o >> 1;
	}
	while(h > w){
		h--;
		w++;
	}
	ll cnh = 0;
	for(ll i = 1 ; i <= lm ; i++){
		for(ll j = 0 ; j < 5 ; j++){
			for(ll e = 0 ; e < cnt[i][j] - 1 && cnh < h ; e += 2){
				ans[cnh].second = {v[i][j][e] , v[i][j][e + 1]};
				ch[v[i][j][e]] = ch[v[i][j][e + 1]] = true;
				cnh++;
			}
		}
	}
	ll cnw = 0;
	for(ll i = 1 ; i <= lm;  i++){
		for(ll j = 0 ; j < 5 ; j++){
			for(auto t : v[i][j]){
				if(ch[t]) continue;
				u[i].push_back(t);
			}
		}
		ll us = sze(u[i]);
		for(ll e = 0 ; e < us - 1 && cnw < h ; e += 2){
			ans[cnw].first = {u[i][e] , u[i][e + 1]};
			cnw++;
		}
	}
	cout<<h<<'\n';
	for(ll i = 0 ; i < h ; i++){
		cout<<s[ans[i].first.first]<<' '<<s[ans[i].second.first]<<'\n'<<s[ans[i].first.second]<<' '<<s[ans[i].second.second]<<'\n';
	}
	return 0;
}