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

bitset<maxn> mark;
ll a[maxn] , p[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	if(n == 1){
		cout<<"-1\n";
		return;
	}
	for(ll i = 0 ; i < n ; i++) mark[i] = true;
	for(ll i = 0 ; i < n - 1 ; i++){
		bool o = mark[a[i]];
		mark[a[i]] = false;
		p[i] = mark._Find_first();
		mark[a[i]] = o;
		mark[p[i]] = false;
	}
	p[n - 1] = mark._Find_first();
	if(a[n - 1] == p[n - 1]) swap(p[n - 1] , p[n - 2]);
	for(ll i = 0 ; i < n ; i++){
		cout<<p[i] + 1<<' ';
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