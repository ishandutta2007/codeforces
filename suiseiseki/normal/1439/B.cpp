#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=100000;
unordered_set<int> st[Maxn+5];
int n,m,k;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int deg[Maxn+5];
bool vis[Maxn+5];
void init(){
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=deg[i]=0;
		vis[i]=0;
		st[i].clear();
	}
}
queue<int> q;
int tmp_deg[Maxn+5];
bool work_bfs(){
	while(!q.empty()){
		q.pop();
	}
	for(int i=1;i<=n;i++){
		tmp_deg[i]=deg[i];
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(tmp_deg[i]<k){
			q.push(i);
			vis[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			tmp_deg[v]--;
			if(tmp_deg[v]<k&&(!vis[v])){
				q.push(v);
				vis[v]=1;
			}
		}
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			num++;
		}
	}
	if(num>0){
		printf("1 %d\n",num);
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				printf("%d ",i);
			}
		}
		puts("");
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	return num>0;
}
void calc_bfs(){
	while(!q.empty()){
		q.pop();
	}
	for(int i=1;i<=n;i++){
		tmp_deg[i]=deg[i];
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(tmp_deg[i]<k-1){
			q.push(i);
			vis[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			tmp_deg[v]--;
			if(tmp_deg[v]<k-1&&(!vis[v])){
				vis[v]=1;
				q.push(v);
			}
		}
	}
}
vector<int> lis;
void del(int x){
	for(int i=head[x];i;i=nxt[i]){
		int v=arrive[i];
		tmp_deg[v]--;
		if(tmp_deg[v]==k-1){
			q.push(v);
		}
	}
}
bool check(int x){
	if(tmp_deg[x]!=k-1){
		del(x);
		vis[x]=1;
		return 0;
	}
	lis.clear();
	lis.push_back(x);
	int num=0;
	for(int i=head[x];i;i=nxt[i]){
		int v=arrive[i];
		if(!vis[v]){
			num++;
			lis.push_back(v);
		}
	}
	if(num!=k-1){
		del(x);
		vis[x]=1;
		return 0;
	}
	for(int i=0;i<(int)lis.size();i++){
		for(int j=i+1;j<(int)lis.size();j++){
			if(st[lis[j]].count(lis[i])==0){
				del(x);
				vis[x]=1;
				return 0;
			}
		}
	}
	puts("2");
	for(int i=0;i<(int)lis.size();i++){
		printf("%d ",lis[i]);
	}
	puts("");
	return 1;
}
int main(){
	int T;
	read(T);
	while(T--){
		read(n),read(m),read(k);
		init();
		for(int i=1;i<=m;i++){
			int u,v;
			read(u),read(v);
			add_edge(u,v);
			add_edge(v,u);
			st[u].insert(v);
			st[v].insert(u);
			deg[u]++;
			deg[v]++;
		}
		if(work_bfs()){
			continue;
		}
		calc_bfs();
		if(1ll*k*(k-1)/2>m){
			puts("-1");
			continue;
		}
		bool flag=0;
		while(!q.empty()){
			q.pop();
		}
		for(int i=1;i<=n;i++){
			if((!vis[i])&&tmp_deg[i]==k-1){
				q.push(i);
			}
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(check(u)){
				flag=1;
				break;
			}
		}
		if(!flag){
			puts("-1");
		}
	}
	return 0;
}
/*
1
16 26 4
1 2
2 3
3 4
1 4
1 3
2 4
1 5
5 6
5 7
2 8
8 9
8 16
3 11
11 12
11 13
4 10
10 14
10 15
9 16
14 15
12 13
6 7
16 14
15 6
7 13
9 12
6 5 2
1 2
2 3
3 4
1 4
5 6
5 7 3
1 2
1 3
2 3
1 4
3 4
3 5
4 5
*/