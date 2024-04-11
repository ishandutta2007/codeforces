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

inline ll tav(ll n , ll k){
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

ll ab(ll a){
	return max(a , -a);
}

ll a[maxn] , b[maxn];
vector<ll> va , vb;

void solve(){
	va.clear(); vb.clear();
	ll n;
	cin>>n;
	vb.push_back(-inf); vb.push_back(inf); va.push_back(inf); va.push_back(-inf);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		va.push_back(a[i]);
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
		vb.push_back(b[i]);
	}
	sort(all(vb)); sort(all(va));
	ll ans = inf;
	ll a0 , a1 , b0 , b1;
	ll j = lower_bound(all(vb) , a[0]) - vb.begin();
	a0 = min(vb[j] - a[0] , a[0] - vb[j - 1]);
	j = lower_bound(all(vb) , a[n - 1]) - vb.begin();
	a1 = min(vb[j] - a[n - 1] , a[n - 1] - vb[j - 1]);
	j = lower_bound(all(va) , b[0]) - va.begin();
	b0 = min(va[j] - b[0] , b[0] - va[j - 1]);
	j = lower_bound(all(va) , b[n - 1]) - va.begin();
	b1 = min(va[j] - b[n - 1] , b[n - 1] - va[j - 1]);
	ans = a0 + a1 + b0 + b1;
	ans = min(ans , ab(a[0] - b[0]) + ab(a[n - 1] - b[n - 1]));
	ans = min(ans , ab(a[0] - b[n - 1]) + ab(a[n - 1] - b[0]));
	ans = min(ans , ab(a[0] - b[0]) + a1 + b1);
	ans = min(ans , ab(a[0] - b[n - 1]) + a1 + b0);
	ans = min(ans , ab(a[n - 1] - b[0]) + a0 + b1);
	ans = min(ans , ab(a[n - 1] - b[n - 1]) + a0 + b0);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}