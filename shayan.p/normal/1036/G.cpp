// Can U hack it?

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

const int maxn=1e6+10,mod=1e9+7,MM=44;
const ll inf=1e18;

vector<int>v[maxn],in,out;
int indg[maxn],outdg[maxn],mark[maxn];
int per[MM],vec[MM],C;
bool vis[MM],adj[MM][MM];

void dfs(int u,int col){
    mark[u]=col;
    for(int y:v[u]){
	if(mark[y]!=col)
	    dfs(y,col);
    }
}

void dfsc1(int u){
    vis[u]=1;
    for(int i=0;i<sz(in)+sz(out);i++)
	if(!vis[i] && adj[u][i])
	    dfsc1(i);
    vec[C++]=u;
}

void dfsc2(int u){
    vis[u]=1;
    for(int i=0;i<sz(in)+sz(out);i++)
	if(!vis[i] && adj[i][u])
	    dfsc2(i);
}

bool ok(){
    memset(vis,0,sizeof vis);
    C=0;
    for(int i=0;i<sz(in)+sz(out);i++)
	if(!vis[i])
	    dfsc1(i);
    memset(vis,0,sizeof vis);
    dfsc2(vec[C-1]);
    for(int i=C-1;i>=0;i--)
	if(!vis[vec[i]])
	    return 0;
    return 1;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
	int a,b;scanf("%d%d",&a,&b);
	v[--a].PB(--b);
	indg[b]++;
	outdg[a]++;
    }
    for(int i=0;i<n;i++){
	if(indg[i]==0 && outdg[i]==0){
	    if(n==1)
		printf("YES\n");
	    else
		printf("NO\n");
	    return 0;
	}
	if(indg[i]==0)
	    out.PB(i);
	if(outdg[i]==0)
	    in.PB(i);
    }
    for(int i=0;i<sz(out);i++){
	dfs(out[i],i+1);
	for(int j=0;j<sz(out);j++)
	    if(mark[out[j]]==i+1)
		adj[i][j]=1;
	for(int j=0;j<sz(in);j++)
	    if(mark[in[j]]==i+1)
		adj[i][sz(out)+j]=1;
    }
    for(int i=0;i<MM;i++)
	per[i]=i;
    for(int Q=0;Q<500000;Q++){
	random_shuffle(per,per+sz(in));
	for(int i=0;i<sz(out);i++)
	    adj[sz(out)+per[i]][i]=1;
	if(!ok()){
	    printf("NO\n");
	    return 0;
	}
	for(int i=0;i<sz(out);i++)
	    adj[sz(out)+per[i]][i]=0;
    }
    printf("YES\n");
}