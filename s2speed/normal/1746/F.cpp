#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 3e5 + 17 , md = 1e9 + 7 , inf = 2e16 , x = 30;

struct fentree {

	ll sz;
	vector<ll> val;

	void init(ll n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(ll i , ll x){
		ll h = i;
		while(h < sz){
			val[h] += x;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll h = i , res = 0;
		while(h > -1){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

	ll cal(ll l , ll r){
		return cal(r - 1) - cal(l - 1);
	}

};

fentree ft[x];
map<int , int> lb;
int cur = 0 , a[maxn] , f[maxn << 1][x];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		if(lb.count(h) == 0){
			lb[h] = cur;
			for(ll j = 0 ; j < x ; j++){
				f[cur][j] = rng() % md;
			}
			cur++;
		}
		a[i] = lb[h];
	}
	for(ll j = 0 ; j < x ; j++){
		ft[j].init(n);
		for(ll i = 0 ; i < n ; i++){
			ft[j].add(i , f[a[i]][j]);
		}
	}
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t;
		if(t == 1){
			ll i , k;
			cin>>i>>k; i--;
			if(lb.count(k) == 0){
				lb[k] = cur;
				for(ll j = 0 ; j < x ; j++){
					f[cur][j] = rng() % md;
				}
				cur++;
			}
			ll h = lb[k];
			for(ll j = 0 ; j < x ; j++){
				ft[j].add(i , f[h][j] - f[a[i]][j]);
			}
			a[i] = h;
		} else {
			ll l , r , k;
			cin>>l>>r>>k; l--;
			bool f = true;
			for(ll j = 0 ; j < x ; j++){
				ll t = ft[j].cal(l , r);
				f &= (t % k == 0);
			}
			cout<<(f ? "YES\n" : "NO\n");
		}
	}
	return 0;
}