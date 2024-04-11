#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
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
#define int ll
const int maxn=2e6+9;
const ll e=1e16;
 
int n,m,q,k,x,y,v,l,r,mn[maxn],mx[maxn];
ll ST[maxn],Add[maxn],ans[maxn];
vector<pair<int,int> > g[maxn];
vector<pair<int,pair<int,int> > > queri[maxn];

void Update(int k, int L, int R, int i, int j, ll v)
{
    if (L > j || R < i) return;
    if (i <= L && R <= j)
    {
        ST[k] += v;
        Add[k] += v;
        return;
    }
 
    Add[k << 1] += Add[k];
    Add[(k << 1) + 1] += Add[k];
    ST[k << 1] += Add[k];
    ST[(k << 1) + 1] += Add[k];
    Add[k] = 0;
 
    int mid = (L + R) >> 1;
    Update(k << 1, L, mid, i, j, v);
    Update((k << 1) + 1, mid + 1, R, i, j, v);
 
    ST[k] = max(ST[k << 1], ST[(k << 1) + 1]);
}
 
ll Get(ll k, int L, int R, int i, int j)
{
    if (L > j || R < i) return -1000000000;
    if (i <= L && R <= j) return ST[k];
 
    Add[k << 1] += Add[k];
    Add[(k << 1) + 1] += Add[k];
    ST[k << 1] += Add[k];
    ST[(k << 1) + 1] += Add[k];
    Add[k] = 0;
 
    ll mid = (L + R) >> 1;
    return max(Get(k << 1, L, mid, i, j), Get((k << 1) + 1, mid + 1, R, i, j));
}
void read_input(){
	Gett(n,q);
	f(i,1,n){
		Gett(x,y);
		g[x].pb(mp(i+1,y));
	}
	f(i,0,q){
		gett(v);Gett(l,r);
		queri[v].pb(mp(i,mp(l,r)));
	}
}
void dfs1(int x,ll dist){
	mn[x]=maxn;
	if(!g[x].size()){
		mn[x]=mx[x]=x;
		Update(1,1,n,x,x,e-dist);
	}
	f(i,0,g[x].size()){
		dfs1(g[x][i].F,dist+g[x][i].S);
		maxm(mx[x],mx[g[x][i].F]);
		minm(mn[x],mn[g[x][i].F]);
	}
}
void dfs(int x){
	f(i,0,queri[x].size())
		ans[queri[x][i].F]=e-Get(1,1,n,queri[x][i].S.F,queri[x][i].S.S);
	f(i,0,g[x].size()){
		Update(1,1,n,1,n,-1ll*g[x][i].S);
		Update(1,1,n,mn[g[x][i].F],mx[g[x][i].F],2ll*g[x][i].S);
		dfs(g[x][i].F);
		Update(1,1,n,1,n,g[x][i].S);
		Update(1,1,n,mn[g[x][i].F],mx[g[x][i].F],-2ll*g[x][i].S);
	}
}
main(){
	read_input();
	dfs1(1,0);
	dfs(1);
	print(ans,q);
}