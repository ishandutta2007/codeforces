#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
using namespace std;

struct node{
	int x,t;
}p[1000005];
int n,m,k,a[1000005],du[1000005],res[1000005],next[1000005];
vi g[1000005],num[1000005],s[1000005],use[1000005];
int si[1000005];
queue<int> q;

inline void add(int x,int y){
//	printf("%d %d\n",x,y);
	s[x].pb(y);du[y]++;
}
inline bool cmp(node a,node b){
	return a.x<b.x;
}
inline int find(int x){
	if(next[x]!=x) next[x]=find(next[x]);
	return next[x];
}
inline void uni(int x,int y){
	next[find(y)]=find(x);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		g[i].pb(0);num[i].pb(0);
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			g[i].pb(x);
			add(0,++k);
			num[i].pb(k);
		}
	}
	for(int i=1;i<=k;i++) next[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			p[j].x=g[i][j],p[j].t=j;
		sort(p+1,p+m+1,cmp);
		int last=0;
		for(int j=1;j<m;j++){
			if(p[j].x<p[j+1].x) last=p[j].t; else uni(num[i][p[j].t],num[i][p[j+1].t]);
			if(last) add(num[i][last],num[i][p[j+1].t]);
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++)
			p[i].x=g[i][j],p[i].t=i;
		sort(p+1,p+n+1,cmp);
		int last=0;
		for(int i=1;i<n;i++){
			if(p[i].x<p[i+1].x) last=p[i].t; else uni(num[p[i].t][j],num[p[i+1].t][j]);
			if(last) add(num[last][j],num[p[i+1].t][j]);
		}
	}
	for(int i=1;i<=k;i++){
		a[i]=find(i);//printf("%d ",a[i]);
		si[a[i]]++;use[a[i]].pb(i);
	}
	q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<s[x].size();i++){
			int y=s[x][i],k=a[y];
			du[y]--;
			if(!du[y]){
				si[k]--;
				if(!si[k]){
					for(int j=0;j<use[k].size();j++)
						q.push(use[k][j]),res[use[k][j]]=res[x]+1;
				}
			}
		}
	}
	k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d ",res[++k]);
		puts("");
	}
	return 0;
}
/*
3 2
2 10
10 3
5 2

1 3
3 2
2 1
*/