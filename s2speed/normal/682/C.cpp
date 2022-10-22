#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5;

vector< pair<ll , ll> > adj[MAX_N];
ll a[MAX_N] , dp[MAX_N] , ans = 0 , zdad = 0 , bad = 0;
bool mark[MAX_N];
vector<ll> v;

void DFS(ll r){
	ll dad , rs = adj[r].size();
	if(r == 0){
		dad = -1;
		dp[r] = 0;
	} else {
		dad = v[v.size() - 1];
		dp[r] = max(0LL , dp[dad] + zdad);
	}
	if(dp[r] > a[r]){
		bad++;
	}
	if(bad > 0){
		ans++;
	}
	v.push_back(r);
	mark[r] = true;
	for(int e = 0 ; e < rs ; e++){
		ll i = adj[r][e].first;
		if(mark[i] == false){
			zdad = adj[r][e].second;
			DFS(i);
		}
	}
	if(dp[r] > a[r]){
		bad--;
	}
	v.pop_back();
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		mark[i] = false;
	}
	for(int i = 1 ; i < n ; i++){
		ll inp1 , inp2;
		cin>>inp1>>inp2; inp1--;
		adj[i].push_back( make_pair(inp1 , inp2) ); adj[inp1].push_back( make_pair(i , inp2) );
	}
//	cout<<"----------------------------\n";
	DFS(0);
/*	for(int i = 0 ; i < n ; i++){
		cout<<dp[i]<<" ";
	}*/
	cout<<ans<<"\n";
	return 0;
}