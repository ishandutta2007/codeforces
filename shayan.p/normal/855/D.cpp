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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<pii> v[maxn];
vector<int>RT;
int sp[20][maxn],spw[20][maxn],h[maxn],ROOT[maxn];

void dfs(int u,int RRT,int par=0,int t=0,int H=1){
    ROOT[u]=RRT;
    h[u]=H;
    sp[0][u]=par;spw[0][u]=t;
    for(int i=1;i<20;i++){
	sp[i][u]=sp[i-1][sp[i-1][u]];
	spw[i][u]=spw[i-1][u]==-1 || spw[i-1][sp[i-1][u]]==-1 || spw[i-1][u]!=spw[i-1][sp[i-1][u]] ? -1 : t ;
    }
    for(pii p:v[u]){
	if(p.F!=par)
	    dfs(p.F,RRT,u,p.S,H+1);
    }
}

int lca(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    for(int i=19;i>=0;i--){
	if(h[sp[i][a]]>=h[b])
	    a=sp[i][a];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--){
	if(sp[i][a]!=sp[i][b])
	    a=sp[i][a],b=sp[i][b];
    }
    return sp[0][a];
}

int type(int a,int b){
    if(a==b) return 0;
    int t=spw[0][a];
    for(int i=19;i>=0;i--){
	if(h[sp[i][a]]>=h[b]){
	    if(t!=spw[i][a]) return -1;
	    a=sp[i][a];
	}
    }
    return t;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	int a,b;cin>>a>>b;
	if(a==-1){
	    RT.PB(i);
	}
	else{
	    v[a].PB({i,b});
	}
    }
    for(int rt:RT)
	dfs(rt,rt);
    int q;cin>>q;
    for(int i=1;i<=q;i++){
	int t,a,b;cin>>t>>a>>b;
        if(ROOT[a]!=ROOT[b])
            cout<<"NO\n";
	else if(t==1){
	    int lc=lca(a,b);
	    if(a!=b && lc==a && type(b,lc)==0)
		cout<<"YES\n";
	    else
		cout<<"NO\n";
	}
	else{
	    int lc=lca(a,b);
	    if(lc!=b && type(a,lc)==0 && type(b,lc)==1)
		cout<<"YES\n";
	    else
		cout<<"NO\n";
	}
    }
    return 0;
}