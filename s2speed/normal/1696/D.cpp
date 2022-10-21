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

const ll maxn = 4e5 + 17 , md = 1e9 + 7 , inf = 2e8;

struct segtree {

	int sz = 1;
	vector<int> val;

	void init(int n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , inf);
		return;
	}

	void set(int i , int k , int x , int lx , int rx){
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		int m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void set(int i , int k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	int cal(int l , int r , int x , int lx , int rx){
		if(rx <= l || lx >= r) return inf;
		if(rx <= r && lx >= l) return val[x];
		int m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		int a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return min(a , b);
	}

	int cal(int l , int r){
		if(l >= r) return inf;
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

segtree stn , stx;
ll a[maxn] , dis[maxn];
vector<ll> vn , vx;

void solve(){
	stn.clear(); stx.clear();
	vn.clear(); vx.clear();
	ll n;
	cin>>n;
	fill(dis , dis + n , inf);
	stn.init(n); stx.init(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	dis[n - 1] = 0;
	stn.set(n - 1 , 0);
	stx.set(n - 1 , 0);
	vn.push_back(n - 1);
	vx.push_back(n - 1);
	for(ll i = n - 2 ; ~i ; i--){
		ll h = n;
		while(!vn.empty()){
			ll j = vn.back();
			if(a[j] < a[i]){
				h = j;
				break;
			}
			vn.pop_back();
			stn.set(j , inf);
		}
		vn.push_back(i);
		ll o = n;
		while(!vx.empty()){
			ll j = vx.back();
			if(a[j] > a[i]){
				o = j;
				break;
			}
			vx.pop_back();
			stx.set(j , inf);
		}
		vx.push_back(i);
		dis[i] = min(stx.cal(i , h) , stn.cal(i , o)) + 1;
		stx.set(i , dis[i]);
		stn.set(i , dis[i]);
	}
	cout<<dis[0]<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
} // maxn