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

const int maxn=1010,Source=0,Sink=2*maxn-1;
const ll inf=1e17;

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
};Flow<ll,2*maxn> flw;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
	int x;cin>>x;
	flw.add_edge(Source,i,x);
    }
    ll ans=0;
    for(int i=n+1;i<=n+m;i++){
	int a,b,c;cin>>a>>b>>c;
	ans+=c;
	flw.add_edge(i,Sink,c);
	flw.add_edge(a,i,inf);
	flw.add_edge(b,i,inf);
    }
    ans-=flw.flow(Source,Sink,30);
    cout<<ans<<endl;
    return 0;
}