#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll ps[maxn] , f[maxn] , fr[10] , sc[10];
string s;
vector<pll> v;

void solve(){
	v.clear();
	fill(fr , fr + 9 , inf);
	fill(sc , sc + 9 , inf);
	ll n , w , q;
	cin>>s>>w>>q; n = sze(s);
	for(ll i = 1 ; i <= n ; i++){
		ps[i] = ps[i - 1] + (s[i - 1] - '0');
	}
	for(ll i = 1 ; i + w - 1 <= n ; i++){
		f[i] = (ps[i + w - 1] - ps[i - 1]) % 9;
	}
	for(ll i = n - w + 1 ; i > 0 ; i--){
		sc[f[i]] = fr[f[i]];
		fr[f[i]] = i;
	}
	for(ll i = 0 ; i < 9 ; i++){
		v.push_back({fr[i] , i});
	}
	sort(all(v));
	for(ll e = 0 ; e < q ; e++){
		ll l , r , k;
		cin>>l>>r>>k;
		ll o = (ps[r] - ps[l - 1]) % 9;
		bool ans = false;
		for(auto p : v){
			if(p.first == inf) break;
			ll h = p.second * o % 9 , y = (k + 9 - h) % 9;
			ll g = (y == p.second ? sc[y] : fr[y]);
			if(g != inf){
				ans = true;
				cout<<p.first<<' '<<g<<'\n';
				break;
			}
		}
		if(!ans){
			cout<<"-1 -1\n";
		}
	}
	return;
}

/*
1
1003004
4 1
1 2 1
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}