#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
 
#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
 
ll arr[1010101];
ll n;
vector<ll> v[301010];
vector<ll> dv[301010];
ll par[301010];
ll dep[301010];
ll sz[301010];
ll top[301010];
 
ll pl[1010101];
ll ml[1010101];
 
ll ppl[1010101];
ll mml[1010101];
ll cost[1010101];
 
void dfs1(ll x){
	sz[x]=1;
	for(auto n:v[x]){
		if(sz[n]) continue;
		dep[n]=dep[x]+1;
		par[n]=x;
		dfs1(n);
		sz[x]+=sz[n];
		pl[x]+=pl[n];
		ml[x]+=ml[n];
		dv[x].pb(n);
		if(sz[n]>sz[dv[x][0]]) swap(dv[x][0],dv[x].back());
	}	
}
 
ll np;
ll in[301010];
ll out[301010];
 
void dfs2(ll x){
	np++;
	in[x]=np;
	for(auto k:dv[x]){
		if(dv[x][0]==k) top[k]=top[x];
		else top[k]=k;
		dfs2(k);
	}
	out[x]=np;
}
 
struct Tree{
    ll val,laz;
};
 
Tree tree[1040404];
 
ll init(ll s,ll e,ll nod){
    if(s==e)
        return tree[nod].val=ppl[s];
    return tree[nod].val=init(s,(s+e)/2,nod*2)
            +init((s+e)/2+1,e,nod*2+1);
}
 
void uptr(ll dif,ll l,ll r,ll s,ll e,ll nod)
{
    if(tree[nod].laz!=0){
        tree[nod].val+=(e-s+1)*tree[nod].laz;
        if(s!=e){
            tree[nod*2].laz+=tree[nod].laz;
            tree[nod*2+1].laz+=tree[nod].laz;
        }
        tree[nod].laz=0;
    }
 
    if(r<s||e<l) return;
 
    if(l<=s&&e<=r){
        tree[nod].val+=(e-s+1)*dif;
        if(s!=e){
            tree[nod*2].laz+=dif;
            tree[nod*2+1].laz+=dif;
        }
        return;
    }
    uptr(dif,l,r,s,(s+e)/2,nod*2);
    uptr(dif,l,r,(s+e)/2+1,e,nod*2+1);
    tree[nod].val = tree[nod*2].val+tree[nod*2+1].val;
}
 
ll sum(ll l,ll r,ll s,ll e,ll nod)
{
    //printf("%lld %lld %lld %lld %lld %lld %lld\n",l,r,s,e,nod,tree[nod].val,tree[nod].laz);
    if(tree[nod].laz!=0){
        tree[nod].val += (e-s+1)*tree[nod].laz;
        if(s!=e){
            tree[nod*2].laz+=tree[nod].laz;
            tree[nod*2+1].laz+=tree[nod].laz;
        }
        tree[nod].laz=0;
    }
 
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return tree[nod].val;
    return sum(l,r,s,(s+e)/2,nod*2)+
            sum(l,r,(s+e)/2+1,e,nod*2+1);
}
 
 
Tree tree2[1040404];
 
ll init2(ll s,ll e,ll nod){
    if(s==e)
        return tree2[nod].val=mml[s];
    return tree2[nod].val=init2(s,(s+e)/2,nod*2)
            +init2((s+e)/2+1,e,nod*2+1);
}
 
void uptr2(ll dif,ll l,ll r,ll s,ll e,ll nod)
{
    if(tree2[nod].laz!=0){
        tree2[nod].val+=(e-s+1)*tree2[nod].laz;
        if(s!=e){
            tree2[nod*2].laz+=tree2[nod].laz;
            tree2[nod*2+1].laz+=tree2[nod].laz;
        }
        tree2[nod].laz=0;
    }
 
    if(r<s||e<l) return;
 
    if(l<=s&&e<=r){
        tree2[nod].val+=(e-s+1)*dif;
        if(s!=e){
            tree2[nod*2].laz+=dif;
            tree2[nod*2+1].laz+=dif;
        }
        return;
    }
    uptr2(dif,l,r,s,(s+e)/2,nod*2);
    uptr2(dif,l,r,(s+e)/2+1,e,nod*2+1);
    tree2[nod].val = tree2[nod*2].val+tree2[nod*2+1].val;
}
 
ll sum2(ll l,ll r,ll s,ll e,ll nod)
{
    //printf("%lld %lld %lld %lld %lld %lld %lld\n",l,r,s,e,nod,tree[nod].val,tree[nod].laz);
    if(tree2[nod].laz!=0){
        tree2[nod].val += (e-s+1)*tree2[nod].laz;
        if(s!=e){
            tree2[nod*2].laz+=tree2[nod].laz;
            tree2[nod*2+1].laz+=tree2[nod].laz;
        }
        tree2[nod].laz=0;
    }
 
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return tree2[nod].val;
    return sum2(l,r,s,(s+e)/2,nod*2)+
            sum2(l,r,(s+e)/2+1,e,nod*2+1);
}
 
bool sf(ll a,ll b){
	return cost[a]<cost[b];
}
 
void ans(ll a,ll b ,ll c){
	ll ret=0;
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]]) swap(a,b);
		ll x=top[b];
		uptr(-c,in[x],in[b],1,n,1);
		uptr2(-c,in[x],in[b],1,n,1);
		b=par[x];
	}
	if(dep[a]>dep[b]) swap(a,b);
	uptr(-c,in[a],in[b],1,n,1);
	uptr2(-c,in[a],in[b],1,n,1);
}
 
 
ll sol(ll x){
	ll k=min(sum(in[x],in[x],1,n,1),sum2(in[x],in[x],1,n,1));
	k=max(k,0LL);
	if(k!=0) ans(1,x,k);
	uptr(-10000000000LL,in[x],out[x],1,n,1);
	uptr2(-10000000000LL,in[x],out[x],1,n,1);
	return k;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll i,j,k,l,m;
	cin>>n;
 
	for(i=1;i<=n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		cost[i]=a;
		if(b==1&&c==0) ml[i]=1;
		if(b==0&&c==1) pl[i]=1;
		arr[i]=i;
	}
	ll ans=0;
 
	for(i=1;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
 
	if(ml[1]!=pl[1]){
		cout<<-1;
		return 0;
	}
 

	for(i=1;i<=n;i++){
		mml[in[i]]=ml[i];
		ppl[in[i]]=pl[i];
	}

	init(1,n,1);
	init2(1,n,1);
	


	sort(arr+1,arr+1+n,sf);
	for(i=1;i<=n;i++){
		ll x=arr[i];
		ans+=sol(x)*cost[x]*2;
//		printf("%lld %lld %lld %lld %lld\n",i,x,ml[x],pl[x],y);
//		for(j=1;j<=n;j++){
//			printf("%lld %lld %lld\n",j,sum(in[j],in[j],1,n,1),sum2(in[j],in[j],1,n,1));
//		}
	}
 
	cout<<ans;
 
}