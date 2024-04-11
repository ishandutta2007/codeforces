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

ll a[maxn] , b[maxn] , c[maxn] , d[maxn] , z[maxn];
vector<pll> adj[maxn];
bitset<maxn> mark;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , lm;
	cin>>n; lm = n << 1;
	if((n & 1) == 0){
		cout<<"First"<<endl;
		for(ll i = 0 ; i < n ; i++){
			cout<<i + 1<<' ';
		}
		for(ll i = n ; i < lm ; i++){
			cout<<i - n + 1<<' ';
		}
		cout<<endl;
		return 0;
	}
	cout<<"Second"<<endl;
	for(ll i = 1 ; i <= lm ; i++){
		ll h;
		cin>>h;
		if(a[h] != 0){
			b[h] = i; d[h] = i % n;
		} else {
			a[h] = i; c[h] = i % n;
		}
	}
	for(ll i = 1 ; i <= n ; i++){
		if(c[i] == d[i]){
			mark[c[i]] = true;
			z[i] = a[i];
			continue;
		}
		adj[c[i]].push_back({d[i] , i});
		adj[d[i]].push_back({c[i] , i});
	}
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		ll pr = i , v = adj[i][0].first;
		z[adj[i][0].second] = (c[adj[i][0].second] == v ? a[adj[i][0].second] : b[adj[i][0].second]);
		mark[pr] = true;
		while(v != i){
			mark[v] = true;
			pll p = adj[v][0];
			if(p.first == pr) p = adj[v][1];
			pr = v;
			v = p.first;
			z[p.second] = (c[p.second] == v ? a[p.second] : b[p.second]);
		}
	}
	ll sum = 0;
	for(ll i = 1 ; i <= n ; i++){
		sum += z[i];
	}
	if(sum % lm == 0){
		for(ll i = 1 ; i <= n ; i++){
			cout<<z[i]<<' ';
		}
		cout<<endl;
		return 0;
	}
	for(ll i = 1 ; i <= n ; i++){
		if(z[i] == a[i]){
			z[i] = b[i];
		} else {
			z[i] = a[i];
		}
		cout<<z[i]<<' ';
	}
	cout<<endl;
	return 0;
}