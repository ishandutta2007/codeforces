#include <cstdio>
#include <queue>
using namespace std;
#define Maxn 100000
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool visit[Maxn+5];
priority_queue<int,vector<int>,greater<int> > q;
int a[Maxn+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	q.push(1);
	visit[1]=1;
	int len=0;
	while(!q.empty()){
		u=q.top();
		a[++len]=u;
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			if(!visit[arrive[i]]){
				visit[arrive[i]]=1;
				q.push(arrive[i]);
			}
		}
	}
	for(int i=1;i<=len;i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}