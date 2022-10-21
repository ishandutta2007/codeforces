#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll a[maxn] , ls[maxn] , nx[maxn] , pr[maxn] , al[maxn] , ar[maxn] , fr[maxn] , qu[maxn];
vector<ll> v;

void solve(){
	v.clear();
	ll n , m;
	cin>>n>>m;
	fill(al , al + n , -1);
	fill(ar , ar + n , inf);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	ll vs = sze(v);
	for(ll i = 0 ; i < n ; i++){
		a[i] = lower_bound(all(v) , a[i]) - v.begin();
//		cout<<a[i]<<' ';
	}
//	cout<<'\n';
	fill(ls , ls + n , -1);
	for(int i = 0 ; i < n ; i++){
		pr[i] = ls[a[i]];
		ls[a[i]] = i;
	}
	fill(ls , ls + n , inf);
	for(ll i = n - 1 ; ~i ; i--){
		nx[i] = ls[a[i]];
		ls[a[i]] = i;
	}
	for(ll i = 0 ; i < m ; i++){
		ll l , r;
		cin>>l>>r; l--; r--;
		al[l] = max(al[l] , r);
		ar[r] = min(ar[r] , l);
	}
	for(ll i = 1 ; i < n ; i++){
		al[i] = max(al[i] , al[i - 1]);
	}
	for(ll i = n - 2 ; ~i ; i--){
		ar[i] = min(ar[i] , ar[i + 1]);
	}
	fill(ls , ls + n , -1);
	for(ll i = n - 1 ; ~i ; i--){
		if(nx[i] <= al[i]){
			fr[a[i]] = i;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(pr[i] >= ar[i]){
			ls[a[i]] = i;
		}
	}
	bool f = true;
	for(ll i = 0 ; i < vs ; i++){
		f &= (ls[i] == -1);
//		cout<<fr[i]<<' '<<ls[i]<<'\n';
	}
	if(f){
		cout<<"0\n";
		return;
	}
	ll l = n , r = -1;
	fill(qu , qu + n , -1);
	for(ll i = 0 ; i < vs ; i++){
		if(ls[i] == -1) continue;
		if(al[fr[i]] >= ls[i]){
			qu[fr[i] + 1] = max(qu[fr[i] + 1] , ls[i]);
		}
		l = min(l , nx[fr[i]]);
		r = max(r , pr[ls[i]]);
	}
	ll res = inf;
	for(ll i = 0 ; i <= l ; i++){
		r = max(r , qu[i]);
		res = min(r - i + 1 , res);
	}
	cout<<res<<'\n';
	return;
}

/*
1
7 3
1 1 2 1 3 3 5
1 4
4 5
2 4
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}