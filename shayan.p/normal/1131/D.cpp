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

const int maxn=2010,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn],rv[maxn],g[maxn];
vector<pii>ed;
int ans[maxn];

bool mark[maxn];
vector<int>vec;
int C,col[maxn];
int deg[maxn];

void Add(int a,int b){
    v[a].PB(b);
    rv[b].PB(a);
}
void dfs1(int u){
    mark[u]=1;
    for(int y:v[u])
	if(!mark[y])
	    dfs1(y);
    vec.PB(u);
}
void dfs2(int u){
    mark[u]=1;
    col[u]=C;
    for(int y:rv[u])
	if(!mark[y])
	    dfs2(y);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
	string s;cin>>s;
	for(int j=0;j<m;j++){
	    if(s[j]=='<') Add(i,n+j),ed.PB({i,n+j});
	    if(s[j]=='>') Add(n+j,i),ed.PB({n+j,i});
	    if(s[j]=='=') Add(i,n+j),Add(n+j,i);
	}
    }
    int N=n+m;
    for(int i=0;i<N;i++)
	if(!mark[i])
	    dfs1(i);
    memset(mark,0,sizeof mark);
    for(int i=N-1;i>=0;i--)
	if(!mark[vec[i]])
	    dfs2(vec[i]),C++;
    for(pii p:ed){
	if(col[p.F]==col[p.S]) return cout<<"No\n",0;
	g[col[p.F]].PB(col[p.S]);
	deg[col[p.S]]++;
    }
    vector<int>Q,Q2;
    int AC=0;
    for(int i=0;i<N;i++){
	if(deg[i]==0) Q.PB(i);
    }
    while(sz(Q)){
	AC++;
	Q2.clear();
	for(int u:Q){
	    for(int y:g[u])
		if(--deg[y]==0)
		    Q2.PB(y),ans[y]=AC;
	}
	Q=Q2;
    }
    cout<<"Yes\n";
    for(int i=0;i<n;i++)
	cout<<ans[col[i]]+1<<" ";
    cout<<endl;
    for(int i=0;i<m;i++)
	cout<<ans[col[n+i]]+1<<" ";
    return cout<<endl,0;
}