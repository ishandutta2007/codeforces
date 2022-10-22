#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
struct node{
	int x1,y1,x2,y2;
}a[100];
int cnt1,cnt2;
int X[110],Y[110];
int head[210],nxt[40010],to[40010],w[40010];
int depth[210],gap[210];
map<PII,bool> ma; 
int s,t;
int tot=1;
void add(int u,int v,int val){
	nxt[++tot]=head[u],head[u]=tot,to[tot]=v,w[tot]=val;
}
bool bfs(int x,int y){
	queue<int>Q;
	Q.push(t);
	depth[t]=1;gap[1]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(!depth[v]){
				depth[v]=depth[u]+1;
				++gap[depth[v]];
				Q.push(v);
			}
		}
	}
	return depth[s]==0?0:1;
}
inline int dfs(int x,int maxf){
	if(x==t) return maxf;
	int sum=0;
	for(register int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(depth[v]+1==depth[x]){
			int d=dfs(v,min(maxf,w[i]));
			w[i]-=d,w[i^1]+=d;
			sum+=d;maxf-=d;if(maxf==0) return sum; 
		}
	}
	if(--gap[depth[x]]==0) depth[s]=t+1;
	++gap[++depth[x]];return sum;
}
int ISAP(int x,int y){
	if(bfs(x,y)==0) return 0;
	int maxflow=0;
	while(depth[s]<=t) maxflow+=dfs(s,0x3f3f3f3f);
	return maxflow;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		a[i].x1=read(),a[i].y1=read();
		a[i].x2=read(),a[i].y2=read();
		X[(i-1)<<1|1]=a[i].x1,X[i<<1]=a[i].x2+1;
		Y[(i-1)<<1|1]=a[i].y1,Y[i<<1]=a[i].y2+1;
	}
	sort(X+1,X+(m<<1|1));
	sort(Y+1,Y+(m<<1|1));
	cnt1=unique(X+1,X+(m<<1|1))-X-1;
	cnt2=unique(Y+1,Y+(m<<1|1))-Y-1;
	for(int i=1;i<=m;++i){
		int px1=lower_bound(X+1,X+cnt1+1,a[i].x1)-X;
		int px2=lower_bound(X+1,X+cnt1+1,a[i].x2+1)-X;
		int py1=lower_bound(Y+1,Y+cnt2+1,a[i].y1)-Y;
		int py2=lower_bound(Y+1,Y+cnt2+1,a[i].y2+1)-Y;
		for(int j=px1;j<px2;++j){
			for(int k=py1;k<py2;++k){
				if(ma.count(mp(j,k+cnt1))) continue ;
				ma[mp(j,k+cnt1)]=1;
				add(j,k+cnt1,0x3f3f3f3f),add(k+cnt1,j,0);
			}
		}
	}
	s=0,t=cnt1+cnt2+1;
	for(register int i=1;i<=cnt1;++i) add(s,i,(i==cnt1?n+1:X[i+1])-X[i]),add(i,s,0);
	for(register int i=1;i<=cnt2;++i) add(i+cnt1,t,(i==cnt2?n+1:Y[i+1])-Y[i]) ,add(t,i+cnt1,0);
	print(ISAP(s,t));
	return 0;
}