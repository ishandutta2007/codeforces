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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+9;
int n,t,k,x,y,a[N],sub[N];
ll ans;
vector<int> g[N];
void dfs(int x,int par,int dist){
	sub[x]=1;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs(g[x][i],x,dist+1);
			sub[x]+=sub[g[x][i]];
		}
	a[x-1]=dist-sub[x]+1;
//	cout<<x<<" : "<<a[x-1]<<endl;
}
int main(){
	cin>>n>>k;
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0,0);
	sort(a,a+n);
	f_(i,n-1,n-k) ans+=1ll*a[i];
	cout<<ans;
}