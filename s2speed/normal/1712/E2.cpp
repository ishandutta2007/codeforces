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

const ll maxn = 4e5 + 17 , md = 1e9 + 7 , inf = 2e16;

struct fentree {

	ll sz;
	vector<ll> val;

	void init(ll n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(ll i , ll k){
		ll h = i;
		while(h < sz){
			val[h] += k;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll h = i , res = 0;
		while(~h){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

};

fentree ft;
vector<ll> dv[maxn] , dt[maxn];
ll t[maxn];
vector<pll> qu[maxn];
ll ans[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll z = 2 ; z < maxn ; z <<= 1){
		for(ll i = z ; i < maxn ; i += z){
			t[i]++;
		}
	}
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = i << 1 ; j < maxn ; j += i){
			dv[j].push_back(i);
			if(t[i] == t[j]) dt[j].push_back(i);
		}
	}
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll l , r;
		cin>>l>>r;
		qu[l].push_back({r , e});
	}
	ll lm = 2e5;
	ft.init(lm + 1);
	for(ll i = lm ; i > 0 ; i--){
		for(ll j = i << 1 ; j <= lm ; j += i){
			ll h = sze(dv[j]) - (lower_bound(all(dv[j]) , i + 1) - dv[j].begin());
			ft.add(j , h);
		}
		for(ll j = i << 1 ; j <= 4e5 ; j += i){
			if(j & 1) continue;
			if(t[j] != t[i]){
				ll h = sze(dt[j]) - (lower_bound(all(dt[j]) , max(i , (j >> 1) - i) + 1) - dt[j].begin());
				ft.add((j >> 1) , h);
			} else {
				ll h = sze(dv[j]) - (lower_bound(all(dv[j]) , max(i , (j >> 1) - i) + 1) - dv[j].begin()) - 1;
				ft.add((j >> 1) , h);
			}
		}
		for(auto p : qu[i]){
			ll r = p.first , e = p.second , d = r - i + 1;
			ans[e] = d * (d - 1) * (d - 2) / 6 - ft.cal(r);
		}
	}
	for(ll i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}