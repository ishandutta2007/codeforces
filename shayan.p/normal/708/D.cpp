// Wanna Hack? GL...

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

const int maxn=110,inf=1e9,Src=maxn-2,Snk=maxn-1;// kam nist?

vector<pair<int,pii> > v[maxn];
vector<int> vid[maxn];

void add_edge(int a,int b,int c,int d){
    //    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    vid[a].PB(sz(v[b]));
    vid[b].PB(sz(v[a]));
    v[a].PB({b,{c, d}});
    v[b].PB({a,{0,-d}});
}

int arr[maxn],ds[maxn],par[maxn];
bool inq[maxn];

int spfa(int src,int snk){
    int L=0,R=0;
    fill(ds,ds+maxn,inf);memset(par,-1,sizeof par);memset(inq,0,sizeof inq);
    arr[R++]=src; inq[src]=1; ds[src]=0;
    while(L!=R){
	int u=arr[L++]; if(L==maxn) L=0;
	inq[u]=0;
	for(int i=0;i<sz(v[u]);i++){
	    int y=v[u][i].F,w=v[u][i].S.F,c=v[u][i].S.S;
	    if(w>0 && ds[y]>ds[u]+c){
		ds[y]=ds[u]+c,par[y]=u;
		if(!inq[y]) inq[y]=1,arr[R++]=y;
		if(R==maxn) R=0;
	    }
	}
    }
    return ds[snk];
}

int pt[maxn];

int dfs(int u,int snk,int f){
    if(u==snk) return f;
    int ans=0;
    while(pt[u]<sz(v[u])){
	int y=v[u][pt[u]].F,&w=v[u][pt[u]].S.F,&w2=v[y][vid[u][pt[u]]].S.F,c=v[u][pt[u]].S.S;
	if(w>0 && par[y]==u && ds[u]+c==ds[y]){
	    int num=dfs(y,snk,min(w,f-ans));
	    w-=num;w2+=num;ans+=num;
	}
	if(ans==f) break;
	pt[u]++;
    }
    return ans;
}

pii Flow(int src,int snk){
    int num=0;
    pii ans={0,0};
    while((num=spfa(src,snk))!=inf){
	memset(pt,0,sizeof pt);
	int f=dfs(src,snk,inf);
	ans.F+=f;ans.S+=f*num;
    }
    return ans;
}

int sm[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    int ans=0;
    add_edge(n,1,inf,0);
    for(int i=0;i<m;i++){
	int a,b,c,d;cin>>a>>b>>c>>d;
	sm[a]-=d;
	sm[b]+=d;
	if(c<=d){
	    ans+=d-c;
	    add_edge(a,b,inf,2);
	    add_edge(b,a,d-c,0);
	    add_edge(b,a,c,1);
	}
	else{
	    add_edge(a,b,c-d,1);
	    add_edge(a,b,inf,2);
	    add_edge(b,a,d,1);
	}
    }
    for(int i=1;i<=n;i++){
	if(sm[i]<=0) add_edge(i,Snk,-sm[i],0);
	else         add_edge(Src,i, sm[i],0);
    }
    return cout<<ans+Flow(Src,Snk).S<<endl,0;
}