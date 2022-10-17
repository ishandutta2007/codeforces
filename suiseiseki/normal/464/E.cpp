#include <queue>
#include <cstdio>
using namespace std;
#define Maxn 100000
#define Mod 1000000007
int n,m,st,ed,lim,bin[Maxn<<1|5];
int tot,head[Maxn+5],pre[Maxn+5];
struct Edge{
	int to,nxt,val;
}e[Maxn<<1|5];
void add(int from,int to,int val){
	e[++tot].to=to;
	e[tot].val=val;
	e[tot].nxt=head[from];
	head[from]=tot;
}
void chkMax(int &x,int y){
	if(y>x){
		x=y;
	}
}
namespace PSegT{
	struct SegNode{
		int lc,rc,w;
	}s[Maxn*120+5];
	int nodeCnt,root[Maxn+5];
	#define mid ((l+r)>>1)
	bool cmp(int x,int l,int r,int y){
		if(l==r){
			return s[x].w>s[y].w;
		}
		if(s[s[x].rc].w==s[s[y].rc].w){
			return cmp(s[x].lc,l,mid,s[y].lc);
		}
		else{
			return cmp(s[x].rc,mid+1,r,s[y].rc);
		}
	}
	bool modify(int &x,int l,int r,int pos,int y){
		s[x=++nodeCnt]=s[y];
		if(l==r){
			s[x].w=s[y].w^1;
			return s[y].w;
		}
		int res;
		if(pos>mid){
			res=modify(s[x].rc,mid+1,r,pos,s[y].rc);
		}
		else{
			res=modify(s[x].lc,l,mid,pos,s[y].lc);
			if(res){
				res=modify(s[x].rc,mid+1,r,mid+1,s[y].rc);
			}
		}
		s[x].w=(1ll*s[s[x].rc].w*bin[mid-l+1]%Mod+s[s[x].lc].w)%Mod;
		return res;
	}
}using namespace PSegT;
struct Node{
	int x,rt;
	friend bool operator <(Node p,Node q){
		return cmp(p.rt,0,lim,q.rt);
	}
};
priority_queue<Node> Q;
void dfs(int x,int dep){
	if(x==st){
		printf("%d\n%d ",dep,x);
		return;
	}
	dfs(pre[x],dep+1);
	printf("%d ",x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int x,y,v,i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v);
		add(y,x,v);
		chkMax(lim,v);
	}
	scanf("%d%d",&st,&ed);
	bin[0]=1;
	lim+=100;
	for(int i=1;i<=lim;i++){
		bin[i]=(bin[i-1]<<1)%Mod;
	}
	nodeCnt=0;
	Q.push((Node){st,root[st]});
	while(!Q.empty()){
		Node now=Q.top();
		Q.pop();
		if(now.rt!=root[now.x]){
			continue;
		}
		if(now.x==ed){
			printf("%d\n",s[root[ed]].w);
			dfs(ed,1);
			puts("");
			return 0;
		}
		for(int i=head[now.x];i;i=e[i].nxt){
			int y=e[i].to,v;
			modify(v,0,lim,e[i].val,root[now.x]);
			if(!root[y]||cmp(root[y],0,lim,v)){
				root[y]=v;
				Q.push((Node){y,root[y]});
				pre[y]=now.x;
			}
		}
	}
	puts("-1");
	return 0;
}