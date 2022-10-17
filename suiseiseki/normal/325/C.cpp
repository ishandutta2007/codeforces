#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Inf 0x3f3f3f3f
#define Maxn 100000
#define int long long
#define Max_ans 314000000
int m,n;
int mn[Maxn+5],mx[Maxn+5];
bool vis[Maxn+5],inq[Maxn+5];
vector<int> u[Maxn+5],v[Maxn+5];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int minn(int a,int b){
	return a<b?a:b;
}
int maxn(int a,int b){
	return a>b?a:b;
}
struct Data{
	int id,w,r,sum;
	vector<int> v;
}p[Maxn+5];
void dij(){
	memset(mn,0x7f,sizeof mn);
	int t;
	int d,x;
	while(!q.empty()){
		d=minn(Inf,q.top().first);
		x=q.top().second;
		q.pop();
		if(d<mn[x]){
			for(int i=0;i<(int)v[x].size();i++){
				t=v[x][i];
				if(mn[x]>Inf){
					p[t].r--;
					p[t].sum+=d;
				}
				else{
					p[t].sum+=d-mn[x];
				}
				if(!p[t].r){
					q.push(make_pair(p[t].sum,p[t].id));
				}
				p[t].sum=minn(p[t].sum,Inf);
			}
			mn[x]=d;
		}
	}
	for(int i=1;i<=n;i++){
		if(mn[i]>Inf){
			mn[i]=mx[i]=-1;
		}
	}
}
void dfs(int x){
	if(vis[x]||inq[x]){
		return;
	}
	vis[x]=inq[x]=1;
	int v,t,sum;
	for(int i=0;i<(int)u[x].size();i++){
		t=u[x][i];
		sum=p[t].w;
		for(int j=0;j<(int)p[t].v.size();j++){
			if(mx[p[t].v[j]]==-1){
				sum=-1;
				break;
			}
		}
		if(sum==-1){
			continue;
		}
		for(int j=0;j<(int)p[t].v.size();j++){
			v=p[t].v[j];
			dfs(v);
			if(inq[v]||mx[v]==Inf){
				sum=Inf;
				break;
			}
			sum+=mx[v];
		}
		mx[x]=maxn(mx[x],sum);
	}
	inq[x]=0;
}
signed main(){
	cin>>m>>n;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>p[i].id;
		u[p[i].id].push_back(i);
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y;
			if(y==-1){
				p[i].w++;
			}
			else{
				p[i].r++;
				p[i].v.push_back(y);
				v[y].push_back(i);
			}
		}
		if(p[i].w==x){
			q.push(make_pair(p[i].w,p[i].id));
		}
		p[i].sum=p[i].w;
	}
	dij();
	for(int i=1;i<=n;i++){
		if(mx[i]!=-1&&!vis[i]){
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(mx[i]==Inf){
			mx[i]=-2;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<minn(mn[i],Max_ans)<<" "<<minn(mx[i],Max_ans)<<endl;
	}
	return 0;
}