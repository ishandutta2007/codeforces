// Jump, and you will find out how to unfold your wings as you fall.

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
typedef long double ld;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int mark[maxn],ans[maxn],par[maxn];
vector<int>v[maxn],vec,vecc[3];
ll Sum=0;

void Fill(int u,int cl){
    mark[u]=cl,ans[u]=0;
    for(int y:v[u])
	if(mark[y]!=cl)
	    Fill(y,cl);
}

bool cycle(int u,int pr=-1){
    mark[u]=1; par[u]=pr;
    for(int y:v[u]){
	if(mark[y]==1 && y!=pr){
	    int tmp=u;
	    while(tmp!=y){
		ans[tmp]=1;
		tmp=par[tmp];
	    }
	    ans[y]=1;
	    return 1;
	}
	else if(mark[y]!=1){
	    if(cycle(y,u))
		return 1;
	}
    }
    return 0;
}

void dfs(int u,bool Do,int pr=-1){
    par[u]=pr;
    if(Do && sz(v[u])>2)
	vec.PB(u);
    for(int y:v[u]){
	if(y!=pr)
	    dfs(y,Do,u);
    }
}

void dfs2(int u,int pr,vector<int>&vec){
    if(sz(vec)<11) vec.PB(u);///
    for(int y:v[u]){
	if(y!=pr)
	    dfs2(y,u,vec);
    }
}

void check(int u,int pr=-1){
    Sum-=1ll*ans[u]*ans[u];
    for(int y:v[u]){
	if(y!=pr)
	    Sum+=1ll*ans[u]*ans[y],check(y,u);
    }
}

bool solve(int u){
    Fill(u,2);
    if(cycle(u)) return 1;
    vec.clear(); dfs(u,1);
    if(sz(vec)==0){
	return 0;
    }
    if(sz(vec)>1){
	int A=vec[0],B=vec[1];
	for(int y:v[A])
	    ans[y]=1;
	for(int y:v[B])
	    ans[y]=1;
	dfs(A,0);
	int tmp=B;
	while(tmp!=A){
	    ans[tmp]=2;
	    tmp=par[tmp];
	}
	ans[A]=2;
	return 1;
    }
    u=vec[0];
    if(sz(v[u])>3){
	ans[u]=2;
	for(int y:v[u])
	    ans[y]=1;
	return 1;
    }
    int Num=1;
    for(int i=0;i<3;i++){
	vecc[i].clear();
	dfs2(v[u][i],u,vecc[i]);
	Num*=sz(vecc[i])+1;
    }
    for(int i=0;i<3;i++){
	reverse(vecc[i].begin(),vecc[i].end());
	for(int j=0;j<sz(vecc[i]);j++){
	    ans[vecc[i][j]]=(Num/(sz(vecc[i])+1))*(j+1);
	}
    }
    ans[u]=Num;
    Sum=0,check(u);
    if(Sum>=0) return 1;
    Fill(u,3);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
	    mark[i]=ans[i]=par[i]=0;
	    v[i].clear();
	}
	while(m--){
	    int a,b;cin>>a>>b;
	    v[--a].PB(--b);
	    v[b].PB(a);
	}
	for(int i=0;i<n;i++){
	    if(mark[i]==0 && solve(i)){
		cout<<"YES\n";
		for(int j=0;j<n;j++)
		    cout<<ans[j]<<" ";
		cout<<"\n";
		goto End;
	    }
	}
	cout<<"NO\n";
    End:;
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.