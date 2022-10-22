#include<bits/stdc++.h>

using namespace std;

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<pll , ll> plll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

struct node {

	ll cnt[11][11] , s , f;

	void init(ll x , ll l){
		memset(cnt , 0 , sizeof(cnt));
		cnt[x][x] = l - 1;
		s = f = x;
		return;
	}

	friend node operator+ (node a , node b){
		node res;
		for(ll i = 0 ; i < 10 ; i++){
			for(ll j = 0 ; j < 10 ; j++){
				res.cnt[i][j] =  a.cnt[i][j] + b.cnt[i][j];
			}
		}
		res.cnt[a.f][b.s]++;
		res.s = a.s;
		res.f = b.f;
		return res;
	}

	friend void operator+= (node &a , node b){
		a = a + b;
		return;
	}

};

struct segtree {

	ll sz = 1;
	vector<node> val;
	vector<ll> laz;
	node def;

	void init(ll n){
		while(sz < n) sz <<= 1;
		def.init(10 , 1);
		val.assign(sz << 1 , def);
		laz.assign(sz << 1 , -1);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		ll h = laz[x];
		laz[x] = -1;
		if(h == -1) return;
		val[x].init(h , rx - lx);
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] = laz[rn] = h;
		return;
	}

	void set(ll l , ll r , ll c , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = c;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		set(l , r , c , ln , lx , m); set(l , r , c , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(ll l , ll r , ll c){
		set(l , r , c , 0 , 0 , sz);
		return;
	}

};

segtree st;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n , q , k;
	string s;
	cin>>n>>q>>k>>s;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		st.set(i , i + 1 , s[i] - 'a');
	}
	for(ll e = 0 ; e < q ; e++){
		ll t;
		cin>>t; t--;
		if(t){
			ll ans = 1;
			string h;
			cin>>h;
			for(ll i = 0 ; i < k ; i++){
				for(ll j = i ; j < k ; j++){
					ans += st.val[0].cnt[h[j] - 'a'][h[i] - 'a'];
				}
			}
			cout<<ans<<'\n';
		} else {
			ll l , r;
			char c;
			cin>>l>>r>>c; l--;
			st.set(l , r , c - 'a');
		}
	}
	return 0;
}