#include <map>
#include <queue>
#include <vector>
#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100;
int n;
bool t[Maxn+5],vis[Maxn+5];
struct Bit{
	bitset<Maxn+5> a;
	int id;
	friend bool operator <(Bit a,Bit b){
		for(int i=n;i>=0;i--){
			if(a.a[i]!=b.a[i]){
				return a.a[i]<b.a[i];
			}
		}
		return 0;
	}
	int count(){
		for(int i=n;i>=0;i--){
			if(a[i]){
				return i;
			}
		}
		return -1;
	}
}f[Maxn+5];
struct Edge{
	int u,v;
}edge[Maxn+5];
map<pair<int,int>,int> col;
priority_queue<Bit> q;
vector<int> g[Maxn+5];
bool check(vector<Bit> a){
	if(a.empty()){
		return 1;
	}
	for(vector<Bit>::iterator it=a.begin();it!=a.end();it++){
		q.push(*it);
	}
	for(int i=n;i>=0;i--){
		if(t[i]==0){
			continue;
		}
		Bit u=q.top();
		q.pop();
		int now=u.count();
		if(now>i){
			break;
		}
		else if(now==i){
			u.a[now]=0;
			q.push(u);
		}
		if(q.empty()){
			return 1;
		}
	}
	while(!q.empty()){
		q.pop();
	}
	return 0;
}
void re_build(int x,vector<Bit> a){
	if(a.empty()){
		return;
	}
	for(vector<Bit>::iterator it=a.begin();it!=a.end();it++){
		q.push(*it);
	}
	for(int i=n;i>=0;i--){
		if(!t[i]){
			continue;
		}
		Bit u=q.top();
		q.pop();
		int now=u.count();
		if(now==i){
			u.a[now]=0;
			q.push(u);
		}
		else{
			col[make_pair(u.id,x)]=col[make_pair(x,u.id)]=i;
		}
		if(q.empty()){
			return;
		}
	}
	while(!q.empty()){
		q.pop();
	}
}
void init_dfs(int u,int fa){
	vector<Bit> a;
	f[u].id=u;
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		a.push_back(f[v]);
	}
	for(int i=0;i<=n;i++){
		t[i]=1;
	}
	for(int i=n;i>=0;i--){
		t[i]=0;
		if(!check(a)){
			t[i]=1;
		}
	}
	for(int i=0;i<=n;i++){
		f[u].a[i]=t[i];
	}
	re_build(u,a);
}
int maxn;
pair<int,int> id;
void work_dfs(int u,int fa){
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(vis[v]||v==fa){
			continue;
		}
		int k=col[make_pair(u,v)];
		if(k>maxn){
			maxn=k;
			id=make_pair(u,v);
		}
		work_dfs(v,u);
	}
}
void solve(int u,int fa){
	maxn=-1;
	work_dfs(u,fa);
	if(maxn==-1){
		printf("! %d\n",u);
		fflush(stdout);
		return;
	}
	printf("? %d %d\n",id.first,id.second);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	if(r==id.first){
		vis[id.second]=1;
		solve(id.first,id.first);
	}
	else{
		vis[id.first]=1;
		solve(id.second,id.second);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	init_dfs(1,1);
	solve(1,1);
	return 0;
}