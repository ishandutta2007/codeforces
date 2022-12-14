//In the name of the truth
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

#define Mp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define Pb push_back
#define Err(x) cerr << #x << " = " << (x) << endl;
#define Get(a) scanf("%d",&a)
#define Put(a) printf("%d\n",a);
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int Maxn = 1e6 + 1e3;
int par[Maxn];
int rank[Maxn];
int ans[Maxn];
vector<int> al[Maxn];
bool got[Maxn];
int in,Max;
void dfs(int v,int p,int dep){
	For(i,0,al[v].size()){
		int u = al[v][i];
		if(u - p)
			dfs(u,v,dep+1);
	}
	if(Max <= dep)
		Max = dep,in = v;
	return;
}
int find(int v){
	if(par[v] != v)
		return find(par[v]);
	return v;
}
bool unite(int u,int v){
	u = find(u),v = find(v);
	if(u == v)
		return 0;
	if(rank[u] < rank[v])
		swap(u,v);
	rank[u] = max(rank[u],rank[v]+1);
	par[v] = u;
	return 1;
}
int get_diam(int v){
	v = find(v);
	if(got[v])
		return ans[v];
	got[v] = 1;
	dfs(v,-1,0);
	Max = 0;
	dfs(in,-1,0);
	ans[v] = Max;
	in = 0,Max = 0;
	return ans[v];
}
void update(int u,int v){
	u = find(u),v = find(v);
	if(!unite(u,v))
		return;
	int tmp = ans[u];
	ans[u] = max(ans[u],ans[u]/2 + ans[u] % 2 + ans[v]/2 + ans[v] % 2 + 1);
	ans[v] = max(ans[v],tmp/2 + tmp % 2 + ans[v]/2 + ans[v] % 2 + 1);
	ans[u] = max(ans[u],ans[v]);
	ans[v] = ans[u];
	return;
}
int query(int v){
	v = find(v);
	return ans[v];
}
int main(){
	int n,m,q;
	Get(n),Get(m),Get(q);
	For(i,0,n)
		par[i] = i;
	For(i,0,m){
		int u,v;
		Get(u),Get(v);
		al[--u].push_back(--v);
		al[v].push_back(u);
		unite(u,v);
	}
	For(i,0,n){
		get_diam(i);
	}
	For(i,0,q){
		int t;
		Get(t);
		if(--t){
			int u,v;
			Get(u),Get(v);
			update(--u,--v);
		}else{
			int v;
			Get(v);
			Put(query(--v));
		}
	}
	return 0;
}