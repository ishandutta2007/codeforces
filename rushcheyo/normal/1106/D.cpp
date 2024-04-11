#include<bits/stdc++.h>

using namespace std;

int n,m;
bool inq[100005];
vector<int> g[100005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	priority_queue<int,vector<int>,greater<int>>q;
	q.push(1),inq[1]=true;
	for(int i=1;i<=n;i++){
		int x=q.top();q.pop();
		printf("%d ",x);
		for(int v:g[x])if(!inq[v])q.push(v),inq[v]=true;
	}
}