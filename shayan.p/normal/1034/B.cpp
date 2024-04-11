// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e3+10,mod=1e9+7;
const ll inf=1e18;

vector<pll>v[maxn];
bool vis[maxn];
ll par[maxn],mn[maxn];

void dfs(ll u){
    vis[u]=1;
    for(pll p:v[u]){
	if(!vis[p.F] && p.S){
	    par[p.F]=u;
	    mn[p.F]=min(mn[u],p.S);
	    dfs(p.F);
	}
    }
}

ll max_flow(ll s,ll t){
    ll ans=0;
    while(true){
	memset(vis,0,sizeof vis);
	memset(par,0,sizeof par);
	memset(mn,0,sizeof mn);
	mn[s]=inf;
	dfs(s);
	if(mn[t]==0)
	    break;
	ll tmp=t,x=mn[t];
	ans+=x;
	while(tmp!=s){
	    FOR(i,0,sz(v[tmp])-1){
		if(v[tmp][i].F==par[tmp])
		    v[tmp][i].S+=x;
	    }
	    FOR(i,0,sz(v[par[tmp]])-1){
		if(v[par[tmp]][i].F==tmp)
		    v[par[tmp]][i].S-=x;
	    }
	    tmp=par[tmp];
	}
    }
    return ans;
}

int dx[4]={1,1,-1,-1};
int dy[4]={-1,1,-1,1};
int Dx[4]={1,0,-1,0};
int Dy[4]={0,1,0,-1};
ll n,m;

inline ll Code(ll x,ll y){
    return m*(x-1)+y;
}

int main(){
    cin>>n>>m;
    if(n==1 || m==1){
	if(m==1)
	    swap(n,m);
	ll ans=m;
	if(m%6==1)
	    ans-=1;
	if(m%6==2)
	    ans-=2;
	if(m%6==3)
	    ans-=3;
	if(m%6==4)
	    ans-=2;
	if(m%6==5)
	    ans-=1;
	cout<<ans<<endl;
	return 0;
    }
    if((n*m)<=150){
	FOR(x,1,n){
	    FOR(y,1,m){
		int C=1-((x+y)&1);
		FOR(k,0,3){
		    int x1=x+2*dx[k],x2=x+dx[k];
		    int y1=y+dy[k],y2=y+2*dy[k];
		    if(x1>0 && x1<=n && y1>0 && y1<=m){
			v[Code(x,y)].PB({Code(x1,y1),C});
		    }
		    if(x2>0 && x2<=n && y2>0 && y2<=m){
			v[Code(x,y)].PB({Code(x2,y2),C});
		    }
		}
		FOR(k,0,3){
		    int x1=x+3*Dx[k],y1=y+3*Dy[k];
		    if(x1>0 && x1<=n && y1>0 && y1<=m){
			v[Code(x,y)].PB({Code(x1,y1),C});
		    }
		}
	    }
	}
	FOR(x,1,n){
	    FOR(y,1,m){
		if((x+y)&1){
		    v[Code(x,y)].PB({n*m+1,1});
		    v[n*m+1].PB({Code(x,y),0});
		}
		else{
		    v[Code(x,y)].PB({0,0});
		    v[0].PB({Code(x,y),1});
		}
	    }
	}
	cout<<2*max_flow(0,n*m+1)<<endl;
    }
    else if(n&1 && m&1){
	cout<<(n*m-1)<<endl;
    }
    else{
	cout<<(n*m)<<endl;
    }
}