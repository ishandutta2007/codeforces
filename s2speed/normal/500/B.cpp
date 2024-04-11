#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

vector<ll> adj[maxn] , v[maxn];
ll a[maxn] , c[maxn] , x[maxn] , o;

void DFS(ll r){
	c[r] = o;
	v[o].push_back(a[r]);
	for(auto i : adj[r]){
		if(c[i] != -1) continue;
		DFS(i);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , -1 , sizeof(c));
	memset(x , 0 , sizeof(x));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		for(ll j = 0 ; j < n ; j++){
			if(s[j] == '1'){
				adj[i].push_back(j);
			}
		}
	}
	o = 0;
	for(ll i = 0 ; i < n ; i++){
		if(c[i] != -1) continue;
		DFS(i); o++;
	}
	for(ll j = 0 ; j < o ; j++){
		sort(all(v[j]));
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<v[c[i]][x[c[i]]++]<<' ';
	}
	cout<<'\n';
	return 0;
}