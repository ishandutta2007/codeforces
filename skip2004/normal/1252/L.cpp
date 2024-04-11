#include<bits/stdc++.h>
using namespace std;
#define read(x)  scanf("%d",&(x))
int n,m;
int a[23333],b[23333],c[23333],l[23333],r[23333],s[23333],H[23333];
const int inf = 2147483647;
inline int f(int i,int x){return x*a[i]*x+b[i]*x+c[i];}
inline int get(int i,int j){return s[i]+j-l[i];}
struct T{
	int from,to,nxt,v;
}way[1<<21];
int h[23333],num=1;
int dis[23333];
inline void adde(int a,int b,int f){
	way[++num]=(T){a,b,h[a],f},h[a]=num;
	way[++num]=(T){b,a,h[b],0},h[b]=num;
}
queue<int> q;
int T;
inline int bfs(int s,int t){
	for(int i=0;i<=T;++i)dis[i]=inf,H[i]=h[i];dis[s]=0;q.push(s);
	while(!q.empty()){
		int t=q.front();q.pop();
		for(int i=h[t];i;i=way[i].nxt)
			if(dis[way[i].to]==inf && way[i].v)
				dis[way[i].to]=dis[t]+1,q.push(way[i].to);
	}
	return dis[t]!=inf;
}
inline int dfs(int s,int to,int f){
	if(s==to || f == 0)return f;
	int ans=0,m;
	for(int&i=H[s];i;i=way[i].nxt)
		if(dis[way[i].to]>dis[s] && (m=dfs(way[i].to,to,min(f,way[i].v)))){
			ans+=m;way[i^1].v+=m;
			way[i].v-=m;f-=m;
			if(f==0)break;
		}
	return ans;
}
inline int dinic(int s,int t){
	int ans=0;
	while(bfs(s,t))ans+=dfs(s,t,inf);
	return ans;
}
int main() {
	read(n),read(m);
	for(int i=1;i<=n;++i)
		read(a[i]),read(b[i]),read(c[i]);
	int t=1,MAXN=0;
	for(int i=1;i<=n;++i){
		read(l[i]),read(r[i]),s[i]=t,t+=r[i]-l[i]+2;
		for(int j=l[i];j<=r[i];++j)
			MAXN=max(MAXN,f(i,j));
	}
	for(int i=1;i<=n;++i){
		adde(0,s[i],inf);
		for(int j=l[i];j<=r[i];++j)
			adde(get(i,j),get(i,j)+1,MAXN-f(i,j));
		adde(get(i,r[i])+1,t,inf);
	}
	for(int i=1,x,y,z;i<=m;++i){
		read(x),read(y),read(z);
		for(int j=l[x];j<=r[x];++j)
			if(j-z >= l[y] && j-z <= r[y]+1)
				adde(get(x,j),get(y,j-z),inf);
	}
	cout << n * MAXN-dinic(0,T=t);
}