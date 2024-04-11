// Believe in yourself...
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e4+10;
vector<ll>v[maxn];
ll color[maxn],C[maxn],ans;
void dfs(ll u){
	if(C[u]!=color[u]){
		ans++;
		C[u]=color[u];
	}
	for(ll i=0;i<v[u].size();i++){
		ll y=v[u][i];
		C[y]=C[u];
		dfs(y);
	}
}
int main(){
	ll n;cin>>n;
	for(ll i=2;i<=n;i++){
		ll x;cin>>x;
		v[x].PB(i);
	}
	for(ll i=1;i<=n;i++){
		cin>>color[i];
	}
	dfs(1);
	cout<<ans;
}