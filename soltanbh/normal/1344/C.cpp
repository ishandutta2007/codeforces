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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+9;

int n,m,t,x,y,ans,c=1,mark[N],deg[N],dp[N],dp1[N];
vector<int> g[N],g1[N];
string s;

void check(){
	queue<int> q;
	f(i,1,n+1){
		deg[i]=g[i].size();
		if(g[i].size()==0)
			q.push(i);
	}
	int t=0;
	while(q.size()){
		t++;
		int u=q.front();
		q.pop();
		f(i,0,g1[u].size()){
			deg[g1[u][i]]--;
			if(deg[g1[u][i]]==0)
				q.push(g1[u][i]);
		}	
	}
	if(t<n){
		cout<<-1;
		exit(0);
	}
}
void solve(int x){
	if(dp[x]!=0) return ;
	dp[x]=x;
	f(i,0,g[x].size()){
		solve(g[x][i]);
		minm(dp[x],dp[g[x][i]]);
	}
}
void solve1(int x){
	if(dp1[x]!=0) return ;
	dp1[x]=x;
	f(i,0,g1[x].size()){
		solve1(g1[x][i]);
		minm(dp1[x],dp1[g1[x][i]]);
	}
}

int main(){
	cin>>n>>m;
	f(i,0,m){
		cin>>x>>y;
		g1[y].pb(x);
		g[x].pb(y);
	}
	check();
	f(i,1,n+1){
		solve(i);
		solve1(i);
		if(dp[i]==i && dp1[i]==i){ ans++;s+='A';}
		else s+='E';
	}
	cout<<ans<<endl<<s;
}