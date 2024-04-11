#include<bits/stdc++.h>
#define ll int
using namespace std;
const ll maxn=35010;
ll a[maxn],val[4*maxn],lazy[4*maxn],dp[60][maxn],last[maxn],vis[maxn];
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
void restart(ll ind){
	memset(val,0,sizeof val);
	memset(lazy,0,sizeof lazy);
	for(ll i=0;i<maxn;i++)add(i,dp[ind-1][i]);
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
void plus_one(ll f,ll s,ll l=0,ll r=maxn,ll ind=1){
	if(r<l)return;
	get(l,r,ind);
	if(r<f||s<l)return;
	if(f<=l&&r<=s){
		lazy[ind]++;
		get(l,r,ind);
		return;
	}
	ll mid=(l+r)/2;
	plus_one(f,s,l,mid,2*ind);
	plus_one(f,s,mid+1,r,2*ind+1);
	val[ind]=max(val[2*ind],val[2*ind+1]);
}
int main(){
	ll n,k;scanf("%d%d",&n,&k);
	for(ll i=1;i<=n;i++)scanf("%d",&a[i]);
	for(ll i=0;i<maxn;i++)vis[i]=-1;
	for(ll i=1;i<=n;i++){
		last[i]=vis[a[i]];
		vis[a[i]]=i;
	}
	for(ll i=1;i<=k;i++){
		restart(i);
		for(ll j=1;j<=n;j++){
			plus_one(last[j],j-1);// index x in segment: dp[i-1][x]+rest of the set that will be made from x+1 to j-1
			dp[i][j]=Max(0,j-1);
		}
	}
	cout<<dp[k][n];
}