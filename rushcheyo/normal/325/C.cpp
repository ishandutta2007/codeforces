#include<bits/stdc++.h>
using namespace std;
const int N=100005,INF=1000000000,lim=314000000;
int n,m,src[N],in[N],val[N],mi[N],ma[N],q[N],d[N],t;
struct node{int x,d;};bool operator<(const node&a,const node&b){return a.d>b.d;}
priority_queue<node>pq;
vector<int>g[N],rg[N],pd[N],e[N];
void upd(int &x,int y){if(y>lim)y=lim;x=y;}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0,l;i<m;i++){
		scanf("%d%d",src+i,&l);
		for(int j=0,k;j<l;j++){
			scanf("%d",&k);
			if(k==-1)val[i]++;
			else g[i].push_back(k),rg[k].push_back(i);
		}
		d[i]=g[i].size();
	}
	for(int i=1;i<=n;i++)mi[i]=INF;
	for(int i=0;i<m;i++)if(g[i].empty())pq.push((node){src[i],val[i]});
	while(!pq.empty()){
		node t=pq.top();pq.pop();
		if(mi[t.x]!=INF)continue;
		mi[t.x]=t.d;
		for(auto v:rg[t.x])
			if(!--d[v]){
				int x=val[v];
				for(auto u:g[v])upd(x,x+mi[u]);
				pq.push((node){src[v],x});
			}
	}
	for(int i=0;i<m;i++)
		if(!count_if(g[i].begin(),g[i].end(),[](int x){return mi[x]==INF;})){
			pd[src[i]].push_back(i);
			for(auto v:g[i])e[v].push_back(src[i]),in[src[i]]++;
		}
	for(int i=1;i<=n;i++)if(!in[i])q[t++]=i;
	for(int i=0;i<t;i++)
		for(auto v:e[q[i]])if(!--in[v])q[t++]=v;
	for(int i=1;i<=n;i++)ma[i]=-INF;
	for(int i=0;i<t;i++)
		for(auto v:pd[q[i]]){
			int x=val[v];
			for(auto u:g[v])upd(x,x+ma[u]);
			ma[q[i]]=max(ma[q[i]],x);
		}
	for(int i=1;i<=n;i++)if(mi[i]==INF)puts("-1 -1");
	else if(ma[i]<0)printf("%d -2\n",mi[i]);
	else printf("%d %d\n",mi[i],ma[i]);
}