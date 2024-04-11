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
const int N=1e5+9,k=17;
int n,x,y,p,e,m,c[N],mx[N],a[N],ans[N];
vector<int> g[N];
vector<pair<int,int> > query[N];
map<int,int> mark[N],t[N];
void add_t(int x,int y){
	p=0;
	f_(i,k-1,0){
		if(y>=(1<<i)){
			y-=(1<<i);
			p+=(1<<i);
			t[x][p]++;
		}
	}
}
void del_t(int x,int y){
	p=0;
	f_(i,k-1,0){
		if(y>=(1<<i)){
			y-=(1<<i);
			p+=(1<<i);
			t[x][p]--;
		}
	}
}
void add(int an,int y){
	for(auto it:mark[y]){
		e=mark[an][it.F];
		del_t(an,e);
		add_t(an,e+it.S);
		mark[an][it.F]+=it.S;
	}
}
int Get_t(int x,int y){
	int sum=0;
	x=(1<<k)-x,p=(1<<k);
	f_(i,k-1,0){
		if(x>=(1<<i)){
			x-=(1<<i);
			p-=(1<<i);
			sum+=t[y][p];
		}
	}
	return sum;
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
	if(x!=1 && g[x].size()==1) a[x]=x;
	e=mark[a[x]][c[x]]++;
	del_t(a[x],e);
	add_t(a[x],e+1);
	f(i,0,g[x].size()){
		if(g[x][i]!=par && g[x][i]!=an){
			add(a[an],a[g[x][i]]);
			mark[a[g[x][i]]].clear();
		}
	}
//	cout<<x<<" :: "<<endl;
//	for(auto it:mark[a[x]])
//	    cout<<it.F<<" "<<it.S<<endl;
//	cout<<endl;
	f(i,0,query[x].size())
		ans[query[x][i].S]=Get_t(query[x][i].F,a[x]);
}
int main(){
	Gett(n,m);
	f(i,1,n+1) gett(c[i]);
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,0,m){
		Gett(x,y);
		query[x].pb(mp(y,i));
	}
	dfs(1,0);
	f(i,0,m) cout<<ans[i]<<endl;
}