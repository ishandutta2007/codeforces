#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
int m;
struct Node{
	int lowbit(int x){
		return x&(-x);
	}
	int x,y;
	void read(){
		scanf("%d%d",&x,&y);
	}
	Node(int _x=0,int _y=0){
		x=_x;
		y=_y;
	}
	int dep(){
		return x+y;
	}
	Node fa(){
		if(x==0&&y==0){
			return Node(-1,0);
		}
		if(x==0){
			return Node(x,y-1);
		}
		if(y==0){
			return Node(x-1,y);
		}
		if(lowbit(x)<lowbit(y)){
			return Node(x-1,y);
		}
		return Node(x,y-1);
	}
	Node top(){
		if(x==0||y==0){
			return Node(0,0);
		}
		if(lowbit(x)<lowbit(y)){
			return Node(x-(x&(lowbit(y)-1)),y);
		}
		return Node(x,y-(y&(lowbit(x)-1)));
	}
	friend bool operator <(Node a,Node b){
		if(a.x==b.x){
			return a.y<b.y;
		}
		return a.x<b.x;
	}
	friend bool operator >(Node a,Node b){
		if(a.x==b.x){
			return a.y>b.y;
		}
		return a.x>b.x;
	}
	friend bool operator ==(Node a,Node b){
		return a.x==b.x&&a.y==b.y;
	}
	friend bool operator !=(Node a,Node b){
		return !(a==b);
	}
	friend bool same_line(Node a,Node b){
		return a.top()==b.top()&&(a.x==b.x||a.y==b.y);
	}
};
Node d[Maxn<<2|5];
map<Node,int> id;
int d_len;
Node find_lca(Node u,Node v){
	while(!same_line(u,v)){
		if(u.top().dep()>v.top().dep()){
			u=u.top();
		}
		else{
			v=v.top();
		}
	}
	if(u.dep()<v.dep()){
		return u;
	}
	return v;
}
bool cmp_dfn(Node u,Node v){
	if(u==v){
		return 0;
	}
	Node tmp_u=u,tmp_v=v;
	while(!same_line(u,v)){
		if(u.top().dep()>v.top().dep()){
			u=u.top();
		}
		else{
			v=v.top();
		}
	}
	Node lca;
	if(u.dep()<v.dep()){
		lca=u;
	}
	else{
		lca=v;
	}
	if(tmp_u==lca){
		return 1;
	}
	if(tmp_v==lca){
		return 0;
	}
	if(u.y==v.y){
		return u.x<v.x;
	}
	return u.y>v.y;
}
struct Edge{
	Node u,v;
}edge[Maxn+5];
int head[Maxn<<2|5],arrive[Maxn<<2|5],nxt[Maxn<<2|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int st[Maxn<<2|5],top;
int build(){
	sort(d+1,d+1+d_len,cmp_dfn);
	for(int i=1;i<=d_len;i++){
		id[d[i]]=i;
	}
	int _d_len=d_len;
	top=0;
	st[++top]=1;
	for(int i=2;i<=_d_len;i++){
		Node lca_node=find_lca(d[i],d[st[top]]);
		if(id.count(lca_node)==0){
			d[++d_len]=lca_node;
			id[lca_node]=d_len;
		}
		int lca=id[lca_node];
		while(top>1&&d[lca].dep()<d[st[top-1]].dep()){
			add_edge(st[top-1],st[top]);
			top--;
		}
		if(top&&d[lca].dep()<d[st[top]].dep()){
			add_edge(lca,st[top]);
			top--;
			if(lca!=st[top]){
				st[++top]=lca;
			}
		}
		st[++top]=i;
	}
	while(top>1){
		add_edge(st[top-1],st[top]);
		top--;
	}
	d_len=_d_len;
	return st[1];
}
int sum[Maxn<<2|5];
bool tag[Maxn<<2|5];
int dep[Maxn<<2|5];
int lis[Maxn<<3|5],lis_len;
void sum_dfs(int u,int fa){
	dep[u]=d[u].dep();
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		sum_dfs(v,u);
		sum[u]+=sum[v];
	}
	if(sum[u]){
		lis[++lis_len]=dep[fa]+1;
		lis[++lis_len]=dep[u]+1;
	}
	else if(tag[u]){
		lis[++lis_len]=dep[u];
		lis[++lis_len]=dep[u]+1;
	}
}
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		edge[i].u.read();
		edge[i].v.read();
		d[++d_len]=edge[i].u;
		d[++d_len]=edge[i].v;
	}
	sort(d+1,d+1+d_len);
	d_len=unique(d+1,d+1+d_len)-d-1;
	int root=build();
	for(int i=1;i<=m;i++){
		int u=id[edge[i].u],v=id[edge[i].v],lca=id[find_lca(edge[i].u,edge[i].v)];
		sum[u]++,sum[v]++,sum[lca]-=2;
		tag[lca]=1;
	}
	sum_dfs(root,0);
	sort(lis+1,lis+1+lis_len);
	int ans=0,num_0=0;
	for(int i=1,j;i<=lis_len;i=j+1){
		j=i;
		while(j<=lis_len&&lis[j]==lis[i]){
			j++;
		}
		j--;
		if(lis[i]==0){
			num_0=((j-i+1)&1);
		}
		else{
			ans+=((j-i+1)&1);
		}
	}
	if((ans&1)!=num_0){
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}