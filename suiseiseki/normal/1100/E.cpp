#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
#define Maxn 100000
int n,m;
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],value[Maxn+5],come[Maxn+5],tot;
void add_edge(int from,int to,int v){
	arrive[++tot]=to;
	come[tot]=from;
	value[tot]=v;
	nxt[tot]=head[from];
	head[from]=tot;
}
int mx(int a,int b){
	return a>b?a:b;
}
bool visit[Maxn+5];
bool all[Maxn+5];
int in[Maxn+5];
int now_ans;
bool dfs(int root){
	if(visit[root]){
		return 1;
	}
	all[root]=1;
	visit[root]=1;
	for(int i=head[root];i;i=nxt[i]){
		if(value[i]>now_ans){
			if(dfs(arrive[i])){
				return 1;
			}
		}
	}
	visit[root]=0;
	return 0;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(!all[i]){
			if(dfs(i)){
				return 1;
			}
		}
	}
	return 0;
}
queue<int> q;
int left=0,right=1000000000,mid;
void bfs(int x){
	for(int i=head[x];i;i=nxt[i]){
		if(value[i]>left){
			in[arrive[i]]--;
			if(in[arrive[i]]==0){
				q.push(arrive[i]);
			}
		}
	}
}
int num[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	int u,v,c;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&c);
		add_edge(u,v,c);
	}
	while(left<right){
		mid=(left+right)>>1;
		memset(visit,0,sizeof visit);
		memset(all,0,sizeof all);
		now_ans=mid;
		if(check()){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	printf("%d ",left);
	for(int i=1;i<=m;i++){
		if(value[i]>left){
			in[arrive[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	int id=0;
	while(!q.empty()){
		id++;
		num[q.front()]=id;
		bfs(q.front());
		q.pop();
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(value[i]<=left&&num[come[i]]>num[arrive[i]]){
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=m;i++){
		if(value[i]<=left&&num[come[i]]>num[arrive[i]]){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}