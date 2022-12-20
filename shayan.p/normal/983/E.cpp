// Phoenix

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

const int maxn=2e5+10,inf=1e9;

vector<int>v[maxn],vec[maxn],val[4*maxn];
int segf[maxn],segs[maxn],sp1[20][maxn],sp2[20][maxn],h[maxn],C,n;

void Ok(int &u,int y){
    if(u==0 || h[u]>h[y])
	u=y;
}

void dfs1(int u,int par=0,int H=1){
    sp1[0][u]=par;
    for(int i=1;i<20;i++)
	sp1[i][u]=sp1[i-1][sp1[i-1][u]];
    h[u]=H;
    segf[u]=++C;
    for(int y:v[u]){
	if(y!=par)
	    dfs1(y,u,H+1);
    }
    segs[u]=C;
}

void dfs2(int u,int par=-1){
    for(int y:v[u]){
	if(y!=par){
	    dfs2(y,u);
	    Ok(sp2[0][u],sp2[0][y]);
	}
    }
}

void dfs3(int u,int par=-1){
    for(int i=1;i<20;i++)
	sp2[i][u]=sp2[i-1][sp2[i-1][u]];
    for(int y:v[u]){
	if(y!=par)
	    dfs3(y,u);
    }
}

int LCA(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    for(int i=19;i>=0;i--){
	if(h[sp1[i][a]]>=h[b])
	    a=sp1[i][a];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--){
	if(sp1[i][a]!=sp1[i][b])
	    a=sp1[i][a],b=sp1[i][b];
    }
    return sp1[0][a];
}

pii solve(int a,int H){ 
    int cnt=0;
    for(int i=19;i>=0;i--){
	if(h[sp2[i][a]]>H)
	    cnt+=(1<<i),a=sp2[i][a];
    }
    if(cnt==(1<<20)-1) return {inf,inf};
    return {cnt,a};
}

void build(int l=1,int r=n,int id=1){
    if(l==r){
	val[id]=vec[l];
	sort(val[id].begin(),val[id].end());
	return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    val[id].resize(sz(val[2*id])+sz(val[2*id+1]));
    merge(val[2*id].begin(),val[2*id].end(),val[2*id+1].begin(),val[2*id+1].end(),val[id].begin());
}

bool ask(int f1,int s1,int f2,int s2,int l=1,int r=n,int id=1){
    if(f1>s1 || f2>s2 || l>r || s1<l || r<f1) return 0;
    if(f1<=l && r<=s1) return upper_bound(val[id].begin(),val[id].end(),s2)!=lower_bound(val[id].begin(),val[id].end(),f2);
    int mid=(l+r)>>1;
    return ask(f1,s1,f2,s2,l,mid,2*id)|ask(f1,s1,f2,s2,mid+1,r,2*id+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++){
	int x;cin>>x;
	v[x].PB(i);
	v[i].PB(x);
    }
    dfs1(1);
    int m;cin>>m;
    for(int i=1;i<=n;i++)
	sp2[0][i]=i;
    while(m--){
	int a,b;cin>>a>>b;
	int lc=LCA(a,b);
	Ok(sp2[0][a],lc);
	Ok(sp2[0][b],lc);
    	vec[segf[a]].PB(segf[b]);
	vec[segf[b]].PB(segf[a]);
    }
    build();
    dfs2(1);
    dfs3(1);
    int q;cin>>q;
    while(q--){
	int a,b;cin>>a>>b;
	int lc=LCA(a,b),ans=inf;
	if(lc==a){
	    ans=solve(b,h[a]).F+1;
	}
	else if(lc==b){
	    ans=solve(a,h[b]).F+1;
	}
	else{
	    pii A=solve(a,h[lc]),B=solve(b,h[lc]);
	    if(A.F==inf || B.F==inf){
		ans=inf;
	    }
	    else{
		ans=A.F+B.F+2-ask(segf[A.S],segs[A.S],segf[B.S],segs[B.S]);
	    }
	}
	if(ans>=inf) ans=-1;
	cout<<ans<<"\n";
    }
    return 0;
}