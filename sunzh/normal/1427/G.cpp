#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,m;
int a[210][210];
struct node{
	int v,id;
	bool operator <(const node &x)const {
		return v<x.v;
	}
}v[810];
int head[40010],nxt[200010],to[200010],w[200010];
int tot=1;
void add(int x,int y){
	nxt[++tot]=head[x];head[x]=tot,to[tot]=y;
}
int getid(int x,int y){
	return (x-1)*n+y;
}
int flow;
int Si[40010],iT[40010];
bool vis[40010];
bool push(int x,int f){
	vis[x]=1;
	if(f==-1&&Si[x]) return 1;
	if(f==1&&iT[x]){
//		printf("atx:%d\n",x);
		return 1;
	}
//	printf("x:%d,f:%d\n",x,f);
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(f==-1&&w[i]!=-1) continue ;
		if(f==1&&w[i]==1) continue ;
		if(vis[v]) continue ;
//		printf("v:%d,w:%d,i:%d,\n",v,w[i],i);
		if(push(v,f)){
			w[i]++;
			w[i^1]--;
			return 1;
		}
	}
	return 0;
}
int main(){
//	freopen("matrix.in","r",stdin);
//	freopen("matrix.out","w",stdout);
	n=read(),m=n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) a[i][j]=read();
	}
	for(int i=1;i<=n;++i) v[i]={a[i][1],getid(i,1)},v[i+n]={a[i][m],getid(i,m)};
	for(int i=2;i<m;++i) v[i+n+n-1]={a[1][i],getid(1,i)},v[i+n+n-1+m-2]={a[n][i],getid(n,i)};
	sort(v+1,v+n+n+m+m-3);
	int cnt=n+n+m+m-4;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==1||i==n||j==1||j==m){
				iT[getid(i,j)]=1;
			}
			if(i+1<=n&&a[i][j]>=0&&a[i+1][j]>=0) add(getid(i,j),getid(i+1,j)),add(getid(i+1,j),getid(i,j));
			
			if(j+1<=m&&a[i][j]>=0&&a[i][j+1]>=0) add(getid(i,j),getid(i,j+1)),add(getid(i,j+1),getid(i,j));
		}
	}
	long long ans=0;
	for(int i=1;i<cnt;++i){
		int p=v[i].id;
		while(push(p,-1)){
			--flow;memset(vis,0,sizeof(vis));
		}
		iT[p]=0;
		Si[p]=1;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=i;++j) if(!vis[v[j].id]){while(push(v[j].id,1)){++flow;memset(vis,0,sizeof(vis));}}
		ans+=1ll*flow*(v[i+1].v-v[i].v);
		memset(vis,0,sizeof(vis));
	}
	printf("%lld\n",ans);
}