#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
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

ll a[maxn];
priority_queue<pll> pq;
vector<pll> v;

void solve(){
	v.clear();
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		if(a[i]) pq.push({a[i] , i});
	}
	while(sze(pq) >= 2){
		pll p = pq.top() , q; pq.pop();
		q = pq.top(); pq.pop();
		ll i = p.second , j = q.second;
		v.push_back({i , j});
		a[i]--;
		a[j]--;
		if(a[i]) pq.push({a[i] , i});
		if(a[j]) pq.push({a[j] , j});
	}
	if(!pq.empty()) pq.pop();
	cout<<sze(v)<<'\n';
	for(auto p : v){
		cout<<p.first<<' '<<p.second<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}