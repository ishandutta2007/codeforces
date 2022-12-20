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
typedef pair<ll,int> pli;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int C=maxn;
bool mark[9*maxn];
ll dis[9*maxn];
vector<pii> v[9*maxn];

inline void add_edge(int a,int b,int w,bool bl){
    if(bl) v[a].PB({b,w});
    else v[b].PB({a,w});
}

struct Segment{
    int wh[4*maxn];
    bool normal;
    Segment(bool b){
	normal=b;
	build();
    }
    void build(int l=0,int r=maxn,int id=1){
	if(r-l==1) { wh[id]=l;  return;}
	int mid=(l+r)>>1;
	build(l,mid,2*id);
	build(mid,r,2*id+1);
	wh[id]=C++;
	add_edge(wh[id],wh[2*id],0,normal);
	add_edge(wh[id],wh[2*id+1],0,normal);
    }
    void add(int f,int s,int u,int w,int l=0,int r=maxn,int id=1){
	if(f>=s || l>=r || s<=l || r<=f) return;
	if(f<=l && r<=s) { add_edge(u,wh[id],w,normal); return; }
	int mid=(l+r)>>1;
	add(f,s,u,w,l,mid,2*id);
	add(f,s,u,w,mid,r,2*id+1);
    }
};Segment seg0(0),seg1(1);

void dij(int s){
    priority_queue<pli,vector<pli>,greater<pli> >pq;
    fill(dis,dis+9*maxn,inf);
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
	int u=pq.top().S;
	pq.pop();
	if(mark[u]) continue;
	mark[u]=1;
	for(pii p:v[u]){
	    if(dis[p.F]>dis[u]+p.S){
		dis[p.F]=dis[u]+p.S;
		pq.push({dis[p.F],p.F});
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,s;cin>>n>>q>>s;
    while(q--){
	int task;cin>>task;
	if(task==1){
	    int a,b,w;cin>>a>>b>>w;
	    add_edge(--a,--b,w,1);
	}
	if(task==2){
	    int a,l,r,w;cin>>a>>l>>r>>w;
	    seg1.add(--l,r,--a,w);
	}
	if(task==3){
	    int a,l,r,w;cin>>a>>l>>r>>w;
	    seg0.add(--l,r,--a,w);
	}
    }
    dij(--s);
    for(int i=0;i<n;i++){
	cout<<(dis[i]==inf?-1:dis[i])<<" ";
    }
    return cout<<endl,0;
}