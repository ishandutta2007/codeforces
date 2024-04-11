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

const int N=2e5+9;

int n,m,k,x,ans,mx=1,par[N],szk[N];
pair<int,pair<int,int> > edge[N];

int Get_par(int x){
	if(par[x]<=0) return x;
	return (par[x]=Get_par(par[x])); 
}
void dsu(int u,int v){
	if((u=Get_par(u)) == (v=Get_par(v))) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	szk[u]+=szk[v];
	maxm(mx,szk[u]);
}

int main(){
	cin>>n>>m>>k;
	f(i,0,k){
		gett(x);
		szk[x]=1;
	}	
	f(i,0,m){
		par[i+1]=par[i+2]=-1;
		Gett(edge[i].S.F,edge[i].S.S);
		gett(edge[i].F);
	}
	sort(edge,edge+m);
	for(;ans<m && mx<k;ans++)
		dsu(edge[ans].S.F,edge[ans].S.S);
	f(i,0,k)
		cout<<edge[ans-1].F<<" ";
}