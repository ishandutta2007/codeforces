#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
const int N=1e6+9;
int n,x,y,p,e,m,c[N],mx[N],a[N],ans[N],mn[N];
vector<int> g[N];
map<int,int> mark[N];
set<ll> s[N];
ll k=1e7;
void add(int an,int y,int x){
	for(auto it:mark[y]){
		e=mark[an][it.F+x];
		s[an].erase(e*k-(it.F+x));
		s[an].insert(k*(e+it.S)-(it.F+x));
		mark[an][it.F+x]+=it.S;
	}
}
void dfs(int x,int par){
	int m=0,an=0;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			if(mark[a[g[x][i]]].size()>m){
		    	m=mark[a[g[x][i]]].size();
		    	an=g[x][i];
			}
		}
	}
	a[x]=a[an];
	mn[x]=mn[an]+1;
	if(x!=1 && g[x].size()==1) a[x]=x,mn[x]=0;
	mark[a[x]][-mn[x]]=1;
	s[a[x]].insert(k+mn[x]);
	f(i,0,g[x].size()){
		if(g[x][i]!=an && g[x][i]!=par)
			add(a[x],a[g[x][i]],mn[g[x][i]]-mn[x]+1);	
	}
//	cout<<x<<" :: "<<endl;
//	for(auto it:mark[a[x]])
//	    cout<<it.F<<" "<<it.S<<endl;
//	cout<<endl;
	ans[x]=(-(*s[a[x]].rbegin()%k))+mn[x];
}
int main(){
	gett(n);
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	f(i,1,n+1) cout<<ans[i]<<" ";
}