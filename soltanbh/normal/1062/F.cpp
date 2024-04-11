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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+9;

int n,m,x,y,ans,ok[N],deg[N],dist[N],a[N][3],mark[N];
vector<int> top,g[N],gb[N];
pair<int,int> v[3];

void find_topo(){
	queue<int> q;
	f(i,1,n+1)
		if(deg[i]==0)
			q.push(i);
	int c=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		dist[u]=c++;
		top.pb(u);
		f(i,0,g[u].size())
			if(--deg[g[u][i]]==0)
				q.push(g[u][i]);
	}
}
void solve0(){
	f(i,1,n+1){
		int u=top[i];
		a[i][0]=a[i][1]=a[i][2]=n+1;
		f(j,0,g[u].size()){
			a[i][2]=dist[g[u][j]];
			sort(a[i],a[i]+3);
		}
	}
	f(i,1,n+1){
		if(v[2].F>i){
			if(v[1].F>i || mark[v[2].S]>i) ok[i]=2;
			else ok[i]=1;
		}
		maxm(mark[a[i][0]],a[i][1]);
		v[0]=mp(a[i][0],i);
		sort(v,v+3);
	}
}
void solve1(){
	fill(mark,mark+N,N);
	f_(i,n,1){
		int u=top[i];
		a[i][0]=a[i][1]=a[i][2]=0;
		f(j,0,gb[u].size()){
			a[i][0]=dist[gb[u][j]];
			sort(a[i],a[i]+3);
		}
	}
	v[0].F=v[1].F=N;
	f_(i,n,1){
		if(v[0].F<i){
			if(v[1].F<i || mark[v[0].S]<i) ok[i]+=2;
			else ok[i]+=1;
		}
		minm(mark[a[i][2]],a[i][1]);
		v[2]=mp(a[i][2],i);
		sort(v,v+3);
	}
}

int main(){
	top.pb(0);
	cin>>n>>m;
	f(i,0,m){
		cin>>x>>y;
		g[x].pb(y);
		gb[y].pb(x);
		deg[y]++;
	}
	find_topo();
	solve0();
	solve1();
	f(i,1,top.size())
		ans+=(ok[i]<2);
	cout<<ans;
}