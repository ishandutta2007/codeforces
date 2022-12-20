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

const int maxn=1e4+10,Source=0,Sink=2*maxn-1,inf=1e9;

vector<pii> g[maxn];
vector<int>vec;
int h[maxn];
pii par[maxn];
int Count;

template<typename T,int MAXN> struct Flow{
    vector< pair<int,T> >v[MAXN];
    vector<int>idv[MAXN];
    int h[MAXN],arr[MAXN],pt[MAXN];
    T lim;

    bool bfs(int Source,int Sink){
	memset(h,0,sizeof h);
	int L=0,R=0;
	arr[R++]=Source;
	h[Source]=1;
	while(L<R){
	    int u=arr[L++];
	    if(u==Sink) return 1;
	    for(pair<int,T> p:v[u]){
		if(p.S>=lim && h[p.F]==0)
		    h[p.F]=h[u]+1,arr[R++]=p.F;
	    }
	}
	return 0;
    }
    T dfs(int u,int Sink,T flow){// flow > 0
	if(u==Sink) return flow;
	T ans=0;
	while(pt[u]<sz(v[u])){
	    int &y=v[u][pt[u]].F;
	    T &w=v[u][pt[u]].S,&w2=v[y][idv[u][pt[u]]].S;
	    if(h[u]+1==h[y] && w>=lim){
		T num=dfs(y,Sink,min(flow-ans,w));
		ans+=num;w-=num;w2+=num;
	    }
	    if(flow==ans) break;
	    ++pt[u];
	}
	return ans;
    }
    void add_edge(int a,int b,T wa,T wb=0){
	idv[a].PB(sz(v[b]));
	idv[b].PB(sz(v[a]));
	v[a].PB({b,wa});
	v[b].PB({a,wb});
    }
    T flow(int Source,int Sink,int MXB=0){// MXB(is power of two) for scaling flow
	T ans=0;
	for(int i=MXB;i>=0;i--){
	    lim=(1ll<<i);
	    while(bfs(Source,Sink)){
		memset(pt,0,sizeof pt);
		ans+=dfs(Source,Sink,inf);
	    }
	}
	return ans;
    }
};Flow<int,2*maxn> flw;

int prep(int u,int H=1){
    h[u]=H;
    int up=H;
    for(pii p:g[u]){
	if(h[p.F] && h[p.F]<H && p.F!=par[u].F){
	    up=min(up,h[p.F]);
	    int tmp=u,cnt=1;
	    flw.add_edge(p.S,Count,1);
	    while(tmp!=p.F){
		flw.add_edge(par[tmp].S,Count,1);
		cnt++;
		tmp=par[tmp].F;
	    }
	    flw.add_edge(Count,Sink,cnt-1);
	    Count++;
	}
	else if(!h[p.F]){
	    par[p.F]={u,p.S};
	    up=min(up,prep(p.F,H+1));
	}
    }
    if(up==H && u!=1){
	flw.add_edge(Count,Sink,1);
	flw.add_edge(par[u].S,Count,2);
	Count++;
    }
    return up;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    Count=m+3;
    for(int i=1;i<=m;i++){
	flw.add_edge(Source,i,1);
    }
    for(int i=0;i<m;i++){
	int a,b,c;cin>>a>>b>>c;
	g[a].PB({b,c});
	g[b].PB({a,c});
    }
    prep(1);
    cout<<flw.flow(Source,Sink)<<endl;
    return 0;
}