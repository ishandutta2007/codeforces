#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=3e5+9;
int n,m,q,mx,u,v,x,y,p,mark[N],par[N],ans[N];
vector<int> g[N];
void dfs(int x,int rt,int dist,int source){
	if(x!=rt) par[x]=rt;
	par[rt]--,mark[x]=source;
	f(i,0,g[x].size())
		if(mark[g[x][i]]!=source)
			dfs(g[x][i],rt,dist+1,source);
	if(dist>mx)
		mx=dist,u=x;
}
int Get_par(int x){
	if(par[x]<0) return x;
	par[x]=Get_par(par[x]);
	return par[x];
}
void merge(int x,int y){
	if((x=Get_par(x))==(y=Get_par(y))) return ;
	if(par[x]<par[y]) swap(x,y);
	par[y]+=par[x],par[x]=y;
	if(ans[x]%2==ans[y]%2){
		if(ans[x]%2)
			p=(1+(ans[x]==ans[y]))*(abs(ans[x]-ans[y])<=2);
		else
			p=(ans[x]==ans[y]);
	}	
	else
		p=(abs(ans[x]-ans[y])<=1);
	ans[y]=max(ans[x],ans[y])+p;
}
int main(){
	cin>>n>>m>>q;
	f(i,0,m){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,1,n+1){
		if(mark[i]==0){
			mx=-1;
			dfs(i,i,0,1);
			dfs(u,i,0,2);
			ans[i]=mx;
			par[i]/=2;
		}
	}
	f(i,0,q){
		gett(x);
		if(x==1){
			gett(x);
			cout<<ans[Get_par(x)]<<endl;
		}
		else{
			Gett(x,y);
			merge(x,y);
		}
	}
}