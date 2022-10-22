#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
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

const int N=5e5+99;

int n,t,u,v,m,pr,deg[N],par[N],mark[N],masir[N];
vector<int> leaf,g[N];

void clear(){
	fill(deg,deg+n+2,0);leaf.clear();
	fill(mark,mark+n+2,0);
	f(i,1,n+1) g[i].clear(); pr=0;
}
void dfs(int x,int dist){
	masir[dist]=x;
	mark[x]=1;
	if(dist==(n-1)/2 && !pr){
		pr=1;
		cout<<"PATH\n";
		cout<<(n+1)/2<<'\n';
		f(i,0,dist+1)
			cout<<masir[i]<<" "; cout<<'\n';
	}
	f(i,0,g[x].size())
		if(!mark[g[x][i]]){
			deg[x]++;
			par[g[x][i]]=x;
			dfs(g[x][i],dist+1);
		}
	if(deg[x]==0) leaf.pb(x);
}
void solve(){
	f(j,0,sz(leaf)){
		if(j==sz(leaf)-1) return ;
		u=leaf[j];
		deg[par[u]]--;
		if(!deg[par[u]]) leaf.pb(par[u]); 
	}
}

int main(){
	cin>>t;
	while(t--){
		clear();
		Gett(n,m);
		f(i,0,m){
			Gett(u,v);
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(1,0);
		if(!pr){
			solve();
			cout<<"PAIRING"<<'\n';
			cout<<sz(leaf)/2<<'\n';
			for(int i=1;i<leaf.size();i+=2)
				cout<<leaf[i-1]<<" "<<leaf[i]<<'\n';
		}
	}
}