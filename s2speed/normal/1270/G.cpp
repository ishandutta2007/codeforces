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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn];
bitset<maxn> mark;
vector<ll> v , ans;

void solve(){
	v.clear(); ans.clear();
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		mark[i] = false;
		cin>>a[i]; a[i] -= i; a[i] = -a[i];
	}
	ll h = 1;
	while(!mark[h]){
		mark[h] = true;
		v.push_back(h);
		h = a[h];
	}
	ans.push_back(h);
	while(v.back() != h){
		ans.push_back(v.back()); v.pop_back();
	}
	cout<<sze(ans)<<'\n';
	for(auto i : ans){
		cout<<i<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	

	return 0;
}