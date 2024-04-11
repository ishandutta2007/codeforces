#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99;

int n,m,ans,w[N];
pair<int,int> par[N];
pair<int,pair<int,int> > edge[N];

int Get_par(int u){
	if(par[u].F<0) return u;
	return (par[u].F=Get_par(par[u].F));
}
void dsu(int u,int v){
	if(par[u].F>par[v].F)
		swap(u,v);
	par[u].F+=par[v].F;
	par[u].S+=par[v].S+1;
	par[v].F=u;
}

int main(){
	cin>>n>>m;
	f(i,0,m)
		cin>>edge[i].S.F>>edge[i].S.S>>edge[i].F;
		
	sort(edge,edge+m);
	reverse(edge,edge+m);
	f(i,0,n+2) par[i].F=par[i].S=-1;
	
	f(i,0,m){
		int u=Get_par(edge[i].S.F),v=Get_par(edge[i].S.S);
		if(u!=v){
			if(par[u].S<0 || par[v].S<0)
				dsu(u,v),ans+=edge[i].F;
		}
		else if(par[u].S==-1)
			ans+=edge[i].F,par[u].S=0;
	}
	cout<<ans;
}