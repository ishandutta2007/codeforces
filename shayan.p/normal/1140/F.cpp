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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int q,par[maxn],difx[maxn],dify[maxn];
vector<pair<pii,int> >qu[4*maxn];
vector<pair<int,pair< pair<int,ll> ,pii> > >vec;// id par ANS difx dify
vector<int>v1[maxn],v2[maxn];
ll ANS,ans[maxn];

void Add(int f,int s,pair<pii,int> p,int l=0,int r=q,int id=1){
    if(f>=s || l>=r || s<=l || r<=f) return;
    if(f<=l && r<=s) {qu[id].PB(p);return;}
    int mid=(l+r)>>1;
    Add(f,s,p,l,mid,2*id);
    Add(f,s,p,mid,r,2*id+1);
}

int Find(int u){
    return par[u]<0?u:Find(par[u]);
}
void Merge(int a,int b,int dx,int dy){
    a=Find(a),b=Find(b);
    assert(a!=b);
    if(par[a]>par[b]) swap(a,b);
    vec.PB({a,{ {par[a],ANS},{difx[a],dify[a]} } });
    vec.PB({b,{ {par[b],ANS},{difx[b],dify[b]} } });
    par[a]+=par[b];
    par[b]=a;
    ANS-=1ll*difx[a]*dify[a];
    ANS-=1ll*difx[b]*dify[b];
    ANS+=1ll*dx*dy;
    difx[a]=dx,dify[a]=dy;
}

void dfs(int l=0,int r=q,int u=1){
    int S=sz(vec);
    for(pair<pii,int> p:qu[u]){
	bool A=v1[p.F.F].empty(),B=v2[p.F.S].empty();
	if(A && B){
	    vec.PB({p.S,{ {-1,ANS},{0,0} } });
	    ++ANS;
	    difx[p.S]=dify[p.S]=1;
	}
	if(!A && B){
	    int num=Find(v1[p.F.F].back());
	    Merge(p.S,num,difx[num],dify[num]+1);
	}
	if(A && !B){
	    int num=Find(v2[p.F.S].back());
	    Merge(p.S,num,difx[num]+1,dify[num]);
	}
	if(!A && !B){
	    int num1=Find(v1[p.F.F].back()),num2=Find(v2[p.F.S].back());
	    if(num1!=num2)
		Merge(num1,num2,difx[num1]+difx[num2],dify[num1]+dify[num2]);
	    num1=Find(num1);
	    vec.PB({p.S, { {par[p.S],ANS} , {0,0} } } );
	    par[p.S]=num1;
	}
	v1[p.F.F].PB(p.S);
	v2[p.F.S].PB(p.S);
    }
    if(r-l>1){
	int mid=(l+r)>>1;
	dfs(l,mid,2*u);
	dfs(mid,r,2*u+1);
    }
    else{
	ans[l]=ANS;
    }
    for(pair<pii,int> p:qu[u]){
	v1[p.F.F].pop_back();
	v2[p.F.S].pop_back();
    }
    while(sz(vec)!=S){
	auto X=vec.back();
	vec.pop_back();
	par[X.F]=X.S.F.F;
	ANS=X.S.F.S;
	difx[X.F]=X.S.S.F;
	dify[X.F]=X.S.S.S;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(par,-1,sizeof par);
    cin>>q;
    map<pii,int>MP;
    int C=0;
    for(int i=0;i<q;i++){
	pii p;cin>>p.F>>p.S;
	if(MP.count(p)){
	    Add(MP[p],i,{p,C++});
	    MP.erase(p);
	}
	else{
	    MP[p]=i;
	}
    }
    for(auto p:MP){
	Add(p.S,q,{p.F,C++});
    }
    dfs();
    for(int i=0;i<q;i++){
	cout<<ans[i]<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.