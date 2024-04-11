// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
ll w[maxn],SS;
int n,l,C=1,dp[maxn];

pii seg[maxn];

ll mx[4*maxn],mn[4*maxn],lz1[4*maxn],lz2[4*maxn];
int mxh[4*maxn],hid[maxn],h[maxn];

void dfs0(int u,int hh=0){
    seg[u].F=C;
    for(int y:v[u]){
	h[y]=h[u]+1;
	dfs0(y,hh+1);
    }
    hid[C]=h[u]=hh;
    seg[u].S=C++;
}

void build(int l=1,int r=maxn,int id=1){
    if((r-l)==1){
	mxh[id]=hid[l];
	return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*id);
    build(mid,r,2*id+1);
    mxh[id]=max(mxh[2*id],mxh[2*id+1]);
}

void get(int l,int r,int id){
    mn[id]+=lz1[id];
    mx[id]+=lz2[id];
    if((r-l)>1){
	lz1[2*id]+=lz1[id];
	lz1[2*id+1]+=lz1[id];
	lz2[2*id]+=lz2[id];
	lz2[2*id+1]+=lz2[id];
    }
    lz1[id]=lz2[id]=0;
}
ll ask(int f,int s,int l=1,int r=maxn,int id=1){// tooye mn ke ba add1 kar mikone
    if(f>=s || l>=r)return inf;
    get(l,r,id);
    if(s<=l || r<=f)return inf;
    if(f<=l && r<=s)return mn[id];
    int mid=(l+r)/2;
    return min(ask(f,s,l,mid,2*id),ask(f,s,mid,r,2*id+1));
}
void add1(int f,int s,ll x,int l=1,int r=maxn,int id=1){// be mn ezafe mikone
    if(f>=s || l>=r)return;
    get(l,r,id);
    if(s<=l || r<=f)return;
    if(f<=l && r<=s){
	lz1[id]+=x;
	get(l,r,id);
	return;
    }
    int mid=(l+r)/2;
    add1(f,s,x,l,mid,2*id);
    add1(f,s,x,mid,r,2*id+1);
    mn[id]=min(mn[2*id],mn[2*id+1]);
}
void add2(int f,int s,ll x,int l=1,int r=maxn,int id=1){
    if(f>=s || l>=r)return;
    get(l,r,id);
    if(s<=l || r<=f)return;
    if(f<=l && r<=s && (mx[id]+x)<=SS){
	lz2[id]+=x;
	get(l,r,id);
	return;
    }
    if((r-l)==1){
	mx[id]=-inf;
	add1(l,r,inf);
	return;
    }
    int mid=(l+r)/2;
    add2(f,s,x,l,mid,2*id);
    add2(f,s,x,mid,r,2*id+1);
    mx[id]=max(mx[2*id],mx[2*id+1]);
}
void del(int f,int s,int h,int l=1,int r=maxn,int id=1){
    if(f>=s || l>=r || s<=l || r<=f)return;
    if(f<=l && r<=s && mxh[id]<=h)return;
    if((r-l)==1){
	mxh[id]=-1000000000;
	add1(l,r,inf);
	return;
    }
    int mid=(l+r)/2;
    del(f,s,h,l,mid,2*id);
    del(f,s,h,mid,r,2*id+1);
    mxh[id]=max(mxh[2*id],mxh[2*id+1]);
}

void dfs(int u){
    int sm=0;
    for(int y:v[u])
	dfs(y),sm+=dp[y];
    for(int y:v[u])
	add1(seg[y].F,seg[y].S+1,sm-dp[y]);
    add1(seg[u].S,seg[u].S+1,sm);
    add2(seg[u].F,seg[u].S+1,w[u]);
    del(seg[u].F,seg[u].S+1,h[u]+l-1);
    dp[u]=ask(seg[u].F,seg[u].S+1)+1;
}

int main(){   
    scanf("%d%d%lld",&n,&l,&SS);
    for(int i=1;i<=n;i++){
	scanf("%lld",&w[i]);
    }
    for(int i=2;i<=n;i++){
	int x;scanf("%d",&x);
	v[x].PB(i);
    }
    for(int i=1;i<=n;i++){
	if(w[i]>SS){
	    printf("-1\n");
	    return 0;
	}
    }
    dfs0(1);
    build();
    dfs(1);
    printf("%d\n",dp[1]);
}