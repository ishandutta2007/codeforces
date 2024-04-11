#include<bits/stdc++.h>
using namespace std;
#define MN 200005              
int cnt,to[MN<<2],nxt[MN<<2],head[MN];
int n,m,N,deg[MN],id[MN],del[MN<<2];
void add(int x,int y){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int op;
void dfs(int x){
	for(int &i=head[x];i;i=nxt[i]){
		if(del[i])continue;
		int tmp=i;
		del[tmp]=del[tmp^1]=1;
		dfs(to[tmp]);
		op^=1;
		if(op)printf("%d %d\n",to[tmp],x);
		else printf("%d %d\n",x,to[tmp]);
	}
}
int main(){
	cnt=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		deg[x]++;deg[y]++;
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;++i)
		if(deg[i]&1)id[++N]=i;
	for(int i=1;i<=N;i+=2){
		int x=id[i],y=id[i+1];
		add(x,y);add(y,x);
	}
	int ans=m+N/2;
	if(ans&1)ans++,add(1,1),add(1,1);
	printf("%d\n",ans);
	dfs(1);
	return 0;
}