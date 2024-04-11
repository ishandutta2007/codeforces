#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include <list>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}
const int maxn=100010;
int N,Q,opt,t1,t2,t3,root,v[maxn];
int tid[maxn],rk[maxn],tim,Prev[maxn],depth[maxn],end[maxn];
int lin[maxn],len;
struct edge{
	int y,next;
}e[maxn<<1];
inline void insert(int xx,int yy){
	e[++len].next=lin[xx];
	lin[xx]=len;
	e[len].y=yy;
}
void dfs(int x,int prev){
	depth[x]=depth[prev]+1;
	tid[x]=++tim;
	rk[tim]=x;
	Prev[x]=prev;
	for(int i=lin[x];i;i=e[i].next)
		if(e[i].y!=prev)
			dfs(e[i].y,x);
	end[x]=tim;
}
int f[17][maxn];
int LCA(int x,int y){
	if(depth[x]<depth[y])
		swap(x,y);
	int dif=depth[x]-depth[y];
	for(int i=16;i>=0;i--)
		if(dif&(1<<i))
			x=f[i][x];
	if(x==y)
		return x;
	for(int i=16;i>=0;i--)
		if(f[i][x]!=f[i][y])
			x=f[i][x],y=f[i][y];
	return f[0][x];
}
int LCALCA(int x,int y){
	int t1=LCA(x,y),t2=LCA(x,root),t3=LCA(y,root);
	if(depth[t1]<depth[t2])
		swap(t1,t2);
	if(depth[t1]<depth[t3])
		return t3;
	return t1;
}
int get_son(int x){
	int temp=root;
	int dif=depth[root]-depth[x]-1;
	for(int i=16;i>=0;i--)
		if(dif&(1<<i))
			temp=f[i][temp];
	return temp;
}
struct Segment_Tree{
	long long sum,tag;
}T[maxn<<2];
int X,Y,Z;
void build(int L,int R,int root){
	if(L==R){
		T[root].sum=v[rk[L]];
		return;
	}
	int mid=(L+R)>>1;
	build(L,mid,root<<1);
	build(mid+1,R,root<<1|1);
	T[root].sum=T[root<<1].sum+T[root<<1|1].sum;
}
void upd(int L,int R,int root){
	if(X>R||Y<L)
		return;
	if(X<=L&&Y>=R){
		T[root].tag+=Z;
		T[root].sum+=1LL*(R-L+1)*Z;
		return;
	}
	int mid=(L+R)>>1;
	if(T[root].tag){
		T[root<<1].tag+=T[root].tag;
		T[root<<1|1].tag+=T[root].tag;
		T[root<<1].sum+=T[root].tag*(mid-L+1);
		T[root<<1|1].sum+=T[root].tag*(R-mid);
		T[root].tag=0;
	}
	upd(L,mid,root<<1);
	upd(mid+1,R,root<<1|1);
	T[root].sum=T[root<<1].sum+T[root<<1|1].sum;
}
long long query(int L,int R,int root){
	if(X>R||Y<L)
		return 0;
	if(X<=L&&Y>=R)
		return T[root].sum;
	int mid=(L+R)>>1;
	if(T[root].tag){
		T[root<<1].tag+=T[root].tag;
		T[root<<1|1].tag+=T[root].tag;
		T[root<<1].sum+=T[root].tag*(mid-L+1);
		T[root<<1|1].sum+=T[root].tag*(R-mid);
		T[root].tag=0;
	}
	return query(L,mid,root<<1)+query(mid+1,R,root<<1|1);
}
int xx[123456];
int main(){
	N=read(),Q=read();root=1;
	for(int i=1;i<=N;i++)
		v[i]=read();
	for(int i=1;i<N;i++){
		t1=read(),t2=read();
		insert(t1,t2);
		insert(t2,t1);
	}
	for(int i=1; i<123456; i++)
    {
        xx[i]++;
    }
	dfs(1,0);
	build(1,N,1);
	for(int i=1;i<=N;i++)
		f[0][i]=Prev[i];
	for(int i=1;i<=16;i++)
		for(int j=1;j<=N;j++)
			f[i][j]=f[i-1][f[i-1][j]];
	while(Q--){
		opt=read();
		if(opt==1)
			root=read();
		else if(opt==2){
			t1=read(),t2=read(),t3=read();
			int lca=LCALCA(t1,t2);
			if(tid[root]>=tid[lca]&&tid[root]<=end[lca]){
				X=1,Y=N,Z=t3;
				upd(1,N,1);
				if(lca==root)
					continue;
				int temp=get_son(lca);
				X=tid[temp],Y=end[temp],Z=-t3;
				upd(1,N,1);
			}
			else{
				X=tid[lca],Y=end[lca],Z=t3;
				upd(1,N,1);
			}
		}
		else{
			int lca=read();
			if(lca==root){
				X=1,Y=N;
				printf("%I64d\n",query(1,N,1));
			}
			else if(tid[root]>=tid[lca]&&tid[root]<=end[lca]){
				long long ans=0;
				X=1,Y=N;
				ans=query(1,N,1);
				int temp=get_son(lca);
				X=tid[temp],Y=end[temp];
				ans-=query(1,N,1);
				printf("%I64d\n",ans);
			}
			else{
				X=tid[lca],Y=end[lca];
				printf("%I64d\n",query(1,N,1));
			}
		}
	}
	return 0;
}