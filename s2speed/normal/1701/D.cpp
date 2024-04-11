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

const ll maxn = 5e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll n;
ll a[maxn] , b[maxn];
vector<pll> v[maxn];
priority_queue<pll> pq;

void solve(){
	cin>>n;
	for(ll i = 1 ; i <= n ; i++) v[i].clear();
	for(ll i = 1 ; i <= n ; i++){
		cin>>b[i];
		ll l , r;
		if(b[i] == 0){
			l = i + 1; r = n;
		} else {
			r = i / b[i]; l = i / (b[i] + 1) + 1;
		}
		v[r].push_back({l , i});
	}
	for(ll i = n ; i ; i--){
		for(auto p : v[i]){
			pq.push(p);
		}
		pll p = pq.top(); pq.pop();
		a[p.second] = i;
	}
	for(ll i = 1 ; i <= n ; i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
	return;
}

/*
1
4
0 2 0 1
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}