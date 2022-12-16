#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=510;
ll n,m,q;
map<ll,ll>mp;
bool grid[maxn][maxn];
ll Max[maxn];
ll row(ll i){
	ll ans=0,num=0;
	for(ll j=0;j<m;j++){
		if(grid[i][j]==1)
			num++;
		else{
			ans=max(ans,num);
			num=0;
		}
	}
	ans=max(ans,num);
	return ans;
}
int main(){
	cin>>n>>m>>q;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin>>grid[i][j];
		}
		Max[i]=row(i);
		mp[Max[i]]++;
	}
	for(ll i=0;i<q;i++){
		ll a,b;cin>>a>>b;
		a--;b--;
		grid[a][b]=!grid[a][b];
		if(--mp[Max[a]]==0)mp.erase(Max[a]);
		Max[a]=row(a);
		mp[Max[a]]++;
		cout<<(--mp.end())->F<<endl;
	}
}