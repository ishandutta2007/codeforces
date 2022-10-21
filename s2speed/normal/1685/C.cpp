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

struct segtree {

	ll sz = 1;
	vector<pll> vax , vin;

	void init(ll n){
		while(sz < n) sz <<= 1;
		vin.assign(sz << 1 , {inf , -1});
		vax.assign(sz << 1 , {-inf , -1});
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			vax[x] = vin[x] = {k , lx};
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		vin[x] = min(vin[ln] , vin[rn]);
		vax[x] = max(vax[ln] , vax[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	pll cax(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return {-inf , -1};
		if(rx <= r && lx >= l) return vax[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		pll a , b;
		a = cax(l , r , ln , lx , m);
		b = cax(l , r , rn , m , rx);
		return max(a , b);
	}

	pll cax(ll l , ll r){
		if(l >= r) return {-inf , -1};
		return cax(l , r , 0 , 0 , sz);
	}

	pll cin(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return {inf , -1};
		if(rx <= r && lx >= l) return vin[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		pll a , b;
		a = cin(l , r , ln , lx , m);
		b = cin(l , r , rn , m , rx);
		return min(a , b);
	}

	pll cin(ll l , ll r){
		if(l >= r) return {-inf , -1};
		return cin(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		vax.clear(); vin.clear();
		return;
	}

};

segtree st;
ll ps[maxn];
vector<pll> ans;
vector<ll> v[maxn] , u;

void solve(){
	st.clear(); ans.clear(); u.clear();
	ll n;
	cin>>n; n <<= 1;
	ps[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		v[i].clear();
		char c;
		cin>>c;
		if(c == '('){
			ps[i] = ps[i - 1] + 1;
		} else {
			ps[i] = ps[i - 1] - 1;
		}
		if(ps[i] == -1 && ps[i - 1] == 0){
			u.push_back(i);
		}
	}
	st.init(n + 1);
	for(ll i = 0 ; i <= n ; i++){
		st.set(i , ps[i]);
		if(ps[i] >= 0){
			v[ps[i]].push_back(i);
		}
	}
	ll maxx = st.cax(0 , n).first , indd = st.cax(0 , n).second;
	ll pr = 0 , y = 0 , x = 0 , us = sze(u);
	while(true){
		ll j = lower_bound(all(u) , x) - u.begin();
		if(j == us) break;
		ll t = u[j] , mx = y , ind = pr;
		pll p = st.cax(x , t);
		if(p.first > y){
			mx = p.first;
			ind = p.second;
		}
		if(mx >= maxx){
			ans.push_back({ind + 1 , n});
			break;
		}
		ll o = v[maxx - mx].back();
		if(o > u.back()){
			ans.push_back({ind + 1 , o});
			break;
		}
		ans.push_back({ind + 1 , indd});
		ans.push_back({indd + 1 , n});
		break;
	}
	cout<<sze(ans)<<'\n';
	for(auto p : ans){
		cout<<p.first<<' '<<p.second<<'\n';
	}
	return;
}

/*
1
5
())((()))(
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}