#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
int a[1010];
int head[1010],nxt[1000010],to[1000010],w[1000010],tot=1,tmp[1010];
int idx[1010][1010];
void add(int x,int y,int z){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
	nxt[++tot]=head[y],head[y]=tot,to[tot]=x,w[tot]=0;
}
int s,t;
int cnt;
int depth[1010];
bool bfs(){
	memset(depth,0,sizeof(depth));
	queue<int>Q;Q.push(s);depth[s]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(w[i]&&!depth[v]){
				depth[v]=depth[u]+1;Q.push(v);
			}
		}
	}
	return depth[t];
}
int dfs(int x,int f){
	if(x==t) return f;
	int sum=0;
	for(int &i=tmp[x];i;i=nxt[i]){
		int v=to[i];
		if(w[i]&&depth[v]==depth[x]+1){
			int d=dfs(v,min(w[i],f));
			f-=d;
			sum+=d;w[i]-=d;w[i^1]+=d;
			if(!f) break ;
		}
	}
	return sum;
}
int dinic(){
	int fl=0,x=0;
	while(bfs()){
		memcpy(tmp,head,sizeof(tmp));
		while(x=dfs(s,0x3f3f3f3f)) fl+=x;
	}
	return fl;
}
bool used[1010];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();s=n+1,t=n+2;
	for(int i=1;i<=n;++i) if(a[i]>(m/3)){
		for(int j=1;j<=n;++j) if(a[i]%a[j]==0&&a[j]<=(m/3)&&1ll*a[i]+a[i]+a[j]<=m){
			idx[i][j]=tot+1;add(i,j,1);
		}
		add(s,i,1);++cnt;
	}else add(i,t,1);
	int flow=dinic();
	if(flow!=cnt){
		printf("-1\n");return 0;
	}
	vector<PII>ans;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) if(idx[i][j]&&!w[idx[i][j]]){
			ans.pb(mp(a[i]+a[j]+a[i],a[i]+a[j]));
			used[i]=used[j]=1;
			break ;
		}
	}
	for(int i=1;i<=n;++i) if(!used[i]) ans.pb(mp(a[i]+a[i]+a[i],a[i]+a[i]));
	printf("%d\n",ans.size());
	for(PII i:ans) printf("%d %d\n",i.fi,i.se);
}