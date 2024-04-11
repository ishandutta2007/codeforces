#include<bits/stdc++.h>
#include<math.h>

#define gcd __gcd

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5;

vector<ll> adj[MAX_N] , v , d;
ll a[MAX_N] , ans[MAX_N] , o[500];
bool mark[MAX_N];

void DFS(ll r){
	ll rs = adj[r].size() , dad;
	mark[r] = true;
	if(r != 0){
		dad = v[v.size() - 1];
		ans[r] = gcd(a[r] , ans[dad]);
	} else {
		ans[0] = 0;
	}
	v.push_back(r);
	for(int e = 0 ; e < rs ; e++){
		ll i = adj[r][e];
		if(mark[i] == false){
			DFS(i);
		}
	}
	v.pop_back();
	return;
}

ll ds;

void DDFS(ll r){
	ll rs = adj[r].size();
	mark[r] = true;
	for(int i = 0 ; i < ds ; i++){
		if(a[r] % d[i] != 0){
			o[i]++;
		}
		if(o[i] <= 1){
			ans[r] = max(ans[r] , d[i]);
		}
	}
	for(int e = 0 ; e < rs ; e++){
		int i = adj[r][e];
		if(mark[i] == false){
			DDFS(i);
		}
	}
	for(int i = 0 ; i < ds ; i++){
		if(a[r] % d[i] != 0){
			o[i]--;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		mark[i] = false;
		cin>>a[i];
	}
	for(int i = 1 ; i < n ; i++){
		ll u , v;
		cin>>u>>v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	DFS(0);
	for(int i = 1 ; i <= sqrt(a[0]) ; i++){
		if(a[0] % i == 0){
			double h = i;
			d.push_back(i);
			if(i != sqrt(a[0])){
				d.push_back(a[0] / i);
			}
		}
	}
	sort(d.begin() , d.end() , greater<ll>());
	ds = d.size();
	for(int i = 0 ; i < ds ; i++){
		o[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		mark[i] = false;
	}
	DDFS(0);
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}