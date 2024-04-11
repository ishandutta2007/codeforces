// Mikaeel_noob_e_sag_e

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

const int maxn=610,inf=1e9,src=maxn-2,snk=maxn-1;

int pt[maxn],h[maxn],arr[maxn],f[maxn];
vector<int> vid[maxn];
vector<pii> v[maxn],ed;

void add_edge(int a,int b,int c){
    vid[a].PB(sz(v[b]));
    vid[b].PB(sz(v[a]));
    v[a].PB({b,c});
    v[b].PB({a,0});
}

bool bfs(){
    memset(h,0,sizeof h);
    int L=0,R=0;
    arr[R++]=src;
    h[src]=1;
    while(L<R){
	int u=arr[L++];
	if(u==snk) return 1;
	for(pii p:v[u]){
	    if(h[p.F]==0 && p.S>0)
		h[p.F]=h[u]+1,arr[R++]=p.F;
	}
    }
    return 0;
}

int dfs(int u,int f){
    if(u==snk) return f;
    int ans=0;
    while(pt[u]<sz(v[u])){
	int y=v[u][pt[u]].F,&w=v[u][pt[u]].S,&w2=v[y][vid[u][pt[u]]].S;
	if(h[u]+1==h[y]){
	    int num=dfs(y,min(f-ans,w));
	    ans+=num;w-=num;w2+=num;
	}
	if(ans==f) break;
	pt[u]++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	int m;cin>>m;
	while(m--){
	    int x;cin>>x;
	    add_edge(i,n+(--x),1);
	    ed.PB({i,x});
	}
    }
    for(int i=0;i<n;i++){
	add_edge(src,i,1);
	add_edge(i+n,snk,1);
    }
    int NUM=0;
    while(bfs()){
	memset(pt,0,sizeof pt);
	NUM+=dfs(src,inf);
    }
    for(int i=0;i<n;i++){
	for(pii p:v[i]){
	    if(n<=p.F && p.F<2*n && p.S==0)
		f[p.F-n]=i;
	}
    }
    for(int i=0;i<maxn;i++){
	v[i].clear();
	vid[i].clear();
    }
    for(pii p:ed){
	add_edge(p.F,f[p.S],inf);
    }
    int ans=0;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	if(x<0){
	    ans-=x;
	    add_edge(src,i,-x);
	}
	else{
	    add_edge(i,snk,x);
	}
    }
    while(bfs()){
	memset(pt,0,sizeof pt);
	ans-=dfs(src,inf);
    }
    return cout<<-ans<<endl,0;
}