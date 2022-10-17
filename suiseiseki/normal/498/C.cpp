#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn=100000*8+10,maxl=70000+111,inf=0x3f3f3f3f;
struct edge {
	int v,next;
	int w;
} e[maxn];
int head[maxl],cnt=0,dep[maxl],n,m,ans=0,s,t,a[maxl];
inline void add(int u,int v,int w) {
	e[cnt]=(edge) {
		v,head[u],w
	};
	head[u]=cnt++;
	e[cnt]=(edge) {
		u,head[v],0
	};
	head[v]=cnt++;
}
bool bfs() {
	memset(dep,-1,sizeof(dep));
	dep[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=head[u]; ~i; i=e[i].next) {
			int v=e[i].v;
			if(dep[v]==-1&&e[i].w>0) {
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[t]>-1;
}
int dfs(int u,int cap) {

	if(u==t)return cap;
	int flow=0;
	for(int i=head[u]; ~i; i=e[i].next) {
		int v=e[i].v;
		if(dep[v]==dep[u]+1&&e[i].w) {
			int temp=dfs(v,min(e[i].w,cap-flow));
			flow+=temp;
			e[i].w-=temp;
			e[i^1].w+=temp;
			if(flow==cap)return flow;
		}
	}
	if(!flow)dep[u]=-2;
	return flow;
}
int dinic() {
	int solve=0,f;
	while(bfs()) {
		while(f=dfs(s,inf))solve+=f;
	}
	return solve;
}
vector<int>yue[maxl],num[maxl];
void make(int k) {
	int lim=sqrt(a[k]+0.5),temp=a[k];
	for(int i=2; i<=lim; i++)
		if(temp%i==0) {
			int cn=0;
			while(temp%i==0)cn++,temp/=i;
			yue[k].push_back(i),num[k].push_back(cn);
		}
	if(temp>1)yue[k].push_back(temp),num[k].push_back(1);
}
void update(int x,int y) {
	int N=yue[x].size(),M=yue[y].size();
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(yue[x][i]==yue[y][j])add((x-1)*n+i+1,(y-1)*n+j+1,min(num[x][i],num[y][j]));
}
int u,v;
int main() {
	cnt=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	s=0,t=n*50+10;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(!(i&1)) {
			make(i);
			for(int j=0; j<yue[i].size(); j++)
				add(s,(i-1)*n+j+1,num[i][j]);
		} else {
			make(i);
			for(int j=0; j<yue[i].size(); j++)
				add((i-1)*n+j+1,t,num[i][j]);
		}
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		if(u&1)swap(u,v);
		update(u,v);
	}
	printf("%d\n",dinic());
	return 0;
}