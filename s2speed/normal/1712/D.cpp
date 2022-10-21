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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> v;
ll a[maxn];
bitset<maxn> mark;

void solve(){
	v.clear();
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
		a[i] = h;
		mark[i] = false;
	}
	if(k == n){
		cout<<(ll)1e9<<'\n';
		return;
	}
	sort(all(v));
	ll res = 1e9;
	if(k == 1){
		ll o = 0;
		for(ll i = 0 ; i < n ; i++){
			if(a[i] == v[0]){
				a[i] = 1e9;
				mark[i] = true;
			}
		}
		for(ll i = 1 ; i < n ; i++){
			if(mark[i] && mark[i - 1]){
				o = max(o , v[0]);
			} else {
				o = max(o , min(a[i] , a[i - 1]));
			}
		}
//		cout<<v[1] * 2<<' '<<o<<' '<<v[0] * 2<<' '<<v[n - 1]<<'\n';
		res = min(res , max(min(v[1] * 2 , o) , min(v[0] * 2 , v[n - 1])));
		cout<<res<<'\n';
		return;
	}
	if(v[k - 1] == v[k]){
		res = min(res , v[k - 1] * 2);
		cout<<res<<'\n';
		return;
	}
	ll o = 0;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] < v[k]){
			a[i] = 1e9;
		}
	}
	for(ll i = 1 ; i < n ; i++){
		o = max(o , min(a[i] , a[i - 1]));
	}
	res = min(res , max(min(o , v[k] * 2) , v[k - 1] * 2));
	cout<<res<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}