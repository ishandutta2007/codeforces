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
typedef long double ld;

const int maxn=1e5+10,SQ=350;
const ll inf=1e18;

ll a[maxn],b[maxn],C;
vector<int>v[maxn];
vector<pll>block[SQ];
bool used[maxn];
ll dp[maxn];
pll p[maxn];

struct CHT{
    vector<pll>vec;
    void build(vector<pll>&vv){
        vec.clear();
  	for(pll p:vv)
	    add(p.F,p.S);
    }
    inline ll gety(int ind,ll x){
	return vec[ind].F*x+vec[ind].S;
    }
    bool bad(pll A,pll B,pll C){
	return (ld(B.S-A.S)/ld(B.F-A.F))<=(ld(B.S-C.S)/ld(B.F-C.F));
	//	return ld(B.S-A.S)*ld(B.F-C.F)>=ld(B.S-C.S)*ld(B.F-A.F);
    }
    void add(ll a,ll b){
	if(sz(vec)>0 && vec.back().F==a){
	    if(b<vec.back().S) vec.pop_back();
	    else return;
	}
	while(sz(vec)>1 && bad(vec[sz(vec)-2],vec[sz(vec)-1],{a,b}))
	    vec.pop_back();
	vec.PB({a,b});
    }
    ll ask(ll x){
	if(sz(vec)==0) return inf;
	int l=0,r=sz(vec)-1;
	ll ans=min(gety(0,x),gety(sz(vec)-1,x));
	while(l<r){
	    int mid=(l+r)>>1;
	    if(gety(mid,x)>gety(mid+1,x))
		l=mid+1,ans=gety(mid+1,x);
	    else
		r=mid,ans=gety(mid,x);
	}
	return ans;
    }
};CHT cht[SQ];

ll Ask(int pos,ll x){
    ll ans=inf;
    while(pos<maxn && pos%SQ){
	if(used[pos]) ans=min(ans,x*p[pos].F+p[pos].S);// overflow?
	pos++;
    }
    while(pos<maxn){
	ans=min(ans,cht[pos/SQ].ask(x));
	pos+=SQ;
    }
    return ans;
}

void Add(int pos,ll a,ll b){
    p[pos]={a,b};used[pos]=1;
    int id=pos/SQ;
    block[id].PB(p[pos]);
    int pt=sz(block[id])-2;
    while(pt>=0 && block[id][pt]<block[id][pt+1]) swap(block[id][pt],block[id][pt+1]),--pt;
    cht[id].build(block[id]);
}

void dfs(int u,int par=-1){
    int start=C++;
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	}
    }
    if(par==-1 || sz(v[u])!=1)
	dp[u]=Ask(start,a[u]);
    Add(start,b[u],dp[u]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
	cin>>a[i];
    for(int i=1;i<=n;i++)
	cin>>b[i];
    for(int i=2;i<=n;i++){
	int x,y;cin>>x>>y;
	v[x].PB(y);
	v[y].PB(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
	cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}

// Behold...  overflows are every where