#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

ll tr[MAXN][26] , last = 0;
bitset<MAXN> dp , pd;
vector<ll> adj[MAXN];

void insert(string h){
	ll v = 0 , hs = h.size();
	for(ll i = 0 ; i < hs ; i++){
		ll j = h[i] - 'a';
		if(tr[v][j] == -1){
			tr[v][j] = ++last;
			adj[v].push_back(last);
		}
		v = tr[v][j];
	}
	return;
}

void DFS(ll r){
	for(auto i : adj[r]){
		DFS(i);
	}
	if(adj[r].size() == 0){
		dp[r] = false;
		pd[r] = true;
	}
	for(auto i : adj[r]){
		dp[r] = !dp[i] | dp[r];
		pd[r] = !pd[i] | pd[r];
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(tr , -1 , sizeof(tr));
	ll n , k;
	cin>>n>>k;
	string s;
	for(ll i = 0 ; i < n ; i++){
		cin>>s;
		insert(s);
	}
	DFS(0);
	if(dp[0] & pd[0]){
		cout<<"First\n";
		return 0;
	}
	if(!dp[0]){
		cout<<"Second\n";
		return 0;
	}
	cout<<(k % 2 ? "First\n" : "Second\n");
	return 0;
}

/*

*/