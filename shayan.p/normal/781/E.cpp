// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=1e5+10,inf=2e9+10,mod=1e9+7;

map<int,pair<pii,int> >mp;
multiset<pii>st[maxn];

int mn[4*maxn],h,n;

void put(int pos,int x,int l=0,int r=n,int id=1){
    if(pos<l || r<=pos) return;
    if(r-l==1){mn[id]=x; return;}
    int mid=(l+r)>>1;
    put(pos,x,l,mid,2*id);
    put(pos,x,mid,r,2*id+1);
    mn[id]=min(mn[2*id],mn[2*id+1]);
}
pii fnd(int f,int s,int x,int l=0,int r=n,int id=1){
    if(f>=s || l>=r || r<=f || s<=l || mn[id]>x) return {inf,inf};
    if(r-l==1) return {mn[id],l};
    int mid=(l+r)>>1;
    if(f<=l && r<=s){
	if(mn[2*id]<=x) return fnd(f,s,x,l,mid,2*id);
	else return fnd(f,s,x,mid,r,2*id+1);
    }
    pii p=fnd(f,s,x,l,mid,2*id);
    if(p.F>x) return fnd(f,s,x,mid,r,2*id+1);
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>h>>n>>q;
    while(q--){
	int a,b,c,d;cin>>a>>b>>c>>d;
	mp[a]={{--b,c},d};
    }
    for(int i=0;i<n;i++){
	st[i].insert({h+1,1});
    }
    fill(mn,mn+4*maxn,h+1);
    while(sz(mp)){
	auto IT=*mp.rbegin();
	mp.erase(IT.F);
	int l=IT.S.F.F,r=IT.S.F.S,h=IT.F,x=h+IT.S.S,sm=0;
	while(true){
	    pii p=fnd(l,r,x);
	    if(p.F>x) break;
	    sm=(sm + st[p.S].begin()->S)%mod;
	    st[p.S].erase(st[p.S].begin());
	    if(st[p.S].empty()) put(p.S,inf);
	    else put(p.S,st[p.S].begin()->F);
	}
	if(l==0)
	    st[r].insert({h,2ll*sm %mod});
	else if(r==n)
	    st[l-1].insert({h,2ll*sm %mod});
	else
	    st[l-1].insert({h,sm}),st[r].insert({h,sm});
	if(l!=0) put(l-1,st[l-1].begin()->F);
	if(r!=n) put(r  ,st[r  ].begin()->F);
    }
    int ans=0;
    for(int i=0;i<n;i++){
	for(auto x:st[i])
	    ans=(ans+x.S)%mod;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.