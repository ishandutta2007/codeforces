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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

map<pii,int> mp;
vector<pii>val[4*maxn];
vector<pair<int,pii> >vec;
bool bad[maxn];
int pr[maxn],xr[maxn];

void add(int f,int s,pii p,int l=0,int r=maxn,int id=1){
    if(f>=s || l>=r || r<=f || s<=l) return;
    if(f<=l && r<=s) {val[id].PB(p);return;}
    int mid=(l+r)>>1;
    add(f,s,p,l,mid,2*id);
    add(f,s,p,mid,r,2*id+1);
}

pii Find(int u){
    if(pr[u]<0) return {u,0};
    pii ans=Find(pr[u]); ans.S^=xr[u];
    return ans;
}
bool Merge(int a,int b){
    pii A=Find(a),B=Find(b);
    if(A.F==B.F && A.S!=B.S) return 1;
    if(A.F==B.F && A.S==B.S) return 0;
    if(pr[A.F]>pr[B.F]) swap(A,B);
    vec.PB({A.F,{pr[A.F],xr[A.F]}});
    vec.PB({B.F,{pr[B.F],xr[B.F]}});
    pr[A.F]+=pr[B.F];
    pr[B.F]=A.F;
    xr[B.F]=A.S^B.S^1;
    return 1;
}

void redo(int num){
    while(sz(vec)>num){
	auto x=vec.back();
	vec.pop_back();
	pr[x.F]=x.S.F;
	xr[x.F]=x.S.S;
    }
}

void dfs(int l=0,int r=maxn,int id=1){
    bool is=0;
    int num=sz(vec);
    for(pii p:val[id]){
 	if(!Merge(p.F,p.S)){
	    is=1;
	    break;
	}
    }
    if(is){
	for(int i=l;i<r;i++)
	    bad[i]=1;
    }
    else if(r-l>1){
	int mid=(l+r)>>1;
	dfs(l,mid,2*id);
	dfs(mid,r,2*id+1);
    }
    redo(num);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(pr,-1,sizeof pr);
    int n,q;cin>>n>>q;
    for(int i=0;i<q;i++){
	int a,b;cin>>a>>b;
	if(a>b) swap(a,b);
	if(mp.count({a,b}))
	    add(mp[{a,b}],i,{a,b}),mp.erase({a,b});
	else
	    mp[{a,b}]=i;
    }
    for(auto p:mp){
	add(p.S,q+5,p.F);
    }
    dfs();
    for(int i=0;i<q;i++)
	cout<<(bad[i]?"NO":"YES")<<"\n";
}