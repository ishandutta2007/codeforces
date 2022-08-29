#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 230000
struct seg{
	int L,R;
	int M[MAXN*4];
	int pos[MAXN];
	inline void build(int x,int l,int r){
		if(l==r){pos[l]=x;return;}
		int mid=(l+r)>>1;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
	}
	inline void modi(int x,int v){
		int u=pos[x];
		M[u]=v;u/=2;
		while(u){
			M[u]=max(M[u*2],M[u*2+1]);
			u/=2;
		}
	}
	inline int asker(int now,int l,int r,int x,int y){
		if(x<=l&&r<=y)return M[now];
		int mid=(l+r)>>1;int res=0;
		if(x<=mid)res=max(res,asker(now*2,l,mid,x,y));
		if(y>mid)res=max(res,asker(now*2+1,mid+1,r,x,y));
		return res;
	}
	inline int ask(int x){
		return asker(1,L,R,x+1,R);
	}
}X,Y;
struct Heap{
	int heap[MAXN*4];
	int size;
	void down(int x){
		int res=x;
		if(x*2<=size&&heap[x*2]<heap[res])res=x*2;
		if(x*2+1<=size&&heap[x*2+1]<heap[res])res=x*2+1;
		swap(heap[res],heap[x]);
		if(res!=x)down(res);
	}
	inline void up(int x){
		while(x!=1&&heap[x]<heap[x/2]){
				swap(heap[x],heap[x/2]);
				x/=2;
		}
	}
	inline int pop(){
		int res=heap[1];
		heap[1]=heap[size--];
		down(1);
		return res;
	}
	inline void push(int x){
		heap[++size]=x;
		up(size);
	}
}HEAP;	
int h[MAXN+200];int ak[MAXN];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);HEAP.size=0;
	X.L=1;X.R=n;X.build(1,X.L,X.R);
	Y.L=1;Y.R=220000;Y.build(1,Y.L,Y.R);
	rep(i,1,m){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int x,y;scanf("%d%d",&x,&y);
			y+=200000-i;
			h[y]=x;ak[x]=y;
			rep (j,200000-i,y-1)if(h[j])X.modi(h[j],0);
			int res=X.ask(x)+1;
			X.modi(x,res);
			Y.modi(y,res);
			per(j,y-1,200000-i)if(h[j]){
				res=X.ask(h[j])+1;
				X.modi(h[j],res);
				Y.modi(j,res);
			}
			HEAP.push(x);
		}
		else
		{
			int x;scanf("%d",&x);
			int tmp[20];
			rep(j,1,x-1){
				tmp[j]=HEAP.pop();
				Y.modi(ak[tmp[j]],0);
			}
			int u=HEAP.pop();
			Y.modi(ak[u],0);
			X.modi(u,0);
			h[ak[u]]=0;
			per(j,x-1,1){
				int res=Y.ask(ak[tmp[j]])+1;
				//if(i==m)printf("_%d %d\n",tmp[j],res);
				Y.modi(ak[tmp[j]],res);
				X.modi(tmp[j],res);
				HEAP.push(tmp[j]);
			}
		}
		printf("%d\n",X.M[1]);
		//printf("___");
		//rep(i,1,HEAP.size)printf("%d ",HEAP.heap[i]);printf("\n");
	}
	return 0;
}