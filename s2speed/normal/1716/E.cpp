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

const ll maxn = 3e5 + 17 , md = 1e9 + 7 , inf = 2e16;

struct item {

	ll ans , sum , pr , sf;

	void init(ll x){
		ans = pr = sf = max(0ll , x);
		sum = x;
		return;
	}

	friend item operator+ (item a , item b){
		item res;
		res.sum = a.sum + b.sum;
		res.pr = max(a.pr , a.sum + b.pr);
		res.sf = max(b.sf , b.sum + a.sf);
		res.ans = max(max(a.ans , b.ans) , a.sf + b.pr);
		return res;
	}

};

ll st[20];
ll a[maxn] , ans[maxn];
vector<item> val;
vector<pll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll i = 0 ; i < 20 ; i++){
		st[i] = (1 << i) - 1;
	}
	ll n , lm;
	cin>>n; lm = (1 << n);
	for(ll i = 0 ; i < lm ; i++){
		cin>>a[i];
	}
	ll sz = (lm << 1) - 1;
	val.resize(sz);
	for(ll i = st[n] ; i < sz ; i++){
		val[i].init(a[i - st[n]]);
	}
	for(ll j = n - 1 ; ~j ; j--){
		for(ll i = st[j] ; i < st[j + 1] ; i++){
			ll ln = (i << 1) + 1 , rn = ln + 1;
			val[i] = val[ln] + val[rn];
		}
	}
	ll q , pr = 0;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll j;
		cin>>j; j = n - 1 - j;
		pr ^= (1 << j);
		v.push_back({pr , e});
	}
	sort(all(v));
	pr = 0;
	for(ll e = 0 ; e < q ; e++){
		ll x = v[e].first , h = x ^ pr;
		if(h == 0){
			ans[v[e].second] = val[0].ans;
			continue;
		}
		ll t;
		for(ll j = n - 1 ; ~j ; j--){
			if(h & (1 << j)){
				t = j;
				break;
			}
		}
		for(ll j = t ; ~j ; j--){
			bool c = (x & (1 << j));
			for(ll i = st[j] ; i < st[j + 1] ; i++){
				ll ln = (i << 1) + 1 , rn = ln + 1;
				if(c){
					val[i] = val[rn] + val[ln];
				} else {
					val[i] = val[ln] + val[rn];
				}
			}
		}
		ans[v[e].second] = val[0].ans;
		pr = x;
	}
	for(ll e = 0 ; e < q ; e++){
		cout<<ans[e]<<'\n';
	}
	return 0;
}