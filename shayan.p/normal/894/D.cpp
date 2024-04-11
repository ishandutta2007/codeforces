#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;
const ll maxn=1e6+10;
vector<ll>pre[maxn],sum[maxn];
ll n,l_par[maxn];
ll binary(ll targ,ll id,ll l,ll r){// returns ind such that pre[i] is less or equal to targ and ind is the greatest
	ll ind=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(pre[id][mid]<=targ){ind=mid;l=mid+1;}
		else r=mid-1;
	}
	return ind;
}
inline ll query(ll v,ll h){
	ll ind=binary(h,v,0,pre[v].size()-1);
	return h*(ind+1)-sum[v][ind];
}
void Merge(vector<ll>&v,vector<ll>&a,vector<ll>&b,ll A,ll B){
	ll curr_a=0,curr_b=0;
	ll sza=a.size(),szb=b.size();
	for(ll i=0;i<sza+szb;i++){
		if(curr_a==sza){
			v.PB(B+b[curr_b++]);
		}
		else if(curr_b==szb){
			v.PB(A+a[curr_a++]);
		}
		else{
			if(A+a[curr_a]<B+b[curr_b])	v.PB(A+a[curr_a++]);
			else v.PB(B+b[curr_b++]);
		}
	}
}
void pre_compute(ll v=1){
	pre[v].PB(0);
	if(v*2<=n&&v*2+1<=n){
		pre_compute(v*2);
		pre_compute(v*2+1);
		Merge(pre[v],pre[2*v],pre[2*v+1],l_par[2*v],l_par[2*v+1]);
	}
	else if(v*2<=n){
		pre_compute(v*2);
		for(ll i=0;i<pre[2*v].size();i++)pre[v].PB(l_par[2*v]+pre[2*v][i]);
	}
	for(ll i=0;i<pre[v].size();i++)sum[v].PB((i==0?0:sum[v][i-1])+pre[v][i]);
}
int main(){
	ll m;scanf("%lld%lld",&n,&m);
	for(ll i=2;i<=n;i++)scanf("%lld",&l_par[i]);
	pre_compute();
	for(ll i=0;i<m;i++){
		ll v,h;scanf("%lld%lld",&v,&h);
		ll ans=query(v,h);
		while(v!=1&&h>=0){
			h-=l_par[v];
			if(h<0)break;
			ans+=h;
			ll dad=v/2,brother=((v%2)?v-1:v+1);
			if(brother<=n){
				ll H=h-l_par[brother];
				if(H>=0)ans+=query(brother,H);
			}
			v=dad;
		}
		printf("%lld\n",ans);
	}
}