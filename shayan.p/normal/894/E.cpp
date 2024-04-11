// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e6+10;
const ll four=3e4+20;

vector<int>v[maxn],g[maxn];
bool mark[maxn];
stack<int>pro;
int t;
int scc[maxn];
int n,m;
vector<pair<int,ll> >s[maxn];
stack<pair<pair<int,int>,int> >edge;
ll score[maxn];
ll dp[maxn];

void dfs1(int u){
	mark[u]=1;
	REP(i,sz(v[u])){
		if(!mark[v[u][i]]){
			dfs1(v[u][i]);
		}
	}
	pro.push(u);
}
void dfs2(int u){
	mark[u]=1;
	scc[u]=t;
	REP(i,sz(g[u])){
		if(!mark[g[u][i]])
			dfs2(g[u][i]);
	}
}
void SCC(){
	REP(i,n)
		if(!mark[i])
			dfs1(i);
	memset(mark,0,sizeof mark);
	while(sz(pro)){
		int tp=pro.top();
		pro.pop();
		if(!mark[tp]){
			dfs2(tp);
			t++;
		}
	}
}

ll calc_edge(ll num){
	ll l=0,r=four,res;
	while(l<=r){
		ll mid=(l+r)/2;
		ll sum=(mid*(mid+1))/2;
		if(num<sum){
			r=mid-1;
		}
		else{
			res=mid;
			l=mid+1;
		}
	}
	ll kam=(((res*(res+1)*((2*res)+1))/6)+((res*(res+1))/2))/2;
	return (((res+1)*num)-kam);
}

void super_node(){
	map<int,int>mp[t+10];
	
	while(sz(edge)){
		pair<pair<int,int>,int>tp;
		tp=edge.top();
		edge.pop();
		
		int sc1=scc[tp.F.F],sc2=scc[tp.F.S];
		ll w=tp.S;
		if(sc1==sc2)
			score[sc1]+=calc_edge(w);
		else
			mp[sc1][sc2]=max(mp[sc1][sc2],int(w));
	}
	REP(i,t){
		for(map<int,int>::iterator it=mp[i].begin();it!=mp[i].end();it++){
			s[i].PB(*it);
		}
	}
}

ll dfs_calc(int u){
	mark[u]=1;
	REP(i,sz(s[u])){
		if(!mark[s[u][i].F])
			dfs_calc(s[u][i].F);
		dp[u]=max(dp[u],dp[s[u][i].F]+s[u][i].S);
	}
	dp[u]+=score[u];
}

int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		ll a,b,w;scanf("%d%d%d",&a,&b,&w);
		a--;b--;
		v[a].PB(b);
		g[b].PB(a);
		edge.push(MP(MP(a,b),w));
	}
	int start;cin>>start;
	start--;
	SCC();
	super_node();
	memset(mark,0,sizeof mark);
	dfs_calc(scc[start]);
	cout<<dp[scc[start]];
}