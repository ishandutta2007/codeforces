//#include "roads.h"
#include<bits/stdc++.h>
using namespace std;
#define int long long
#include <vector>
#define MN 250005
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
vector<pii >e[MN];
int f[MN][2],n,k,fa[MN],fw[MN];
multiset<int>A[MN],B[MN],val[MN];
int suma[MN];
const int inf=1e18;
#define itset multiset<int>::iterator
void dfs(int x){
	f[x][0]=f[x][1]=0;
	while(A[x].size()&&B[x].size()&&(*A[x].begin())<(*B[x].rbegin())){
		int a=*A[x].begin(),b=*B[x].rbegin();
		A[x].erase(A[x].find(a));
		A[x].insert(b);
		B[x].erase(B[x].find(b));
		B[x].insert(a);
		suma[x]+=b;
		suma[x]-=a;
	}
	val[x].clear();
	int ans=suma[x];
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i].x,w=e[x][i].y;	
		if(e[v].size()<=k)break;
		if(fa[x]==v)continue;
		dfs(v);
		ans+=f[v][0];
		val[x].insert(f[v][1]-f[v][0]+w);	
	}
	f[x][0]=ans;
	if(k)f[x][1]=ans;
	assert(k-1>=A[x].size());
	int N=k-1-A[x].size();
	for(int i=1;i<=N;++i){
		if(!val[x].size()||(B[x].size()&&(*val[x].rbegin())<(*B[x].rbegin()))){
			int v=*B[x].rbegin();
			assert(v>=0);
			A[x].insert(v);
			B[x].erase(--B[x].end());
			suma[x]+=v;
			ans+=v;
		}				
		else{
			if((*val[x].rbegin())>0)
			ans+=*val[x].rbegin();
			val[x].erase(--val[x].end());
		}
	}
	while(val[x].size()&&A[x].size()&&(*A[x].begin())<(*val[x].rbegin())){
		int v=*A[x].begin();
		suma[x]-=v;
		A[x].erase(A[x].begin());
		B[x].insert(v);
		ans-=v;
		ans+=(*val[x].rbegin());
		val[x].erase(--val[x].end());
	}
	f[x][0]=f[x][1]=ans;
	if(B[x].size()||val[x].size()){	
		if(!val[x].size()||(B[x].size()&&(*val[x].rbegin())<(*B[x].rbegin()))){
			int v=*B[x].rbegin();
			if(v>0)
				ans+=v;
		}				
		else{
			if((*val[x].rbegin())>0)
				ans+=*val[x].rbegin();
			val[x].erase(--val[x].end());
		}
		f[x][0]=ans;
	}
	assert(f[x][0]>=f[x][1]);
//	f[x][0]=max(f[x][0],f[x][1]);
}
void DFS(int x){
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i].x,w=e[x][i].y;
		if(fa[x]==v)continue;
		fa[v]=x;DFS(v);fw[v]=w;
	}
}
vector<int>upd[MN],fin[MN];
int dep[MN];
bool cmp(int a,int b){return dep[a]>dep[b];}
bool vis[MN];
bool CMP(pii a,pii b){return e[a.x].size()>e[b.x].size();}
std::vector<long long> minimum_closure_costs(signed N, std::vector<signed> U,
		std::vector<signed> V,
		std::vector<signed> W) {
	n=N;
	int sum=0;
	for(int i=0;i<N-1;++i){
		U[i]++;V[i]++;
		sum+=W[i];
		e[U[i]].pb(mp(V[i],W[i]));
		e[V[i]].pb(mp(U[i],W[i]));
	}
	int mx=0;
	e[1].pb(mp(0,0));
	DFS(1);
	for(int i=1;i<=n;++i){
		sort(e[i].begin(),e[i].end(),CMP);
		mx=max(mx,(int)e[i].size());
		for(int j=1;j<e[i].size();++j)upd[j].pb(i);
		fin[e[i].size()].pb(i);
	}
	vector<int>ans(0);
	int tot=0;
	ans.pb(sum);
	for(int i=1;i<N;++i){
		k=i;
		for(auto j:fin[i]){
			vis[j]=1;
			for(int k=0;k<e[j].size();++k){
				int v=e[j][k].x,w=e[j][k].y;
				if(vis[v])tot+=w;
				else
					B[v].insert(w);
			}
		}
		int res=tot;
		for(auto j:upd[i]){
			if(e[fa[j]].size()<=i){
				dfs(j);
				res+=f[j][0];
			}
		}
		ans.pb(sum-res);
	}
	return ans;
}
vector<signed>u,v,w;
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
signed main(){
	n=read();
	for(int i=1;i<n;++i){
		u.pb(read()-1);
		v.pb(read()-1);
		w.pb(read());
	}
	vector<int>ans=minimum_closure_costs(n,u,v,w);
	for(auto i:ans)printf("%lld ",i);
	return 0;
}