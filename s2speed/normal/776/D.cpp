#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll {ll first , second , third;};
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

bitset<MAXN> r;
vector<int> v[MAXN] , adj[MAXN];
int c[MAXN] , x = 0;

void DFS(int r){
	c[r] = x;
	for(auto i : adj[r]){
		if(c[i] != -1) continue;
		DFS(i);
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , -1 , sizeof(c));
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		bool v;
		cin>>v;
		r[i] = v;
	}
	for(int i = 0 ; i < m ; i++){
		int l;
		cin>>l;
		for(int j = 0 ; j < l ; j++){
			int q;
			cin>>q; q--;
			v[q].push_back(i);
		}
	}
	for(int i = 0 ; i < n ; i++){
		int o = v[i][0] , p = v[i][1];
		if(r[i]){
			adj[o].push_back(p); adj[p].push_back(o);
			adj[o + m].push_back(p + m); adj[p + m].push_back(o + m);
		} else {
			adj[o].push_back(p + m); adj[p + m].push_back(o);
			adj[o + m].push_back(p); adj[p].push_back(o + m);
		}
	}
	for(int i = 0 ; i < 2 * m ; i++){
		if(c[i] != -1) continue;
		DFS(i);
		x++;
	}
	for(int i = 0 ; i < m ; i++){
		if(c[i] == c[i + m]){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}

/*

*/