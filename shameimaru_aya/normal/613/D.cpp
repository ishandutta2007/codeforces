#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w*=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
struct node{ int id,val; }p[N];
struct TREE{ int v,nex; }tree[2*N]; //
struct NewTREE{ int v,nex; }Newtree[2*N]; // 
int n,T,t,cnt,tot,Newtot,ans,num;
int mk[N],dfn[N],siz[N],father[N];
int first[N],head[N],point[N];
int deep[N],f[N][25];
int top,st[N];
bool vis[N],Judge[N];
queue<int> q;
inline bool cmp(node x,node y) { return x.id<y.id; }
inline void Add(int x,int y)
{
	tree[++tot].nex=first[x];
	first[x]=tot,tree[tot].v=y;
}
inline void NewAdd(int x,int y)
{
	Newtree[++Newtot].nex=head[x];
	head[x]=Newtot,Newtree[Newtot].v=y;
}
inline void DFS(int u,int fa)
{
	father[u]=fa,dfn[u]=++cnt;
	for(register int i=first[u];i;i=tree[i].nex)
		if(tree[i].v!=fa) DFS(tree[i].v,u);
}
inline void BFS()
{
	q.push(1),deep[1]=1;
	while(q.size()){
		int x=q.front(); q.pop();
		for(register int i=first[x];i;i=tree[i].nex){
			int y=tree[i].v;
			if(deep[y]) continue;
			deep[y]=deep[x]+1;
			f[y][0]=x;
			for(register int j=1;j<=t;j++) f[y][j]=f[f[y][j-1]][j-1];
			q.push(y);
		}
	}
}
inline int LCA(int x,int y)
{
	if(deep[x]>deep[y]) swap(x,y);
	for(register int i=t;i>=0;i--)
		if(deep[f[y][i]]>=deep[x]) y=f[y][i];
	if(x==y) return x;
	for(register int i=t;i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline void Solve(int u,int fa)
{ 
	for(register int i=head[u];i;i=Newtree[i].nex)
		if(Newtree[i].v!=fa) Solve(Newtree[i].v,u);
	if(vis[u]){ // 
		ans=ans+siz[u],siz[fa]+=1;
	}
	else{
		if(siz[u]>1) ans+=1;
		else siz[fa]+=(!!siz[u]);
	}
}
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("sol.out","w",stdout);
	n=read();
	t=(int)(log(n)/log(2))+1;
	for(register int i=1;i<n;i++){
		int x=read(),y=read();
		Add(x,y),Add(y,x);
	}
	DFS(1,0);
	BFS(); 
	T=read();
	while(T--){
		Newtot=0,top=0,ans=0,num=0;
		bool flag=false;
		int m=read();
		for(register int i=1;i<=m;i++){
			mk[i]=read();
			vis[mk[i]]=true;
			p[i].val=mk[i],p[i].id=dfn[mk[i]];
		}
		for(register int i=1;i<=m;i++){
			if(vis[father[mk[i]]]) { flag=true; break; }
		}
		if(flag){ 
			puts("-1"); 
			for(register int i=1;i<=m;i++) vis[mk[i]]=false;
			continue; 
		}
		sort(p+1,p+m+1,cmp);
		st[++top]=1;
		// 
		for(register int i=1;i<=m;i++){
			if(p[i].val==st[top]) continue;
			int l=LCA(p[i].val,st[top]);
			if(l==st[top]) st[++top]=p[i].val;
			else{
				while(deep[st[top-1]]>deep[l]&&top>1){
					//cout<<st[top-1]<<" "<<st[top]<<endl;
					NewAdd(st[top-1],st[top]),NewAdd(st[top],st[top-1]);
					if(!Judge[st[top]]) Judge[st[top]]=true,point[++num]=st[top];
					if(!Judge[st[top-1]]) Judge[st[top-1]]=true,point[++num]=st[top-1];
					top--;
				}
				if(deep[st[top]]>deep[l]){
					//cout<<st[top]<<" "<<l<<endl;
					NewAdd(st[top],l),NewAdd(l,st[top]);
					if(!Judge[st[top]]) Judge[st[top]]=true,point[++num]=st[top];
					if(!Judge[l]) Judge[l]=true,point[++num]=l;
					top--;
				}
				if(st[top]!=l||!top) st[++top]=l;
				st[++top]=p[i].val;
			}
		}
		while(top>1){
			NewAdd(st[top-1],st[top]),NewAdd(st[top],st[top-1]);
			//cout<<st[top-1]<<" "<<st[top]<<endl;
			if(!Judge[st[top]]) Judge[st[top]]=true,point[++num]=st[top];
			if(!Judge[st[top-1]]) Judge[st[top-1]]=true,point[++num]=st[top-1];
			top--;
		}
		Solve(1,0);
		printf("%d\n",ans);
		for(register int i=0;i<=Newtot;i++) Newtree[i].nex=0;
		for(register int i=1;i<=num;i++){
			Judge[point[i]]=false;
			head[point[i]]=0,siz[point[i]]=0; 
		}
		for(register int i=1;i<=m;i++) vis[mk[i]]=false;
	}
	return 0;
}