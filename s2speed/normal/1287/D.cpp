#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e3 + 16 , md = 1e9 + 7 , inf = 2e18;

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

bitset<maxn> av;
ll c[maxn] , a[maxn];
vector<ll> adj[maxn];
ll n;
bool ch = false;

void DFS(ll r){
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		cnt += av[i];
		if(cnt == c[r]){
			av[i] = false;
			a[r] = i;
			break;
		}
	}
	for(auto i : adj[r]){
		DFS(i);
	}
	for(ll i = 0 ; i < a[r] ; i++){
		ch |= av[i];
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll r;
	av.set();
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll p;
		cin>>p>>c[i]; p--; c[i]++;
		if(p != -1){
			adj[p].push_back(i);
		} else {
			r = i;
		}
	}
	DFS(r);
	if(ch){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(ll i = 0 ; i < n ; i++){
		cout<<a[i] + 1<<' ';
	}
	cout<<'\n';
	return 0;
}