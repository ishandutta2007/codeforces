#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[100010];
int maxn=0;
int cnt;
int ans=0x3f3f3f3f;
bool notprime[1000010];
int vis[100010];
int prime[1000010];
int head[100010],nxt[200010],to[200010];
int tot;
PII q[100010];
int dis[100010];
int pos[1000010];
inline void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
inline void bfs(int s){
	for(int i=0;i<=cnt;++i) dis[i]=0x3f3f3f3f,vis[i]=-1;
	vis[s]=s;dis[s]=0;
	int hd=1,tail=0;
	q[++tail]=mp(s,s);
	while(hd<=tail){
		PII t=q[hd];
		int u=t.fi;++hd;
		if(dis[u]>ans) break ;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(vis[v]!=s){
				vis[v]=s;
				dis[v]=dis[u]+1;q[++tail]=mp(v,u);
			}
			else if(v!=t.se){
				ans=min(ans,dis[v]+dis[u]+1);
			}
		}
	}
}
void getprime(){
	for(int i=2;i<=maxn;++i){
		if(!notprime[i]) prime[++cnt]=i,pos[i]=cnt;
		for(int j=1;j<=cnt&&prime[j]*i<=maxn;++j){
			notprime[prime[j]*i]=1;
			if(i%prime[j]==0) break ;
		}
	}
//	printf("%d\n",cnt);
} 
void check(int x){
	if(x==1){
		printf("1\n");exit(0);
	}
	int t=x;
	int p=-1,q=-1,l=-1;
	for(int i=1;i<=cnt;++i){
		if(prime[i]*prime[i]>t) break ;
		int c=0;
		while(t%prime[i]==0){
			++c;t/=prime[i];
		}
		if(c&1){
			if(p==-1) p=i;
			else q=i;
		}
		else if(c!=0) l=i;
	}
	if(t!=1){
		if(p==-1) p=pos[t];
		else q=pos[t];
	}
	if(q==-1){
		add(0,p),add(p,0);
	}
	else if(p==-1){
		printf("1\n");exit(0);
	}
	else add(p,q),add(q,p);
}
int main(){
//	freopen("tst.in","r",stdin);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),maxn=max(maxn,a[i]);
	getprime();
	for(int i=1;i<=n;++i) check(a[i]);
	for(int i=0;i<=cnt&&prime[i]*prime[i]<=maxn;++i) bfs(i);
	printf("%d\n",ans>=0x3f3f3f3f?-1:ans);
	return 0;
}