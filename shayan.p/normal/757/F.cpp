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

const int maxn=3e5+10,Lg=20;
const ll inf=1e18;

priority_queue<pll,vector<pll>,greater<pll> >pq;
vector<pii>g[maxn];
vector<int>v[maxn],rv[maxn],vv[maxn],tpl;
bool mark[maxn];
int h[maxn],sp[Lg][maxn];
ll dis[maxn];

void topol(int u){
    mark[u]=1;
    for(int y:v[u])
	if(!mark[y])
	    topol(y);
    tpl.PB(u);
}
int LCA(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    for(int i=Lg-1;i>=0;i--){
	if(h[b]<=h[sp[i][a]])
	    a=sp[i][a];
    }
    if(a==b) return a;
    for(int i=Lg-1;i>=0;i--){
	if(sp[i][a]!=sp[i][b])
	    a=sp[i][a],b=sp[i][b];
    }
    return sp[0][a];
}
int dfs(int u){
    int num=1;
    for(int y:vv[u])
	num+=dfs(y);
    return num;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,s;cin>>n>>m>>s;
    for(int i=0;i<m;i++){
	int a,b,c;cin>>a>>b>>c;
	g[a].PB({b,c});
	g[b].PB({a,c});
    }
    fill(dis,dis+maxn,inf);
    pq.push({0,s});
    dis[s]=0;
    while(sz(pq)){
	int u=pq.top().S;
	pq.pop();
	if(mark[u]) continue;
	mark[u]=1;
	for(pii p:g[u]){
	    if(dis[u]+p.S<dis[p.F])
		dis[p.F]=dis[u]+p.S,pq.push({dis[p.F],p.F});
	}
    }
    for(int i=1;i<=n;i++){
	for(pii p:g[i]){
	    if(dis[i]+p.S==dis[p.F])
		v[i].PB(p.F),rv[p.F].PB(i);
	}
    }
    memset(mark,0,sizeof mark);
    topol(s);
    reverse(tpl.begin(),tpl.end());
    h[s]=1;
    for(int i=1;i<sz(tpl);i++){
	int u=tpl[i],ans=-1;
	for(int y:rv[u]){
	    if(ans==-1) ans=y;
	    else ans=LCA(ans,y);
	}
	sp[0][u]=ans;
	h[u]=h[ans]+1;
	vv[ans].PB(u);
	for(int j=1;j<Lg;j++)
	    sp[j][u]=sp[j-1][sp[j-1][u]];
    }
    int ans=0;
    for(int u:vv[s]){
	ans=max(ans,dfs(u));
    }
    return cout<<ans<<endl,0;
}