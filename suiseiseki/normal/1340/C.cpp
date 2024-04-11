#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=10000;
const int Maxm=1000;
const int Inf=0x7f7f7f7f;
int n,m;
int r,g;
int d[Maxn+5];
/*int find_edge(int x,int y,int t){
	if(abs(d[x]-d[y])+t>g){
		return -1;
	}
	if(abs(d[x]-d[y])+t==g){
		return abs(d[x]-d[y])+r;
	}
	return abs(d[x]-d[y]);
}
int head[Maxn*Maxm+5],arrive[Maxn*Maxm*2+5],val[Maxn*Maxm*2+5],nxt[Maxn*Maxm*2+5],tot;
void add_edge(int from,int to,int v){
	arrive[++tot]=to;
	val[tot]=v;
	nxt[tot]=head[from];
	head[from]=tot;
}
*/
int dis[Maxn+5][Maxm+5];
int ans=Inf;
bool vis[Maxn+5][Maxm+5];
/*
bool in[Maxn+5][Maxm+5];
queue<pair<int,int> > q;
void spfa(){
	dis[1][0]=0;
	in[1][0]=1;
	q.push(make_pair(1,0));
	while(!q.empty()){
		pair<int,int> u=q.front();
		in[u.first][u.second]=0;
		q.pop();
		int val;
		if(u.first>1&&(val=find_edge(u.first,u.first-1,u.second))!=-1){
			int to=(u.second+d[u.first]-d[u.first-1])%g;
			if(dis[u.first-1][to]>dis[u.first][u.second]+val){
				dis[u.first-1][to]=dis[u.first][u.second]+val;
				if(dis[u.first-1][to]<ans&&!in[u.first-1][to]){
					in[u.first-1][to]=1;
					q.push(make_pair(u.first-1,to));
				}
			}
		}
		if(u.first<m&&(val=find_edge(u.first,u.first+1,u.second))!=-1){
			int to=(u.second+d[u.first+1]-d[u.first])%g;
			if(dis[u.first+1][to]>dis[u.first][u.second]+val){
				dis[u.first+1][to]=dis[u.first][u.second]+val;
				if(u.first+1==m){
					if(to==0){
						ans=min(ans,dis[u.first+1][to]-r);
					}
					else{
						ans=min(ans,dis[u.first+1][to]);
					}
				}
				if(dis[u.first+1][to]<ans&&!in[u.first+1][to]){
					in[u.first+1][to]=1;
					q.push(make_pair(u.first+1,to));
				}
			}
		}
	}
}
*/
deque<pair<int,int> > q;
void bfs(){
	dis[1][0]=0;
	vis[1][0]=1;
	q.push_back(make_pair(1,0));
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop_front();
		if((n-d[u.first])+u.second<=g){
			ans=min(ans,(r+g)*dis[u.first][u.second]+(n-d[u.first])+u.second);
		}
		if(u.first>1&&u.second+d[u.first]-d[u.first-1]<=g&&(!vis[u.first-1][(u.second+d[u.first]-d[u.first-1])%g])){
			if(u.second+d[u.first]-d[u.first-1]==g){
				vis[u.first-1][0]=1;
				dis[u.first-1][0]=dis[u.first][u.second]+1;
				q.push_back(make_pair(u.first-1,0));
			}
			else{
				vis[u.first-1][u.second+d[u.first]-d[u.first-1]]=1;
				dis[u.first-1][u.second+d[u.first]-d[u.first-1]]=dis[u.first][u.second];
				q.push_front(make_pair(u.first-1,u.second+d[u.first]-d[u.first-1]));
			}
		}
		if(u.first<m&&u.second+d[u.first+1]-d[u.first]<=g&&(!vis[u.first+1][(u.second+d[u.first+1]-d[u.first])%g])){
			if(u.second+d[u.first+1]-d[u.first]==g){
				vis[u.first+1][0]=1;
				dis[u.first+1][0]=dis[u.first][u.second]+1;
				q.push_back(make_pair(u.first+1,0));
			}
			else{
				vis[u.first+1][u.second+d[u.first+1]-d[u.first]]=1;
				dis[u.first+1][u.second+d[u.first+1]-d[u.first]]=dis[u.first][u.second];
				q.push_front(make_pair(u.first+1,u.second+d[u.first+1]-d[u.first]));
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&d[i]);
	}
	sort(d+1,d+1+m);
	scanf("%d%d",&g,&r);
	/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<r;j++){
			if(i>1&&j+d[i]-d[i-1]<=g){
				if(j+d[i]-d[i-1]==g){
					add_edge(id[i][j],id[i-1][0],d[i]-d[i-1]+r);
				}
				else{
					add_edge(id[i][j],id[i-1][j+d[i]-d[i-1]],d[i]-d[i-1]);
				}
			}
			if(i<n&&j+d[i+1]-d[i]<=g){
				if(j+d[i+1]-d[i]==g){
					add_edge(id[i][j],id[i+1][0],d[i+1]-d[i]+r);
				}
				else{
					add_edge(id[i][j],id[i+1][j+d[i+1]-d[i]],d[i+1]-d[i]);
				}
			}
		}
	}
	*/
	memset(dis,0x7f,sizeof dis);
	bfs();
	if(ans==Inf){
		puts("-1");
	}
	else{
		printf("%d\n",ans);
	}
	return 0;
}