#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 400005
#define For(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int Ans[2*N],L,R,n;
struct rec{
	int ll,rr,Ret,tot,Delete[N];
	int pa[N],fa[N],dis[N],pos[N],size[N];
	int son[4*N],next[25*N],ed[25*N],cnt;
	
	void link(int x,int y){
//		printf("link %d -> %d\n",x,y);
		next[++cnt]=son[x]; son[x]=cnt; ed[cnt]=y;}
	void Modify(int t,int l,int r){
		if(ll<=l&&r<=rr){
			link(t,Ret);
			return;
		}
		int mid=(l+r)>>1;
		if(ll<=mid) Modify(t*2,l,mid);
		if(rr>mid) Modify(t*2+1,mid+1,r);
	}
	void Query(int t,int l,int r){
		for(int j=son[t];j;j=next[j])
		if(!Delete[ed[j]]){
			Delete[ed[j]]=1;
			Ans[++R]=ed[j];
		}
		son[t]=0;
		
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ll<=mid) Query(t*2,l,mid);
		else Query(t*2+1,mid+1,r);
	}
	void Insert(int x,int y,int id){
//		printf("-------Insert x y %d %d id %d\n",x,y,id);
		while(pa[x]!=pa[y]){
//			printf("Find %d %d\n",x,y);
			if(dis[fa[pa[x]]]<dis[fa[pa[y]]]) swap(x,y);
			Ret=id; ll=pos[pa[x]]; rr=pos[x]; Modify(1,1,n);
//			printf("Add %d ll rr %d %d\n",Ret,ll,rr);
			x=fa[pa[x]];
		}
//		printf("Fineded %d %d\n",x,y);
		if(dis[x]<dis[y]) swap(x,y);
		Ret=id; ll=pos[y]+1; rr=pos[x]; if(ll<=rr) Modify(1,1,n);
//		printf("Add %d ll rr %d %d\n",Ret,ll,rr);
		
	}
	void dfs1(int t){
		size[t]=1;
		for(int i=son[t];i;i=next[i]){
			dis[ed[i]]=dis[t]+1;
			dfs1(ed[i]);
			size[t]+=size[ed[i]];
		}
	}
	void dfs2(int t){
		pos[t]=++tot;
		
		int v=0;
		for(int i=son[t];i;i=next[i])
		if(size[ed[i]]>size[v]) v=ed[i];
		
		if(v) pa[v]=pa[t],dfs2(v);
		
		for(int i=son[t];i;i=next[i])
		if(ed[i]!=v){
			pa[ed[i]]=ed[i];
			dfs2(ed[i]);
		}
	}
	void read(){
		For(i,2,n) scanf("%d",&fa[i]),link(fa[i],i);
		pa[1]=1; dis[1]=1; dfs1(1); dfs2(1);
		For(i,1,n) son[i]=0; cnt=0;
		
//		For(i,1,n) printf("%d ",fa[i]); printf("fa\n");
//		For(i,1,n) printf("%d ",pa[i]); printf("pa\n");
//		For(i,1,n) printf("%d ",pos[i]); printf("pos\n");

	}
	void doit(int t){ll=pos[t+1]; Query(1,1,n);}
	void work(int l,int r){
		sort(Ans+l,Ans+r+1);
		For(i,l,r) printf("%d ",Ans[i]); printf("\n");
		For(i,l,r) doit(Ans[i]); L=r;
	}
}Tree[2];
int main(){
	
	scanf("%d",&n);
	Tree[0].read();
	Tree[1].read();
	
	
	For(i,2,n) Tree[1].Insert(i,Tree[0].fa[i],i-1);
	For(i,2,n) Tree[0].Insert(i,Tree[1].fa[i],i-1);
	
	
	scanf("%d",&Ans[++R]); Tree[1].Delete[Ans[R]]=1;
	
	while(L<R){
		if(L<R) printf("Blue\n"),Tree[0].work(L+1,R);
		if(L<R) printf("Red\n" ),Tree[1].work(L+1,R);
	}
	
//	for(;;);
	
//	printf("R %d\n",R);
}