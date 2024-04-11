#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,ans,a[N],e[N],par[N],deg[N];
vector<int> g[N];
set<pair<int,int> > s;

void dfs(int x){
	f(i,0,g[x].size())
		if(g[x][i]!=par[x]){
			deg[x]++;
			e[g[x][i]]=e[x]+1;
			par[g[x][i]]=x;
			dfs(g[x][i]);
		}
	if(x==1 || g[x].size()!=1)
		s.insert(mp(e[x],x));
}
void TT(){
	ans=1;
	s.clear();
	f(i,1,n+1) g[i].clear(),deg[i]=0;
	
	cin>>n;
	f(i,1,n){
		int u,v;
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	if(deg[1]==n-1){
		cout<<n-1<<'\n';
		return ;
	}
	dfs(1);
	while(s.size()){
		pair<int,int> u=*s.rbegin();
		s.erase(u);
		if(--deg[par[u.S]]==0 && par[u.S]!=1)
			s.erase(mp(e[par[u.S]],par[u.S]));
		ans+=max(0,deg[u.S]-1);
		//cout<<u.S<<" : "<<deg[u.S]<<endl;
	}
	cout<<ans<<'\n';
}

int main(){
	cin>>t;
	while(t--)
		TT();
}