#include <ctime>
#include <random>
#include <cstdio>
#include <algorithm>
const int Maxn=800000;
const int Maxm=800000;
std::mt19937 rnd(time(NULL));
struct LCT_node{
	int fa,ch[2];
	int val;
	int sum;
	bool rev;
}node[Maxn+5];
int n,m;
int identify(int x){
	return node[node[x].fa].ch[1]==x;
}
bool nroot(int x){
	return node[node[x].fa].ch[0]==x||node[node[x].fa].ch[1]==x;
}
void update_rev(int root){
	node[root].rev^=1;
	std::swap(node[root].ch[0],node[root].ch[1]);
}
void push_down(int root){
	if(node[root].rev){
		update_rev(node[root].ch[0]);
		update_rev(node[root].ch[1]);
		node[root].rev=0;
	}
}
void push_up(int root){
	node[root].sum=node[node[root].ch[0]].sum^node[node[root].ch[1]].sum^node[root].val;
}
void connect(int x,int fa,int son){
	node[fa].ch[son]=x;
	if(x){
		node[x].fa=fa;
	}
}
void rotate(int x){
	int y=node[x].fa,z=node[y].fa;
	int id_x=identify(x),id_y=identify(y);
	int B=node[x].ch[id_x^1];
	connect(B,y,id_x);
	if(nroot(y)){
		connect(x,z,id_y);
	}
	else{
		node[x].fa=z;
	}
	connect(y,x,id_x^1);
	push_up(y);
	push_up(x);
}
void push_all(int x){
	if(nroot(x)){
		push_all(node[x].fa);
	}
	push_down(x);
}
void splay(int x){
	push_all(x);
	while(nroot(x)){
		int y=node[x].fa;
		if(nroot(y)){
			identify(x)==identify(y)?rotate(y):rotate(x);
		}
		rotate(x);
	}
}
void access(int x){
	for(int i=0;x;x=node[i=x].fa){
		splay(x);
		node[x].ch[1]=i;
		push_up(x);
	}
}
int find_root(int x){
	access(x);
	splay(x);
	int u=x;
	while(node[u].ch[0]){
		push_down(u);
		u=node[u].ch[0];
	}
	splay(u);
	return u;
}
void make_root(int x){
	access(x);
	splay(x);
	update_rev(x);
}
void link(int x,int y){
	make_root(x);
	if(find_root(y)!=x){
		node[x].fa=y;
	}
}
void split(int x,int y){
	make_root(x);
	access(y);
	splay(y);
}
void cut(int x,int y){
	make_root(x);
	if(find_root(y)!=x||node[y].fa!=x||node[y].ch[0]!=0){
		return;
	}
	node[x].ch[1]=node[y].fa=0;
	push_up(x);
}
void dfs(int x){
	if(x==0){
		return;
	}
	dfs(node[x].ch[0]),dfs(node[x].ch[1]);
	if(x>n){
		node[x].val=rnd();
	}
	push_up(x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		int id=i+n;
		node[id].val=v;
		if(find_root(x)!=find_root(y)){
			link(x,id),link(y,id);
			puts("YES");
		}
		else{
			split(x,y);
			if((node[y].sum^v)==1){
				puts("YES");
				dfs(y);
			}
			else{
				puts("NO");
			}
		}
	}
	return 0;
}