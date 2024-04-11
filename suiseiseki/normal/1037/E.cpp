#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define Maxn 2000000
struct Node1{
	int u,v;
};
struct Node2{
	int id,v,next;
};
queue<int> que;
Node1 pre[Maxn+5];
Node2 edge[(Maxn<<1)+5];
int first[Maxn+5],degree[Maxn+5],ans[Maxn+5];
bool flag[Maxn+5],book[Maxn+5];
int n,m,k,num;
void add_edge(int id,int u,int v){
	edge[num].id=id;
	edge[num].v=v;
	edge[num].next=first[u];
	first[u]=num++;
}
void init(){
	int id,u,v;
	for(int i=1;i<=n;i++){
		if(degree[i]<k){
			que.push(i);
			book[i]=1;
		}
	}
	while(!que.empty()){
		u=que.front();
		que.pop();
		for(int i=first[u];i!=-1;i=edge[i].next){
			id=edge[i].id,v=edge[i].v;
			if(flag[id]==0){
				degree[v]--;
				if(degree[v]<k&&book[v]==0){
					que.push(v);
					book[v]=1;
				}
				flag[id]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			ans[m]++;
		}
	}
}
void work(){
	int id,u,v;
	for(int i=m;i>0;i--){
		ans[i-1]=ans[i];
		if(flag[i]){
			continue;
		}
		flag[i]=1;
		degree[pre[i].u]--,degree[pre[i].v]--;
		if(degree[pre[i].u]<k&&book[pre[i].u]==0){
			que.push(pre[i].u);
			book[pre[i].u]=1;
			ans[i-1]--;
		}
		if(degree[pre[i].v]<k&&book[pre[i].v]==0){
			que.push(pre[i].v);
			book[pre[i].v]=1;
			ans[i-1]--;
		}
		while(!que.empty()){
			u=que.front();
			que.pop();
			for(int j=first[u];j!=-1;j=edge[j].next){
				id=edge[j].id,v=edge[j].v;
				if(!flag[id]){
					degree[v]--;
					if(degree[v]<k&&book[v]==0){
						que.push(v);
						book[v]=1;
						ans[i-1]--;
					}
					flag[id]=1;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	memset(first,-1,sizeof first);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&pre[i].u,&pre[i].v);
		add_edge(i,pre[i].u,pre[i].v);
		add_edge(i,pre[i].v,pre[i].u);
		degree[pre[i].u]++,degree[pre[i].v]++;
	}
	init();
	work();
	return 0;
}