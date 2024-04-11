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

const ll MAXN = 2e2 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

vector<ll> adj[MAXN];
ll c[MAXN] , x = 0;
string ans;
vector<pll> q;

void DFS(ll r){
	c[r] = x;
	for(auto i : adj[r]){
		if(~c[i]) continue;
		DFS(i);
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , -1 , sizeof(c));
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--; if(v > u) swap(v , u);
		q.push_back({v , u});
	}
	for(ll i = 0 ; i < m ; i++){
		for(ll j = i + 1 ; j < m ; j++){
			if(q[j].second > q[i].first && q[j].second < q[i].second && q[j].first < q[i].first){
				adj[i].push_back(j + m); adj[j + m].push_back(i);
				adj[j].push_back(i + m); adj[i + m].push_back(j);
			}
			if(q[j].first > q[i].first && q[j].first < q[i].second && q[j].second > q[i].second){
				adj[i].push_back(j + m); adj[j + m].push_back(i);
				adj[j].push_back(i + m); adj[i + m].push_back(j);
			}
		}
	}
	for(ll i = 0 ; i < 2 * m ; i++){
		if(~c[i]) continue;
		DFS(i);
		x++;
	}
	for(int i = 0 ; i < m ; i++){
		if(c[i] == c[i + m]){
			cout<<"Impossible\n";
			return 0;
		}
		if(c[i] < c[i + m]){
			ans += 'i';
		} else {
			ans += 'o';
		}
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/