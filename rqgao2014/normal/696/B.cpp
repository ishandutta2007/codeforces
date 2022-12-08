#include<bits/stdc++.h>
using namespace std;

const int N=100005;
struct node{
	int to,next;
}p[N<<1];
int n,tot,head[N],si[N];
double ans[N];
inline void add(int x,int y){
	p[++tot].to=y;p[tot].next=head[x];head[x]=tot;
}
inline void dfs(int x,int fa){
	si[x]=1;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==fa) continue;
		dfs(y,x);
		si[x]+=si[y];
	}
}
inline void dfs2(int x,int fa){
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==fa) continue;
		ans[y]=ans[x]+(double)(si[x]-si[y]-1)/2.0+1.0;
		dfs2(y,x);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		add(x,i);
	}
	dfs(1,0);
	ans[1]=1.0;dfs2(1,0);
	for(int i=1;i<=n;i++) printf("%.1f ",ans[i]);puts("");
	return 0;
}
/*
12
1 1 2 2 4 4 3 3 1 10 8
*/