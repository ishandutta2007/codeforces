#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 4e5 + 15 , md = 1e9 + 7 , inf = 1e18;

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz *= 2;
		val.assign(2 * sz , 0);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = max(val[ln] , val[rn]);
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cal(ll l , ll r){
		if(l >= r) return 0;
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		val.clear();
		val.assign(2 * sz , 0);
		return;
	}

};

segtree st;
ll dp[MAXN] , pd[MAXN] , a[MAXN] , cnt[MAXN] , qdp[MAXN] , qpd[MAXN];
vector<pll> v;
vector<plll> q;
pll p[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n , m , g = 0;
	cin>>n>>m;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back({a[i] , n - i});
	}
	for(ll i = 0 ; i < m ; i++){
		ll j , o;
		cin>>j>>o; j--;
		p[i] = {j , o};
		q.push_back({{o , j} , i});
	}
	sort(all(q)); q.push_back({{inf , -1} , -1});
	sort(all(v));
	for(ll e = 0 ; e < n ; e++){
		ll i = n - v[e].second;
		dp[i] = st.cal(0 , i) + 1;
		g = max(g , dp[i] + 1);
		st.set(i , dp[i]);
	}
	st.clear(); reverse(all(v));
	for(ll e = 0 ; e < n ; e++){
		ll i = n - v[e].second;
		pd[i] = st.cal(i + 1 , n) + 1;
		st.set(i , pd[i]);
	}
	st.clear();
	for(ll i = 0 ; i < n ; i++){
		if(dp[i] + pd[i] == g){
			cnt[dp[i]]++;
		}
	}
	reverse(all(v));
	ll x = 0;
	for(ll e = 0 ; e < n ; e++){
		ll i = n - v[e].second , w = a[i];
		while(q[x].first.first <= w){
			ll t = q[x].second , j = q[x].first.second;
			qdp[t] = st.cal(0 , j) + 1;
			x++;
		}
		st.set(i , dp[i]);
	}
	while(x < q.size() - 1){
		ll t = q[x].second , j = q[x].first.second;
		qdp[t] = st.cal(0 , j) + 1;
		x++;
	}
	q.pop_back();
	reverse(all(q)); reverse(all(v));
	q.push_back({{-inf , -1} , -1});
	x = 0;
	st.clear();
	for(ll e = 0 ; e < n ; e++){
		ll i = n - v[e].second , w = a[i];
		while(q[x].first.first >= w){
			ll t = q[x].second , j = q[x].first.second;
			qpd[t] = st.cal(j + 1 , n) + 1;
			x++;
		}
		st.set(i , pd[i]);
	}
	while(x < q.size() - 1){
		ll t = q[x].second , j = q[x].first.second;
		qpd[t] = st.cal(j + 1 , n) + 1;
		x++;
	}
	for(ll i = 0 ; i < m ; i++){
		if(qdp[i] + qpd[i] >= g){
			cout<<qdp[i] + qpd[i] - 1<<'\n';
			continue;
		}
		ll j = p[i].first;
		if(dp[j] + pd[j] != g){
			cout<<g - 1<<'\n';
			continue;
		}
		if(cnt[dp[j]] > 1){
			cout<<g - 1<<'\n';
		} else {
			cout<<g - 2<<'\n';
		}
	}
	return 0;
}

/*

*/