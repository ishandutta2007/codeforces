#include <bits/stdc++.h>

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
#define ALL(x) x.begin(),x.end()

using namespace std;

using pi=pair<int,int>;
using vi=vector<int>;

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

void print(int x,int z){
	printf("%lld",x);
	if(z==1)printf("\n");
	if(z==2)printf(" ");
}

const int Nmax=100010;
vi tr[Nmax];
int md[Nmax],mi[Nmax];
void dfs(int v,int p){
	md[v]=0,mi[v]=v;
	for(auto to:tr[v])if(to!=p){
		dfs(to,v);
		if(md[to]+1>md[v]){
			md[v]=md[to]+1;
			mi[v]=mi[to];
		}
	}
}
int par[Nmax];
void dfs2(int v,int p){
	par[v]=p;
	for(auto to:tr[v])if(to!=p)
		dfs2(to,v);
}

int ans;
bool used[Nmax];
priority_queue<pi> pq;
void Mark(int v){
	if(v==-1)return;
	if(used[v])return;
	used[v]=1;
	ans++;
	Mark(par[v]);
	for(auto to:tr[v])if(!used[to])
		pq.push(pi(md[to],to));
}

signed main(){
	int n=read();
	if(n==1){
		print(1,1);
		return 0;
	}
	
	REP(i,n-1){
		int a=read()-1,b=read()-1;
		tr[a].PB(b);
		tr[b].PB(a);
	}
	
	dfs(0,-1);
	int root=mi[0];
	dfs(root,-1);
	dfs2(root,-1);
	
	pq.push(pi(md[root],root));
	vi res{1};
	
	while(!pq.empty()){
		pi w=pq.top();pq.pop();
		int v=w.second;
		Mark(mi[v]);
		res.PB(ans);
	}
	assert(ans==n);
	
	while(int(res.size())<n)
		res.PB(n);
	
	REP(i,n)
		print(res[i],i==n-1?1:2);
}