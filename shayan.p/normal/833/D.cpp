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

const int maxn=1e5+2,maxn2=4e5+10,mod=1e9+7;
const ll inf=1e18;

int x[maxn],c[maxn],SZ[maxn],ans=1;
bool mark[maxn];
vector<pii>v[maxn];

struct Fenwick{
    int zr[maxn2],cnt[maxn2],tot1,tot2;
    Fenwick(){
	fill(zr,zr+maxn2,1);
	memset(cnt,0,sizeof cnt);
	tot1=1;
	tot2=0;
    }
    vector<pair<int,pii> > vec;
    void add(int id,int x){
	tot1=1ll*tot1*x %mod;
	tot2++;
	while(id<maxn2){
	    vec.PB({id,{zr[id],cnt[id]}});
	    cnt[id]++;
	    zr[id]=1ll*zr[id]*x %mod;
	    id+=(id & -id);
	}
    }   
    pii ask(int id){
	int A=1,B=0;
	while(id>0){
	    B+=cnt[id];
	    A=1ll*A*zr[id] %mod;
	    id-=(id & -id);
	}
	return {A,B};
    }
    inline void Restart(){
	for(int i=sz(vec)-1;i>=0;i--){
	    auto it=vec[i];
	    zr[it.F]=it.S.F;
	    cnt[it.F]=it.S.S;
	}
	vec.clear();
	tot1=1;
	tot2=0;
    }
};Fenwick fn1,fn2;

int Pow(int a,int b){
    b=b%(mod-1);
    if(b<0) b+=mod-1;
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

void dfsz(int u,int par=-1){
    SZ[u]=1;
    for(pii p:v[u]){
	if(p.F!=par && !mark[p.F])
	    dfsz(p.F,u),SZ[u]+=SZ[p.F];
    }
}

int dfsc(int u,int N,int par=-1){
    for(pii p:v[u]){
	if(p.F!=par && !mark[p.F] && SZ[p.F]>N)
	    return dfsc(p.F,N,u);
    }
    return u;
}

inline void Add(int X,int C1,int C2){
    fn1.add(C2-2*C1+maxn+maxn,X);
    fn2.add(C1-2*C2+maxn+maxn,X);
}

inline void Get(int X,int C1,int C2){
    pii p1=fn1.ask(2*C1-C2+maxn+maxn),p2=fn2.ask(2*C2-C1+maxn+maxn);
    p2.F=1ll*fn2.tot1*Pow(p2.F,mod-2) %mod;
    p2.S=fn2.tot2-p2.S;
    ans=1ll*ans*p1.F %mod *Pow(p2.F,mod-2) %mod * Pow(X,p1.S-p2.S) %mod;
}

void dfssl(int u,int X,int C1,int C2,int par){
    Get(X,C1,C2);
    if(2*C1>=C2 && 2*C2>=C1) ans=1ll*ans*X %mod;
    for(pii p:v[u]){
	if(p.F!=par && !mark[p.F]){
	    dfssl(p.F,1ll*X*x[p.S]%mod,C1+(c[p.S]==0),C2+(c[p.S]==1),u);
	}
    }
}

void dfsad(int u,int X,int C1,int C2,int par){
    Add(X,C1,C2);
    for(pii p:v[u]){
	if(p.F!=par && !mark[p.F])
	    dfsad(p.F,1ll*X*x[p.S]%mod,C1+(c[p.S]==0),C2+(c[p.S]==1),u);
    }
}

void solve(int u){
    dfsz(u);
    u=dfsc(u,SZ[u]/2);
    mark[u]=1;
    for(pii p:v[u]){
	if(!mark[p.F]){
	    dfssl(p.F,x[p.S],c[p.S]==0,c[p.S]==1,u);
	    dfsad(p.F,x[p.S],c[p.S]==0,c[p.S]==1,u);
	}
    }
    fn1.Restart();
    fn2.Restart();
    for(pii p:v[u]){
	if(!mark[p.F])
	    solve(p.F);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b>>x[i]>>c[i];
	v[a].PB({b,i});
	v[b].PB({a,i});
    }
    solve(1);
    cout<<ans<<endl;
    return 0;
}