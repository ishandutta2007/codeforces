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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<pll>v[maxn];
int h[maxn];
int wh[maxn][21];
ll sp[maxn][21];
ll ds[50][maxn];
bool mark[maxn];

vector<ll>verts;

priority_queue<pll,vector<pll>,greater<pll> >pq;

void dfs(int u,int par=0){
    mark[u]=1;
    for(pll p:v[u]){
	if(p.F==par){
	    wh[u][0]=p.F;
	    sp[u][0]=p.S;
	}
	else if(mark[p.F] && h[p.F]<h[u]){
	    verts.PB(p.F);
	    verts.PB(u);
	}
	else if(!mark[p.F]){
	    h[p.F]=h[u]+1;
	    dfs(p.F,u);
	}
    }
}

ll DIS(int a,int b){
    if(h[a]<h[b])swap(a,b);
    ll ans=0;
    for(int i=20;i>=0;i--){
	if(h[wh[a][i]]>=h[b]){
	    ans+=sp[a][i];
	    a=wh[a][i];
	}
    }
    for(int i=20;i>=0;i--){
	if(wh[a][i]!=wh[b][i]){
	    ans+=sp[a][i]+sp[b][i];
	    a=wh[a][i];
	    b=wh[b][i];
	}
    }
    if(a!=b)
	ans+=sp[a][0]+sp[b][0];
    return ans;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    FOR(i,1,m){
	int a,b;
	ll c;
	scanf("%d%d%lld",&a,&b,&c);
	v[a].PB({b,c});
	v[b].PB({a,c});
    }
    
    h[1]=1;
    dfs(1);

    FOR(j,1,20){
	FOR(i,1,n){
	    wh[i][j]=wh[wh[i][j-1]][j-1];
	    sp[i][j]=sp[i][j-1]+sp[wh[i][j-1]][j-1];
	}
    }

    FOR(i,0,sz(verts)-1){
	FOR(j,1,n){
	    ds[i][j]=inf;
	}
	memset(mark,0,sizeof mark);
	pq.push({0,verts[i]});
	ds[i][verts[i]]=0;
	while(sz(pq)){
	    int u=pq.top().S;
	    pq.pop();
	    if(mark[u])continue;
	    mark[u]=1;
	    for(pll p:v[u]){
		if((ds[i][u]+p.S)<ds[i][p.F]){
		    ds[i][p.F]=ds[i][u]+p.S;
		    pq.push({ds[i][p.F],p.F});
		}
	    }
	}
    }

    int q;scanf("%d",&q);
    while(q--){
	int a,b;scanf("%d%d",&a,&b);
	ll ans=DIS(a,b);
	FOR(i,0,sz(verts)-1){
	    ans=min(ans,DIS(a,verts[i])+ds[i][b]);
	    //	    cout<<DIS(a,verts[i])<<" "<<a<<" "<<verts[i]<<endl;
	}
	cout<<ans<<endl;
    } 
}