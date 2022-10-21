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

ll n , m , p;
vector<ll> v , c[maxn] , r;
ll a[maxn] , b[maxn] , cnt[2 * maxn] , bnt[2 * maxn] , vs , cur , znt = 0 , ans = 0;

void add(ll x){
	cnt[x]++;
	if(cnt[x] == bnt[x]) cur++;
	if(cnt[x] == bnt[x] + 1) cur--;
	return;
}

void del(ll x){
	cnt[x]--;
	if(cnt[x] == bnt[x]) cur++;
	if(cnt[x] == bnt[x] - 1) cur--;
	return;
}

void solve(ll j){
	ll cs = sze(c[j]);
	if(cs < m) return;
	for(ll i = 0 ; i < m - 1 ; i++){
		add(c[j][i]);
	}
	for(ll i = 0 ; i < cs ; i++){
		if(i + m - 1 < cs) add(c[j][i + m - 1]);
		if(cur == vs){
			ans++;
			r.push_back(i * p + j + 1);
		}
		del(c[j][i]);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	memset(bnt , 0 , sizeof(bnt));
	cin>>n>>m>>p;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i];
		v.push_back(b[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	vs = sze(v);
	for(ll i = 0 ; i < n ; i++){
		a[i] = lower_bound(all(v) , a[i]) - v.begin();
		c[i % p].push_back(a[i]);
	}
	for(ll i = 0 ; i < m ; i++){
		b[i] = lower_bound(all(v) , b[i]) - v.begin();
		bnt[b[i]]++;
	}
	for(ll i = 0 ; i < vs ; i++){
		if(bnt[i] == 0) znt++;
	}
	cur = znt;
	for(ll i = 0 ; i < p ; i++){
		solve(i);
	}
	sort(all(r));
	cout<<ans<<'\n';
	for(auto i : r){
		cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}