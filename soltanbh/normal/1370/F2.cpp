#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1005;

int n,t,l,r,u,v,h,c,f1,f2,mx,cent,ans,mid,rt_par,sub[N];
vector<int> ver,g[N];
pair<int,int> a[N];
string s;

int ask(int x){
	cout<<"? "<<x<<" ";
	f(i,1,x+1)
		cout<<a[i].S<<" ";
	cout<<endl;
	cin>>u>>v;
	return v;
}
void dfs(int x,int dist,int par){
	sub[x]=1;
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],dist+1,x),sub[x]+=sub[g[x][i]];
	if(sub[x]>=n/2 && dist>h) h=dist,cent=x;
}
void dfs1(int x,int dist,int par,int goal){
	if(dist==goal) ver.pb(x);
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs1(g[x][i],dist+1,x,goal);
}
void dfs2(int x,int par,int dist){
	a[++c]=mp(dist,x);
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs2(g[x][i],x,dist+1);
}
void remove_centroid(){
	h=-1,mx=0,c=0;
	dfs(1,0,0);
	cout<<"? "<<n-1;
	f(i,1,n+1) if(i!=cent) cout<<" "<<i; cout<<endl;
	cin>>u>>ans;
	f(i,0,g[u].size()){
		if(sub[g[u][i]]>sub[u]) sub[g[u][i]]=n-sub[u];
		if(sub[g[u][i]]>mx) mx=sub[g[u][i]],rt_par=g[u][i];
	}
	dfs2(u,rt_par,0);
}
void find_f1_f2(){
	sort(a+1,a+1+c);
	reverse(a+1,a+1+c);
	l=0,r=c;
	while(l+1<r){
		mid=(l+r)/2;
		if(ask(mid)>ans) l=mid;
		else r=mid;
	}
	f1=a[r].S;
	dfs1(f1,0,0,ans);
	cout<<"? "<<ver.size()<<" ";
	print(ver,ver.size());
	cin>>f2>>u;
	cout<<"! "<<f1<<" "<<f2<<endl;
	cin>>s;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		f(i,1,n+1) g[i].clear(); ver.clear();
		f(i,1,n){
			Gett(u,v);
			g[u].pb(v);
			g[v].pb(u);
		}
		remove_centroid();
		find_f1_f2();
	}
}