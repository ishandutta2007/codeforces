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
namespace fastio{
	inline bool read(int &x){
		x=0;char ch=getchar(),flag=0;
		while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
		if(ch=='-') flag=1,ch=getchar();
		if(ch>'9'||ch<'0') return 0;
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(flag) x=-x;
		return 1;
	}
	inline bool read(int &x,int &y){return (read(x)&&read(y));}
	inline bool read(int &x,int &y,int &z){return (read(x)&&read(y)&&read(z));}
	inline void _put(int x){
		if(!x){putchar('0');return;}
		int a[20],m=0;
		while(x) a[m++]=x%10,x/=10;
		while(m--) putchar(a[m]+'0');
	}
	inline void print(int x){_put(x);puts("");}
	inline void print(int x,int y){_put(x);putchar(' ');_put(y);puts("");}
	inline void print(int x,int y,int z){_put(x);putchar(' ');_put(y);putchar(' ');_put(z);puts("");}
	inline void _print(int x){_put(x);putchar(' ');}
	inline void _print(int x,int y){_print(x);_print(y);}
	inline void _print(int x,int y,int z){_print(x,y);_print(z);}
};
namespace counter{
	int x=0;
	inline int CASE(){printf("Case %d: ",++x);}
	inline int CASE2(){printf("Case #%d: ",++x);}
};
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
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
using namespace fastio;


const int N=3010,mod=N-5,M=N*10;
const int INF=1e9+7;
const ll inf=1ll<<60;

struct node{
	int to,next;
	ll flow;
	int cost;
}p[M];
int head[N],tot,n,q[N],S,T,from[N],use[N],d[N];
int a[N];
bool vis[N];
inline void add(int x,int y,ll f,int w){
//	printf("%d %d %I64d %d\n",x,y,f,w);
	p[tot]=(node){y,head[x],f,w};head[x]=tot++;
	p[tot]=(node){x,head[y],0,-w};head[y]=tot++;
}
inline int inc(int &x){x++;if(x>=mod) x-=mod;return x;}
inline bool spfa(){
	int h=0,t=1;
	memset(vis,0,sizeof(vis));
	for(int i=S;i<=T;i++) d[i]=INF;
	vis[S]=1;q[t]=S;d[S]=0;
	while(h!=t){
		int x=q[inc(h)];vis[x]=0;
		for(int i=head[x];~i;i=p[i].next){
			if(!p[i].flow) continue;
			int y=p[i].to,w=p[i].cost;
			if(d[y]>d[x]+w){
				d[y]=d[x]+w;from[y]=x;use[y]=i;
				if(!vis[y]) q[inc(t)]=y,vis[y]=1;
			}
		}
	}
//	for(int i=S;i<=T;i++) printf("%d ",d[i]);puts("");
	return d[T]<INF;
}
inline ll extend(){
	int x=T;ll minx=inf,ans=0;
	while(x!=S){
		minx=min(minx,p[use[x]].flow);
		x=from[x];
	}
//	printf("flow:%I64d\n",minx);
	x=T;
	while(x!=S){
		p[use[x]].flow-=minx;p[use[x]^1].flow+=minx;
		ans+=minx*p[use[x]].cost;
		x=from[x];
	}
	return ans;
}

int main(){
	memset(head,-1,sizeof(head));
	read(n);S=0;T=n+2;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++){
		add(i,i+1,inf,1),add(i+1,i,inf,1);
//		printf("%d\n",a[i]-a[i-1]-1);
		if(a[i]-a[i-1]-1>0) add(S,i,a[i]-a[i-1]-1,0); else add(i,T,a[i-1]+1-a[i],0);
	}
	add(S,1,inf,0);
	add(S,n+1,inf,0);
	ll ans=0;
	while(spfa()) ans+=extend();
	printf("%I64d\n",ans);
	return 0;
}