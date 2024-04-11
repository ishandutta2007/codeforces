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

const int maxn=1e5+10,inf=15e8;

int A[maxn],B[maxn],C[maxn],ANSA,ANSB,n,l,r;
vector<int>ed;
vector<pii> v[maxn];

int SZ[maxn],MX;
bool mark[maxn];

pii val[2*maxn];

void dfsS(int u,int par=-1){
    SZ[u]=1;
    for(pii p:v[u]){
	if(p.F!=par && !mark[p.F])
	    dfsS(p.F,u),SZ[u]+=SZ[p.F];
    }
}

int dfsC(int u,int ss,int par=-1){
    for(pii p:v[u]){
	if(p.F!=par && !mark[p.F] && SZ[p.F]>=ss)
	    return dfsC(p.F,ss,u);
    }
    return u;
}

void prep(){
    for(int i=0;i<2*MX;i++){
	val[i]={-inf,-inf};
    }
}
pii ask(int f,int s){
    s=min(s,MX-1);
    f+=MX;s+=MX;
    pii ans={-inf,-inf};
    while(f<s){
	if(f&1) ans=max(ans,val[f++]);
	if(s&1) ans=max(ans,val[--s]);
	f>>=1;s>>=1;
    }
    return ans;
}
void add(int pos,pii p){
    pos+=MX;
    while(pos>0){
	val[pos]=max(val[pos],p);
	pos>>=1;
    }
}

void dfsadd(int u,int ln,int sm,int par){
    add(ln,{sm,u});
    for(pii p:v[u]){
	if(p.F!=par && !mark[p.F])
	    dfsadd(p.F,ln+1,sm+p.S,u);
    }
}

void dfsask(int u,int ln,int sm,int par){
    pii X=ask(max(0,l-ln),max(0,r-ln+1));
    if(X.F+sm>=0) ANSA=X.S,ANSB=u;
    for(pii p:v[u]){
	if(p.F!=par && !mark[p.F])
	    dfsask(p.F,ln+1,sm+p.S,u);
    }
}

void solve(int u){
    dfsS(u);
    MX=SZ[u]+5;
    prep();
    u=dfsC(u,SZ[u]/2);
    add(0,{0,u});
    mark[u]=1;
    for(pii p:v[u]){
	if(!mark[p.F])
	    dfsask(p.F,1,p.S,u),dfsadd(p.F,1,p.S,u);
    }
    for(pii p:v[u]){
	if(!mark[p.F])
	    solve(p.F);
    }
}

bool okay(int num){
    memset(mark,0,sizeof mark);
    for(int i=1;i<=n;i++){
	v[i].clear();
    }
    for(int i=0;i<n-1;i++){
	v[A[i]].PB({B[i],C[i]>=ed[num]?1:-1});
	v[B[i]].PB({A[i],C[i]>=ed[num]?1:-1});
    }
    ANSA=ANSB=-1;
    solve(1);
    return ANSA!=-1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>l>>r;
    for(int i=0;i<n-1;i++){
	cin>>A[i]>>B[i]>>C[i];
	ed.PB(C[i]);
    }
    sort(ed.begin(),ed.end());
    int l=0,r=n-2,ansa=-1,ansb=-1;
    while(l<=r){
	int mid=(l+r)/2;
	if(okay(mid))
	    ansa=ANSA,ansb=ANSB,l=mid+1;
	else
	    r=mid-1;
    }
    cout<<ansa<<" "<<ansb<<endl;
    return 0;
}