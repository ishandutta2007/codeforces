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

const int maxn=1e5+10,Max=1e7+10,mod=1e9+7;
const ll inf=1e18;

int nxt[Max],ans[maxn],a[maxn],A[maxn],B[maxn],h[maxn],sp[20][maxn],C;
map<int,pair<vector<pii>,vector<pii> > >mp;
vector<int>v[maxn];
pii seg[maxn];

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod){
	if(b&1)
	    ans=1ll*ans*a %mod;
    }
    return ans;
}

void dfs(int u,int par=0){
    sp[0][u]=par;
    for(int i=1;i<20;i++){
	sp[i][u]=sp[i-1][sp[i-1][u]];
    }
    h[u]=h[par]+1;
    seg[u].F=C++;
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	}
    }
    seg[u].S=C;
}

int Lca(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    for(int i=19;i>=0;i--){
	if(h[sp[i][a]]>=h[b])
	    a=sp[i][a];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--){
	if(sp[i][a]!=sp[i][b])
	    a=sp[i][a],b=sp[i][b];
    }
    return sp[0][a];
}

struct Fenwick{
    int sm[maxn];
    vector<int>tdo;
    Fenwick(){
	memset(sm,0,sizeof sm);
    }
    void Restart(){
	for(int x:tdo)
	    sm[x]=0;
	tdo.clear();
    }
    void _Add(int pos,int x){
	for(pos=pos+3;pos<maxn;pos+=pos & -pos)
	    sm[pos]+=x,tdo.PB(pos);
    }
    void Add(int f,int s,int x){
	_Add(f,x),_Add(s,-x);
    }
    int Ask(int pos){
	int ans=0;
	for(pos=pos+3;pos;pos-=pos & -pos)
	    ans+=sm[pos];
	return ans;
    }
};Fenwick data1,data2;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=2;i<Max;i++){
	if(nxt[i]==0){
	    for(int j=i;j<Max;j+=i)
		nxt[j]=i;
	}
    }
    int n;cin>>n;
    for(int i=1;i<n;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
	cin>>a[i];
	int x=a[i];
	while(x>1){
	    int p=nxt[x],c=0;
	    while(x%p==0) x/=p,c++;
	    mp[p].F.PB({c,i});
	}
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
	cin>>A[i]>>B[i]>>ans[i];
	int x=ans[i];
	while(x>1){
	    int p=nxt[x],c=0;
	    while(x%p==0) x/=p,c++;
	    mp[p].S.PB({c,i});
	}
    }
    for(int i=1;i<=q;i++){
	ans[i]=__gcd(ans[i],a[Lca(A[i],B[i])]);
    }
    for(auto &IT:mp){
	int prim=IT.F;
	vector<pii>&vert=IT.S.F,&qur=IT.S.S;
	sort(vert.begin(),vert.end());
	sort(qur.begin(),qur.end());
	data1.Restart(),data2.Restart();
	for(pii p:vert){
	    data2.Add(seg[p.S].F,seg[p.S].S,1);
	}
	int pt=0;
	for(pii p:qur){
	    while(pt<sz(vert) && vert[pt].F<=p.F){
		pii pp=vert[pt];
		data2.Add(seg[pp.S].F,seg[pp.S].S,-1);
		data1.Add(seg[pp.S].F,seg[pp.S].S,pp.F);
		pt++;
	    }
	    int av=A[p.S],bv=B[p.S],lcv=Lca(av,bv),a=seg[av].F,b=seg[bv].F,lc=seg[lcv].F;
	    int num=data1.Ask(a)+data1.Ask(b)-2*data1.Ask(lc) + p.F*(data2.Ask(a)+data2.Ask(b)-2*data2.Ask(lc));
	    ans[p.S]=1ll*ans[p.S]*Pow(prim,num) %mod;
	}
    }
    for(int i=1;i<=q;i++){
	cout<<ans[i]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.