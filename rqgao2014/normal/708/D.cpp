#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=105,M=N*N*5,mod=100,inf=1e9;
struct node{
	int to,next,flow,cost;
}p[M];
int head[N],tot,n,m,k,q[N],S,T,from[N],use[N],d[N],x[N],y[N],du[N];
bool vis[N];
inline void add(int x,int y,int f,int w){
	p[tot]=(node){y,head[x],f,w};head[x]=tot++;
	p[tot]=(node){x,head[y],0,-w};head[y]=tot++;
}
inline int inc(int &x){x++;if(x>=mod) x-=mod;return x;}
inline bool spfa(){
	int h=0,t=1;
	memset(vis,0,sizeof(vis));
	for(int i=S;i<=T;i++) d[i]=inf;
	vis[S]=1;q[t]=S;d[S]=0;
	while(h!=t){
		int x=q[inc(h)];vis[x]=0;
		for(int i=head[x];~i;i=p[i].next){
			if(!p[i].flow) continue;
			int y=p[i].to;int w=p[i].cost;
			if(d[y]>d[x]+w){
				d[y]=d[x]+w;from[y]=x;use[y]=i;
				if(!vis[y]) q[inc(t)]=y,vis[y]=1;
			}
		}
	}
	return d[T]<inf;
}
inline int extend(){
	int x=T,ans=0,maxx=inf;
	while(x!=S){
		maxx=min(p[use[x]].flow,maxx);
		x=from[x];
	}
	x=T;
	while(x!=S){
		p[use[x]].flow-=maxx;p[use[x]^1].flow+=maxx;
		ans+=p[use[x]].cost*maxx;
		x=from[x];
	}
	return ans;
}

int main(){
	memset(head,-1,sizeof(head));
	read(n,m);S=0;T=n+1;
	int ans=0,cap=0;
	for(int i=1;i<=m;i++){
		int x,y,c,f;
		read(x,y);read(c,f);
		du[x]-=f;du[y]+=f;
		if(c>=f){
			add(y,x,f,1);
			add(x,y,c-f,1);
			add(x,y,inf,2);
		}
		else{
			ans+=f-c;
			add(y,x,c,1);
			add(y,x,f-c,0);
			add(x,y,inf,2);
		}
	}
	for(int i=1;i<=n;i++)
		if(du[i]>0) add(S,i,du[i],0);
		else if(du[i]<0) add(i,T,-du[i],0);
	add(n,1,inf,0);
//	debuge;
	while(spfa()){//printf("%d\n",ans);
		ans+=extend(),cap++;
		
	}
	printf("%d\n",ans);
	return 0;
}