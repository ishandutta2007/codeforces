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

vector<ll> v , a;

void solve(){
	a.clear(); v.clear();
	ll m , n;
	cin>>m>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		a.push_back(h);
	}
	sort(all(a));
	for(ll i = 1 ; i < n ; i++){
		ll h = a[i] - a[i - 1] - 1;
		v.push_back(h);
	}
	ll h = m + a[0] - a[n - 1] - 1 , res = 0 , cnt = 0;
	v.push_back(h);
	sort(all(v) , greater<ll>());
	for(ll i = 0 ; i < n ; i++){
		ll h = v[i] - (cnt << 1);
		if(h <= 0){
			break;
		}
		if(h == 1){
			res++;
			break;
		}
		res += h - 1;
		cnt += 2;
	}
	cout<<m - res<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}