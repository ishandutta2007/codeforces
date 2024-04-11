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

const ll maxn = 2e3 + 49 , md = 1e9 + 7 , inf = 2e16;

ll n;
ll a[maxn];
vector<ll> adj[maxn];
bitset<maxn> mark;
ll o;

void DFS(ll r){
	mark[r] = true;
	if(r < n) o++;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		DFS(i);
	}
	return;
}

bool check(){
	for(ll i = 0 ; i < n + 30 ; i++){
		adj[i].clear();
		mark[i] = false;
	}
	o = 0;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < 30 ; j++){
			if(a[i] & (1 << j)){
				adj[i].push_back(n + j); adj[n + j].push_back(i);
			}
		}
	}
	DFS(0);
	return (o == n);
}

/*
1
5
1 2 3 4 5
*/

ll c[maxn];

void solve(){
	cin>>n;
	ll res = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		if(a[i] == 0){
			res++;
			a[i] = 1;
		}
	}
	if(check()){
		cout<<res<<'\n';
		for(ll i = 0 ; i < n ; i++){
			cout<<a[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		a[i]--;
		if(check()){
			cout<<res + 1<<'\n';
			for(ll i = 0 ; i < n ; i++){
				cout<<a[i]<<' ';
			}
			cout<<'\n';
			return;
		}
		a[i] += 2;
		if(check()){
			cout<<res + 1<<'\n';
			for(ll i = 0 ; i < n ; i++){
				cout<<a[i]<<' ';
			}
			cout<<'\n';
			return;
		}
		a[i]--;
	}
	cout<<res + 2<<'\n';
	ll mx = -1;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < 30 ; j++){
			if(a[i] & (1 << j)){
				c[i] = j;
				break;
			}
		}
		if(c[i] > mx) mx = c[i];
	}
	for(ll i = 0 ; i < n ; i++){
		if(c[i] == mx){
			a[i]--;
			break;
		}
	}
	for(ll i = n - 1 ; ~i ; i--){
		if(c[i] == mx){
			a[i]++;
			break;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<a[i]<<' ';
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