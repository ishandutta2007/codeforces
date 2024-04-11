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

ll a[maxn] , b[maxn];
vector<pll> v;

void solve(){
	v.clear(); v.shrink_to_fit();
	ll n , m , k , sum = 0;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		sum += a[i];
	}
	cin>>m;
	for(ll j = 0 ; j < m ; j++){
		cin>>b[j];
		sum -= b[j];
	}
	if(sum != 0){
		cout<<"NO\n";
		return;
	}
	ll pr = -1;
	for(ll i = 0 ; i < n ; i++){
		ll h = a[i];
		while(h % k == 0) h /= k;
		ll t = a[i] / h;
		if(h == pr){
			v.back().second += t;
		} else {
			v.push_back({h , t});
			pr = h;
		}
	}
	ll x = 0;
	for(ll i = 0 ; i < m ; i++){
		if(b[i] < v[x].first){
			cout<<"No\n";
			return;
		}
		if(b[i] % v[x].first != 0){
			cout<<"nO\n";
			return;
		}
		ll h = b[i] / v[x].first;
		while(h % k == 0) h /= k;
		if(h != 1){
			cout<<"no\n";
			return;
		}
		ll t = b[i] / v[x].first;
		if(v[x].second < t){
			cout<<"NO\n";
			return;
		}
		v[x].second -= t;
		if(v[x].second == 0) x++;
	}
	cout<<"Yes\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
} // maxn