/*
author:jxy
lang:C/C++
university:China,Xidian University
**If you need to reprint,please indicate the source**
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define INF 1E9
using namespace std;
#define maxn 100005
struct node {
	int u;
	node *next;
};
int n,m;
node* First[maxn*2];
inline void add(int v,int u) {
	// cout<<v<<" "<<u<<endl;
	node *s=new node;
	s->next=First[v];
	s->u=u;
	First[v]=s;
}
int a[maxn],b[maxn];
int cnt;
bool cmp(int c,int d) {
	return a[c]<a[d];
}
void init() {
	scanf("%d%d",&n,&m);
	memset(First,0,sizeof(First));
	int i,j,k;
	cnt=0;
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d",&a[j]);
			b[j]=j;
		}
		sort(b,b+m,cmp);
		for(k=0; k<m; k++) {
			if(a[b[k]]==-1)continue;
			if(!k||a[b[k]]!=a[b[k-1]])cnt++;//
			add(b[k],m+cnt+1);
			add(m+cnt,b[k]);
		}
		cnt++;
	}
}
int  inq[maxn*2];
int topo[maxn],t;
bool dfs(int u) {
	inq[u]=-1;
	for(node *i=First[u]; i; i=i->next) {
		if(inq[i->u]<0)
			return 0;
		else if(!inq[i->u]&&!dfs(i->u))return 0;
	}
	inq[u]=1;
	if(u<m) topo[--t]=u;
	return 1;
}
bool toposort() {
	t=m;
	memset(inq,0,sizeof(inq));
	for(int u=0; u<m+cnt; u++)
		if(!inq[u]&&!dfs(u))return 0;
	return 1;
}


int main() {
	init();
	if(!toposort())puts("-1");
	else {
		for(int i=0; i<m; i++) {
			if(i)putchar(' ');
			printf("%d",topo[i]+1);
		}
		puts("");
	}
}