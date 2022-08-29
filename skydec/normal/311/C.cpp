#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 210000
LL h;int n,m;
LL key[MAXN];LL Num[MAXN],k;
struct HEAP{
	int heap[MAXN*4],pos[MAXN],size;
	inline bool cmp(int a,int b){
		if(key[a]!=key[b])return key[a]>key[b];
		return a<b;
	}
	inline void Swap(int a,int b){
		swap(heap[a],heap[b]);
		pos[heap[a]]=a;pos[heap[b]]=b;
	}
	inline void up(int x){
		while(x!=1&&cmp(heap[x],heap[x/2])){
			Swap(x,x/2);
			x/=2;
		}
	}
	void down(int x){
		int res=x;
		if(x*2<=size&&cmp(heap[x*2],heap[res]))res=x*2;
		if(x*2+1<=size&&cmp(heap[x*2+1],heap[res]))res=x*2+1;
		Swap(res,x);
		if(res!=x)down(res);
	}
	inline int pop(){
		int x=heap[1];Swap(1,size);size--;down(1);
		pos[x]=0;
		return x;
	}
	inline void push(int x){
		heap[++size]=x;pos[x]=size;
		up(size);
	}
}heap;
struct SPFA{
	int head[MAXN],next[MAXN*20],p[MAXN*20];LL w[MAXN*20];
	int tot;bool inq[MAXN];LL dis[MAXN];int q[MAXN*20];
	inline void L(int a,int b,LL v){
		tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;w[tot]=v;
	}
	inline void Relax(int x){
		for(int u=head[x];u;u=next[u])
		if(dis[p[u]]>dis[x]+w[u]){
			dis[p[u]]=dis[x]+w[u];
			if(!inq[p[u]]){
				inq[p[u]]=1;
				q[++q[0]]=p[u];
			}
		}
	}
	inline void spfa(){
		rep(i,0,k-1){dis[i]=h+1;inq[i]=0;}
		dis[1]=1;inq[1]=1;q[q[0]=1]=1;
		for(int i=1;i<=q[0];i++){
			int x=q[i];
			Relax(x);
			inq[x]=0;
		}
	}
}Spfa;
int yiku;
inline void Renew(){
	Spfa.spfa();
	rep(i,1,n)if(key[i]>=0)if(!heap.pos[i])if(Spfa.dis[Num[i]%k]<=Num[i]){heap.push(i);}
}
inline void TypeOne(){
	LL step;scanf("%I64d",&step);LL u=step%k;
	rep(i,0,k-1)Spfa.L(i,(i+u)%k,step);
	Renew();
}
inline void TypeTwo(){
	int x,y;scanf("%d%d",&x,&y);
	key[x]-=y;
	if(heap.pos[x])heap.down(heap.pos[x]);
}
inline void TypeThree(){
	if(!heap.size){
		printf("0\n");
		return;
	}
	int res=heap.pop();
	printf("%I64d\n",key[res]);
	key[res]=-1;
}
int main(){
	scanf("%I64d%d%d%d",&h,&n,&m,&k);
	rep(i,1,n){scanf("%I64d%d",&Num[i],&key[i]);}
	Renew();
	while(m--){
		int type;scanf("%d",&type);
		if(type==1)TypeOne();
		if(type==2)TypeTwo();
		if(type==3)TypeThree();
	}
	return 0;
}