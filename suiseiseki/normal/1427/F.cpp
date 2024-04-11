#include <list>
#include <cstdio>
using namespace std;
const int Maxn=200;
int n;
bool bel[Maxn*6+5];
int st[Maxn*6+5],top;
int col[Maxn*6+5];
int to[Maxn*6+5];
struct Node{
	int a,b,c;
}a[Maxn<<1|5];
int id_tot;
int head[Maxn<<1|5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
int out[Maxn<<1|5],in[Maxn<<1|5];
void add_edge(int from,int to){
	out[from]++;
	in[to]++;
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
list<int> q[2];
int ans[Maxn<<1|5],len;
void work_bfs(){
	for(int i=1;i<=id_tot;i++){
		if(in[i]==0){
			if(out[i]){
				q[bel[a[i].a]].push_front(i);
			}
			else{
				q[bel[a[i].a]].push_back(i);
			}
		}
	}
	int start=1;
	while(!q[start].empty()){
		int u=q[start].front();
		q[start].pop_front();
		ans[++len]=u;
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			in[v]--;
			if(in[v]==0){
				if(out[v]){
					q[bel[a[v].a]].push_front(v);
				}
				else{
					q[bel[a[v].a]].push_back(v);
				}
			}
		}
		start^=1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++){
		int x;
		scanf("%d",&x);
		bel[x]=1;
	}
	for(int i=1;i<=6*n;i++){
		st[++top]=i;
		while(top>=3&&bel[st[top]]==bel[st[top-1]]&&bel[st[top-1]]==bel[st[top-2]]){
			a[++id_tot].a=st[top-2];
			a[id_tot].b=st[top-1];
			a[id_tot].c=st[top];
			col[st[top-2]]=col[st[top-1]]=col[st[top]]=id_tot;
			to[id_tot]=st[top-3];
			top-=3;
		}
	}
	for(int i=1;i<=id_tot;i++){
		if(to[i]){
			add_edge(i,col[to[i]]);
		}
	}
	work_bfs();
	for(int i=1;i<=len;i++){
		printf("%d %d %d\n",a[ans[i]].a,a[ans[i]].b,a[ans[i]].c);
	}
	return 0;
}