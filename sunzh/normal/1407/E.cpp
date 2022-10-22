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
int n,m;
int head[500010],nxt[500010],to[500010],col[500010];
int cov[500010];
int d[500010];
void bfs(int s){
	queue<int>q;
	q.push(s);
	memset(cov,-1,sizeof(cov));
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
//		printf("u:%d\n",u);
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
//			printf("v:%d,col:%d,cov:%d",v,col[i],cov[v]);
			if(cov[v]==-1||cov[v]==col[i]){
				cov[v]=col[i];
			}
			else if(d[v]>d[u]+1){
				d[v]=d[u]+1;
				cov[v]=col[i]+2;
				q.push(v);
			}
		}
	}
	if(d[1]>=0x3f3f3f3f){
		printf("-1\n");
		for(int i=1;i<=n;++i){
			if(cov[i]!=-1) printf("%d",cov[i]>=2?cov[i]-2:(cov[i]^1));
			else printf("1");
		}
	}
	else{
		printf("%d\n",d[1]);
		for(int i=1;i<=n;++i){
			if(cov[i]!=-1) printf("%d",cov[i]>=2?cov[i]-2:(cov[i]^1));
			else printf("1");
		}
	}
}
int tot;
void add(int x,int y,int z){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,col[tot]=z;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),c=read();
		add(v,u,c);
	}
	bfs(n); 
}