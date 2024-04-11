#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=2e5+10;
vector<pll>en[maxn];
ll W[maxn],dp[maxn],val[4*maxn],lazy[4*maxn];
void get(ll l,ll r,ll ind){
	val[ind]+=lazy[ind];
	if(r!=l){
		lazy[2*ind]+=lazy[ind];
		lazy[2*ind+1]+=lazy[ind];
	}
	lazy[ind]=0;
}
void add(ll targ,ll value,ll l=0,ll r=maxn,ll ind=1){
	if(r<l)return;
	if(r<targ||targ<l)return;
	val[ind]=max(val[ind],value);
	if(l!=r){
		ll mid=(l+r)/2;
		add(targ,value,l,mid,2*ind);
		add(targ,value,mid+1,r,2*ind+1);
	}
}
ll Max(ll f,ll s,ll l=0,ll r=maxn,ll ind=1){
	if(r<l)return 0;
	get(l,r,ind);
	if(r<f||s<l)return 0;
	if(f<=l&&r<=s){
	return val[ind];
	}
	ll mid=(l+r)/2,ans=0;
	ans=max(ans,Max(f,s,l,mid,2*ind));
	ans=max(ans,Max(f,s,mid+1,r,2*ind+1));
	return ans;
}
void Plus(ll f,ll s,ll money,ll l=0,ll r=maxn,ll ind=1){
	if(r<l)return;
	get(l,r,ind);
	if(r<f||s<l)return;
	if(f<=l&&r<=s){
		lazy[ind]+=money;
		get(l,r,ind);
		return;
	}
	ll mid=(l+r)/2;
	Plus(f,s,money,l,mid,2*ind);
	Plus(f,s,money,mid+1,r,2*ind+1);
	val[ind]=max(val[2*ind],val[2*ind+1]);
}
int main(){
	ll n,m;cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>W[i];
	for(ll i=0;i<m;i++){
		ll a,b,w;cin>>a>>b>>w;
		en[b].PB(MP(a,w));
	}
	for(ll i=1;i<=n;i++){
		Plus(0,i-1,-W[i]);
		for(ll j=0;j<en[i].size();j++){
			Plus(0,en[i][j].F-1,en[i][j].S);
		}
		dp[i]=max(dp[i-1],Max(0,i-1));
		add(i,dp[i]);
	}
	cout<<dp[n];
}