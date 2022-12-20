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

const int maxn=1e5+10;

vector<pii>v[maxn],fn[maxn],vec;
vector<int>tdo[maxn];
bool mark[maxn];
int MX,n,_L,_W,SZ[maxn];
ll ANS;

void add(int ln,int W){
    pii P={W,-1};
    ++ln;
    while(ln<MX){
	int ind=lower_bound(fn[ln].begin(),fn[ln].end(),P)-fn[ln].begin();
	while(ind<sz(fn[ln])){
	    fn[ln][ind].S++;
	    ind+=(ind & -ind);
	}
	ln+=(ln & -ln);
    }
}

int ask(int ln,int W){
    if(ln<0 || W<0) return 0;
    ++ln;
    int ans=0;
    pii P={W,2e9};
    ln=min(ln,MX-1);
    while(ln>0){
	int ind=upper_bound(fn[ln].begin(),fn[ln].end(),P)-fn[ln].begin()-1;
	while(ind>0){
	    ans+=fn[ln][ind].S;
	    ind-=(ind & -ind);
	}
	ln-=(ln  & -ln);
    }
    return ans;
}

void build(){
    for(int i=0;i<MX;i++)
	fn[i].clear(),fn[i].PB({-2,-2});
    for(pii p:vec){
	int ind=p.F+1;
	while(ind<MX){
	    fn[ind].PB({p.S,0});
	    ind+=(ind & -ind);
	}
    }
    for(int i=0;i<MX;i++){
	sort(fn[i].begin(),fn[i].end());
    }
}

void dfsS(int u,int par=-1){
    SZ[u]=1;
    for(pii p:v[u]){
	int y=p.F;
	if(!mark[y] && y!=par){
	    dfsS(y,u);
	    SZ[u]+=SZ[y];
	}
    }
}

int dfsC(int u,int ss,int par=-1){
    for(pii p:v[u]){
	int y=p.F;
	if(!mark[y] && y!=par && SZ[y]>=ss)
	    return dfsC(y,ss,u);
    }
    return u;
}

void dfsP(int u,int W=0,int ln=0,int par=-1){
    MX=max(MX,ln+5);
    vec.PB({ln,W});
    for(pii p:v[u]){
	int y=p.F;
	if(!mark[y] && y!=par)
	    dfsP(y,W+p.S,ln+1,u);
    }
}

void dfsadd(int u,int W,int ln,int par){
    add(ln,W);
    for(pii p:v[u]){
	int y=p.F;
	if(!mark[y] && y!=par)
	    dfsadd(y,W+p.S,ln+1,u);
    }
}

void dfsask(int u,int W,int ln,int par){
    ANS+=ask(_L-ln,_W-W);
    for(pii p:v[u]){
	int y=p.F;
	if(!mark[y] && y!=par)
	    dfsask(y,W+p.S,ln+1,u);
    }
}

void solve(int u){
    dfsS(u);
    u=dfsC(u,SZ[u]/2);
    vec.clear();MX=0;
    dfsP(u);
    build();
    add(0,0);
    mark[u]=1;
    for(pii p:v[u]){
	if(!mark[p.F]){
	    dfsask(p.F,p.S,1,u);
	    dfsadd(p.F,p.S,1,u);
	}
    }
    for(pii p:v[u]){
	if(!mark[p.F])
	    solve(p.F);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cin>>n>>_L>>_W;
    for(int i=2;i<=n;i++){
	int p,w;cin>>p>>w;
	v[p].PB({i,w});
	v[i].PB({p,w});
    }
    solve(1);
    cout<<ANS<<endl;
    return 0;
}