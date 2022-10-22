#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
int tot=1;
int head[60],nxt[6010],to[6010],w[6010],c[6010];
void add(int u,int v,int f,int cs){
	nxt[++tot]=head[u],head[u]=tot,to[tot]=v,w[tot]=f,c[tot]=cs;
}
int dis[60];
int pre[60],edgenum[60];
bool inq[60];
bool spfa(int s,int t){
	memset(dis,0x3f,sizeof(dis));
	memset(pre,-1,sizeof(pre)); 
	dis[s]=0;inq[s]=1;queue<int>Q;Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(w[i]>0&&dis[v]>dis[u]+c[i]){
				dis[v]=dis[u]+c[i];
				pre[v]=u;edgenum[v]=i;
				if(!inq[v]){
					inq[v]=1;Q.push(v);
				}
			}
		}
	}
	return pre[t]!=-1;
}
int a[110];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),wg=read();
		add(u,v,1,wg);
		add(v,u,0,-wg);
	}
	int mincost,maxflow;
	mincost=maxflow=0;
	while(spfa(1,n)){
		mincost+=dis[n];maxflow++;
		int v=n;
		while(v!=1){
			w[edgenum[v]]--;
			++w[edgenum[v]^1];
			v=pre[v];
		}
		a[maxflow]=mincost;
	}
//	printf("%d\n",maxflow);
	int q=read();
	while(q--){
		int x=read();
		int l=1,r=maxflow;
		long double ans=1e12;
		while(r-l>=6){
			int mid1=(r-l+1)/3+l;
			int mid2=r-(r-l+1)/3;
			long double u1=(a[mid1]+x)*1.0L/mid1;
			long double u2=(a[mid2]+x)*1.0L/mid2;
			if(u1<u2) r=mid2-1;
			else l=mid1+1;
			ans=min(ans,min(u1,u2));
		}
		for(int i=l;i<=r;++i) ans=min(ans,(a[i]+x)*1.0L/i);
		printf("%.7Lf\n",ans);
	}
}